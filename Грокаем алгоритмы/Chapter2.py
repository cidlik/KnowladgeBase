import random
from array import array


ARRAY_LEN = 10


def selection_sort(a: list or array, inc_order: bool = True) -> list or array:
    if isinstance(a, list):
        ret = list()
    elif isinstance(a, array):
        ret = array("i", [])
    else:
        print(f"type {type(a)} is unsupported")
        return -1

    if inc_order:
        exp = lambda x, y: x < y
    else:
        exp = lambda x, y: x > y

    while len(a):
        tmp = a[0]
        pos = 0
        for i, el in enumerate(a):
            if exp(el, tmp):
                tmp = el
                pos = i
        ret.append(tmp)
        a.pop(pos)

    return ret


if __name__ == "__main__":
    a = array("i", [random.randint(1, 1000) for i in range(ARRAY_LEN)])
    print(a)
    sort_a = selection_sort(a, inc_order=False)
    print(sort_a)
