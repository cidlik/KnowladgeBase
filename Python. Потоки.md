#python #thread

### Ресурсы

1. docs:  https://docs.python.org/3/library/threading.html
2. Статья на русском №1: https://webdevblog.ru/vvedenie-v-potoki-v-python/

### Связи
[[Python. watchdog]]


### Пример
```
import time
import threading


def sec_counter():
    sec = 0
    while True:
        print(f"Seconds from start programm: {sec} sec")
        time.sleep(1)
        sec = sec + 1


def main():
    shadow_func = threading.Thread(target=sec_counter, daemon=True)
    shadow_func.start()
    while True:
        str_in = input("Print something good: ")
        print(f"You enter: {str_in}")


if __name__ == "__main__":
    main()
```

### Заметки

1. Чтобы **указать одному потоку дождаться завершения другого потока**, вам нужно вызывать **.join()**.
2. Убить поток вручную не получилось. Если при создании потока не указать демона, то не получается выйти из петли в `sec_counter()`.