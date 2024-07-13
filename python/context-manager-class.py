#!/usr/bin/env python3

class Wrapper:
    def __init__(self, foo):
        self.foo = foo

    def __enter__(self):
        print("You are in __enter__()")
        print(f"self.foo = {self.foo}")
        return "Response from __enter__()"

    def __exit__(self, exc_type, exc_value, exc_traceback):
        print("You are in __exit__()")
        print(exc_type)
        print(exc_value)
        print(exc_traceback)


print("Before wrapper")

with Wrapper("enter arg") as wr:
    print("Inside a wrapper")
    print(wr)

print("After wrapper")


with Wrapper("enter arg") as wr:
    raise Exception("Some exception")