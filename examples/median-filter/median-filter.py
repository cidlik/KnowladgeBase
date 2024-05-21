#!/usr/bin/env python3

import plotly.graph_objects as go


def median_filter(l: list, window_size):
    # https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B4%D0%B8%D0%B0%D0%BD%D0%BD%D1%8B%D0%B9_%D1%84%D0%B8%D0%BB%D1%8C%D1%82%D1%80
    l = l.copy()
    len_l = len(l)
    l.insert(0, l[0])
    l.append(l[len_l])
    l.append(l[len_l])
    result = []
    for i in range(len_l):
        tmp = sorted(l[i: i + window_size])
        half = window_size // 2
        try:
            if len(tmp) % 2 == 0:
                result.append((tmp[half - 1] + tmp[half]) / 2)
            else:
                result.append(tmp[half])
        except IndexError:
            break
    return result


def median_filter_v2(value, l: list, window_size):
    l.pop(0)
    l.append(value)
    sort = sorted(l)
    half = window_size // 2
    if len(sort) % 2 == 0:
        return (sort[half - 1] + sort[half]) / 2
    else:
        return sort[half]


def check_algo():
    l = [2, 80, 6, 3]
    result = median_filter(l, 3)
    print(result)
    result = median_filter(l, 4)
    print(result)
    result = median_filter(l, 2)
    print(result)


def check_algo_v2():
    l = [2, 80, 6, 3]
    history = [0, 0, 0]
    result = []
    for v in l:
        result.append(median_filter_v2(v, history, 3))


def main():
    with open("dark-stock.csv") as f:
        raw_data = f.read()
    data = []
    for line in raw_data.splitlines()[1:]:
        num, gain = line.split(",")
        data.append((int(num), round(float(gain), 3)))
    gains = [line[1] for line in data]
    new_gains = []
    WINDOW = 100
    history = []
    for i, g in enumerate(gains):
        if i < WINDOW:
            history.append(g)
            new_gains.append(g)
        else:
            new_gains.append(median_filter_v2(g, history, WINDOW))

    fig = go.Figure()
    fig.add_trace(
        go.Scatter(
            x=list(range(len(gains))),
            y=gains,
            name="Before filter",
        )
    )
    fig.add_trace(
        go.Scatter(
            x=list(range(len(new_gains))),
            y=new_gains,
            name="After filter",
        )
    )
    with open("result.html", "w") as f:
        f.write(fig.to_html())


if __name__ == "__main__":
    main()
