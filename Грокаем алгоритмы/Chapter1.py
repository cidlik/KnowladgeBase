import random
from array import array

ARRAY_LEN = 10


def binarySearch(a: array or list, t: int) -> int:
    left = 0
    right = len(a) - 1
    while left <= right:
        mid = (right + left) // 2
        # print(f"mid: {mid}; left: {left}; right: {right}; len: {len(a)}")
        # print(a[right])
        # print(a[left:right])
        if a[mid] == t:
            return mid
        if a[mid] < t:
            left = mid + 1
        elif a[mid] > t:
            right = mid - 1
    return None


def run_(func, *args):
    a = args[0]
    t = args[1]
    print(f"\narray: {a}\nsearch: {t}")
    pos = func(a, t)
    if pos is None:
        print(f"element {t} was not found")
    else:
        print(f"element {t} in {pos} position")


def main():
    a = sorted(array("i", [random.randint(1, 10) for i in range(ARRAY_LEN)]))
    a = array("i", [1, 2, 3, 4, 5, 6])
    run_(binarySearch, a, 1)
    run_(binarySearch, a, 10)
    a = array("i", [0, 2, 4, 6, 8, 10, 12, 14, 16])
    run_(binarySearch, a, 9)
    run_(binarySearch, a, 16)


if __name__ == "__main__":
    main()
