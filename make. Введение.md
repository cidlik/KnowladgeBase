#make #introduction

# Ресурсы

1. Статья: https://habr.com/ru/articles/155201/
2. Automatic variables: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
3. Cheat sheet: https://devhints.io/makefile
4. Manual: https://www.gnu.org/software/make/manual/html_node/

Примеры располагаются в `make`. Проект возможно собрать при помощи
команды `gcc -Iinclude/ src/custom-lib.c src/main.c -o test`.


# Заметки

`make` - способ автоматизации сборки проекта. В случае, если проект содержит
более одного файла с исходниками и одного заголовочника, становится некомфортно
собирать его "руками".

По умолчанию, `make` ищет `Makefile` в той директории, откуда вызвали команду.
Возможно уточнить имя при помощи ключа `-f`.

## Самый простой Makefile

Основой Makefile является кострукция вида:
```
цель: зависимости
[tab] команда
```
Пример - `Makefile.test1`.

По умолчанию, выполняется сборка для цели `all`, поэтому вызов данного Makefile
можо выполнить без указания цели.

## Использование нескольких целей и зависимостей

Пример - `Makefile.test2`.

В данном примере каждый файл компилируется отдельно. Для этого используется
ключ `-c` - `Compile and assemble, but do not link`. Затем в зависимости `all`
перечисляются все цели, которые компилировали файлы. Таким образом, перед
выполнением `all` будут выполнены остальные цели.

В целях `custom-lib` и `main` используются автоматические переменные (см. 2).
Подробонее будет в разделе "Магические переменные".

В примере `Makefile.test3` вводится тривиальное использование переменных.

## Изучение присвоения значения переменных

Разбирается `Var assignment` из источника 3.

```
foo := bar
foo ?= xyz

all:
	echo $(foo)  # expected "boo"
```

Если переменная не существует, то `?=` сработает как `=`. Если существует, то
присваивание игнорируется.

```
foo != uname -a

all:
	echo $(foo)  # expected "boo"
```

Присвоить foo вывод выполнения shell команды.

### Разница между := и =

Для сравнения запустить:

```
foo = bar
bar = $(foo) foo
foo := boo

all:
	echo $(foo)  # expected "boo"
	echo $(bar)  # expected "boo foo"
```

и

```
foo = bar
bar := $(foo) foo  #
foo := boo

all:
	echo $(foo)  # expected "boo"
	echo $(bar)  # expected "bar foo"
```

Использование `=` приводит к тому, что выражение для `bar` не раскрывается,
т.е. значение переменной `foo` будет подставлено дальше. Если `foo` изменится,
то изменится и `bar`.

Во втором случае используется _one time assignment_, т.е. из-за `:=` происходит
раскрытие всех составляющих, в `bar` попадают строки `bar` и `foo`.

## Магические переменные

Вырезка из [3].

```
out.o: src.c src.h
  $@   # "out.o" (target)
  $<   # "src.c" (first prerequisite)
  $^   # "src.c src.h" (all prerequisites)

%.o: %.c
  $*   # the 'stem' with which an implicit rule matches ("foo" in "foo.c")
```

Пример - `Makefile.test4`. Была сделана одна цель `%.c` - название соотвествует
шаблону - любой Си-файл. При указании файлов в команде для `gcc` используется
`$*` - название без ресширения - `stem`.

## Поиск файлов

Нашел следующие способы
```
FILES != find -name *.c
FILES := $(shell find -name *.c)
FILES := $(wildcard src/*.c)
```

## Работа со строками

* `$(subst from,to,text)` - замена `from` на `to` в `text`. Пример:

  ```
  STR := $(subst foo,bar,1foo2)  # 1foo2 -> 1bar2
  ```

* `$(patsubst pattern,replacement,text)` - замена `pattern` на `replacement`
  в `text`. Используется, когда `text` разделен пробелами (видимо, для работы
  с файлами). Пример:

  ```
  STR := $(patsubst %.c,%.o,$(wildcard src/*.c))
  ```

  ```
  [rkuznecov@dojo-pc make]$ ls src/
  custom-lib.c  main.c
  [rkuznecov@dojo-pc make]$ make -f Makefile.test5
  src/custom-lib.o src/main.o
  ```
