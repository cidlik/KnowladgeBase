#python #collections

### Ресурсы
1. https://python-scripts.com/queues

### Заметки
* `collections.deque` - двухконечная очередь, которая поддерживает добавление/удаление элементов с обоих концов.
```src
dq = deque()
print(f"1: {dq}")
dq.append(1)
dq.append(2)
dq.append(3)
print(f"2: {dq}")
dq.popleft()
print(f"3: {dq}")
```
```stdout
$ python Chapter6.py
1: deque([])
2: deque([1, 2, 3])
3: deque([2, 3])
```

Преимущество такой структуры перед обычными списками - скорость!
```src
from collections import deque

LEN = 100000
print("test. Pop left element until the structure is empty")

dq = deque([i for i in range(LEN)])
start_time = time.time()
while len(dq):
	dq.popleft()
print(f"time: collections.deque: {time.time() - start_time} sec")

l = [i for i in range(LEN)]
start_time = time.time()
while len(l):
	l.pop(0)
print(f"time: list: {time.time() - start_time} sec")
```
```stdout
$ python Chapter6.py
test. Pop left element until the structure is empty
time: collections.deque: 0.009992361068725586 sec
time: list: 1.586679220199585 sec
```
