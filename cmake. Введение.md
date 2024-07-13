#cmake #introduction

# Ресурсы

1. Статья: https://habr.com/ru/articles/155467/

Примеры будут располагаться в `cmake`.

# Заметки

## Про cmake

**Cmake** - кроссплатформенная утилита для сборки проектов из исходного кода.
Сама утилита сборкой не занимается, а выполняет роль некоторого front-end'a.
Back-end'ом может выступать, например, make.

Чуть иначе, *cmake* - утилита для генерации проектов при сборке.

Правила генерации размещаются в файлах `CMakeLists.txt`.

## Hello world

См. пример `prj1`.

Сборка (относительно `.../cmake/prj1`):
```
cmake -S . -B build/
make -C build/
```

[`add_executable()`](https://cmake.org/cmake/help/latest/command/add_executable.html)
позволяет указать, какой исполняемый файл получить, из каких исходников его
собирать.

Без указания:
```
cmake_minimum_required(VERSION 3.20)
project(prj1)
```
собирается, но Cmake это не очень нравится. Если минимальная требуемая версия
больше той, что установлена, то `cmake ...` свалится. [`project`](https://cmake.org/cmake/help/latest/command/project.html) испольщуется для указания сводной информации о
проекте: версия, описание, URL, ЯП.

## Библиотеки

См. пример `prj2`.

Сборка (относительно `.../cmake/prj2`):
```
cmake -S . -B build/
make -C build/
make -C build/ install
```

[`set()`](https://cmake.org/cmake/help/latest/command/set.html) используется
для создания обычных переменных, кэшируемых или переменных окружения. Обращение
к переменным выполняется при помощи `${<SOME_VAR>}`.

[`add_library()`](https://cmake.org/cmake/help/latest/command/add_library.html)
- конструкция, позволяющая собрать подключаемый файл. По умолчанию, собирается
как static library.

[`target_include_directories()`](https://cmake.org/cmake/help/latest/command/target_include_directories.html) позволяет указать директорию с заголовочными
файлами, необходимыми при компиляции.

[`target_link_libraries()`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) позволяет связать `<target>` - основная программа - с `<item>` -
подключаемые файлы.

При написании `CMakeLists.txt` возник воспрос, почему потребовалось подключать
заголовочные файлы через `target_include_directories()` только к `custom-lib`.
Цель `test` (файл `main.c`) тоже ведь использует этот заголовочник. Однако и
так все работает. Оказалось, что все дело в ключевом слове `PUBLIC` в строке:
```
target_include_directories(custom-lib PUBLIC include)
```
Если заменить на `PRIVATE`, то сборка сломается. Можно починить, если отдельно
указать:
```
target_include_directories(test PRIVATE/PUBLIC include)
```

## Подпроекты

См. пример `prj3`.

Сборка (относительно `.../cmake/prj3`):
```
cmake -S . -B build/
make -C build/
make -C build/ install
```

`subprj1` и `subprj2` - как пример "Hello world". В головной CMakeLists.txt
добавлены [`add_subdirectory()`](https://cmake.org/cmake/help/latest/command/add_subdirectory.html) для указания вложенных проектов.

В этом примере также можно посмотреть:

* работу с ветвлениями;
* работу со строками (использование strip для отбрасывание символа конца строки
  из вывода `pwd`);
* вывод сообщений через `message()`.
