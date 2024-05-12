#python #set #collections

### Ресурсы
1. Статья: https://forproger.ru/tutorial-article/mnozhestva-set-v-python

### Заметки
- **Множество** - коллекция неупорядоченных элементов.
- Множества могут быть изменяемыми `set` и неизменяемыми `frozenset`.
- Элементы в множестве уникальны.
- Т.к. множества неупорядоченны, то нельзя обратитья к элементу множества напрямую, НО! можно составить список из множества.
	*Ex*
	```
	>>> a = set("abcaba")
	>>> type(a)
	<class 'set'>
	>>> a[1]
	Traceback (most recent call last):
	File "<stdin>", line 1, in <module>
	TypeError: 'set' object is not subscriptable
	>>> print(a)
	{'c', 'a', 'b'}
	>>> list(a)
	['c', 'a', 'b']
	>>> list(a)[0]
	'c'
	```
