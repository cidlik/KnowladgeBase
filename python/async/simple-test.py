#!/usr/bin/env python3

import asyncio
import time


async def fun1(x):
    print(x**2)
    await asyncio.sleep(3)
    print('fun1 завершена')


async def fun2(x):
    print(x**0.5)
    await asyncio.sleep(3)
    print('fun2 завершена')


async def main():
    task1 = asyncio.create_task(fun1(4))
    task2 = asyncio.create_task(fun2(4))

    await task1
    await task2


start_time = time.time()

asyncio.run(main())

finish_time = time.time()
print(f"{start_time=}; {finish_time=}; diff={finish_time - start_time}")
