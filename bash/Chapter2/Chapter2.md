#bash #loop

# Ресурсы

1. Статья: https://habr.com/ru/companies/ruvds/articles/325928/
2. ABS Guide: https://tldp.org/LDP/abs/html

# Заметки

## Цикл for

Файл: ``for.sh``

Базовая конструкция:

```
for var in list
do
    команды
done
```

Также является возможным написание цикла for в стиле ЯП C:
```
for (( начальное значение переменной ; условие окончания цикла; изменение переменной ))
```

### Про разделитель полей

По умолчанию, bash считает разделителями полей символы:

* пробел;
* табуляция;
* символ перевода строки.

Изменить это значение можно, если переопределить переменную IFS - Internal
Field Separator. Для демонстрации используется блок "Experiment with IFS".
Из коробки, в ``for.sh`` устанавливается значение ``IFS=$'\n'``. Если
закомментировать строку:
```
IFS=$'\n'  # comment me
```
то цикл проитерирует все элементы по дефолтным разделителям.

## Цикл while

Файл: ``while.sh``

Базовая конструкция:
```
while команда проверки условия
do
    другие команды
done
```
Можно перевести как "выполняй, пока условие верно".

## Цикл until

Файл: ``until.sh``

Базовая конструкция:
```
until команда проверки условия
do
    другие команды
done
```
Можно перевести как "выполняй до тех пор, пока условие не станет верным".

## Управление циклами

Для управления циклами можно использовать команды:

* ``break``;
* ``continue``.