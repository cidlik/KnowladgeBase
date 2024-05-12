import traceback


class Stack:
    def __init__(self):
        self.__list = []

    def push(self, foo: any) -> None:
        self.__list.append(foo)

    def pop(self) -> any:
        if not self.__list:
            print("Stack is empty")
            return None
        return self.__list.pop()

    def show(self) -> None:
        print(self.__list)


def factorial(n: int) -> int:
    print(f"1: n: {n}")
    if n == 1:
        return 1
    tmp = n * factorial(n - 1)
    for line in traceback.format_stack():
        print(line.strip())
    print(f"\n2: n: {n}")
    return tmp


def Fibonacci(n: int):
    f0 = 0
    f1 = 1
    l = [f0, f1]

    def _fib(i, l):
        nonlocal n
        if i > n:
            return
        l.append(l[-1] + l[-2])
        _fib(i + 1, l)

    _fib(0, l)
    print(l)


if __name__ == "__main__":
    Fibonacci(10)

    # stack = Stack()
    # stack.show()
    # stack.pop()
    # stack.push(1)
    # stack.push(2)
    # stack.push(4)
    # stack.show()
    # print(stack.pop())
    # stack.show()
