from __init__ import RanList


def my_sum(l: list) -> int:
    if len(l) == 0:
        return 0
    elif len(l) == 1:
        return l[0]

    sum_ = l.pop(0) + my_sum(l)
    return sum_


def euclidean_algo(m, n):
    """
    В самом простом случае алгоритм Евклида применяется к паре положительных
    целых чисел и формирует новую пару, которая состоит из меньшего числа и
    разницы между большим и меньшим числом. Процесс повторяется, пока числа
    не станут равными.
    src: https://en.wikipedia.org/wiki/Euclidean_algorithm
    """
    ret = 0
    if m == n:
        ret = m
        return ret
    if m > n:
        min_ = n
    else:
        min_ = m
    ret = euclidean_algo(min_, abs(m - n))

    return ret


def num_elements(l: list) -> int:
    if l == []:
        return 0
    l.pop()
    return 1 + num_elements(l)


def find_max(l: list) -> int:
    if len(l) == 1:
        return l[0]
    max_ = l.pop(0)
    tmp = find_max(l)
    if tmp > max_:
        max_ = tmp
    return max_


# src: https://www.geeksforgeeks.org/python-program-for-binary-search/
def binary_search_recursive(l: list, t: int, left: int, right: int) -> int:
    if left <= right:
        mid = (left + right) // 2
        if l[mid] == t:
            return mid
        elif l[mid] > t:
            return binary_search_recursive(l, t, left, mid - 1)
        else:
            return binary_search_recursive(l, t, mid + 1, right)
    else:
        return None


count = 0


def quicksort(l: list):
    global count
    if len(l) < 2:
        return l
    base, _ = l[0], l.pop(0)
    lesser, grater = [], []
    for el in l:
        count += 1
        if el < base:
            lesser.append(el)
        else:
            grater.append(el)
    return quicksort(lesser) + [base] + quicksort(grater)


def main():
    l = RanList()

    print(f"euclidean_algo: {euclidean_algo(1680, 640)}")
    print(f"my_sum: {my_sum([2, 4, 6])}")
    print(f"num_elements: {num_elements([2, 4, 6, 7, 10])}")
    print(f"find_max: {find_max([5, 18, 6, 3, 18, 4, 0])}")
    a = [0, 2, 4, 6, 8, 10, 12, 14, 16]
    tmp = binary_search_recursive(
        a,
        t=3,
        left=0,
        right=len(a) - 1,
    )
    print(f"binary_search_recursive: {tmp}")
    # l.l = sorted([9, 8, 7, 6, 5, 4, 3, 2, 1, 0])
    print(l.l)
    print(f"{quicksort(l.l)}; op_count = {count}")


if __name__ == "__main__":
    main()
