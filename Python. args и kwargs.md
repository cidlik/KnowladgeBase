#python #built-in

### Ресурсы
1. Статья: https://habr.com/ru/company/ruvds/blog/482464/

### Заметки

- `*args` - позиционные аргументы (arguments); `**kwargs` - именованные (keyword arguments)
- В Python `*` - оператор, позволяющий *распаковывать* объекты, внутри которых хранятся некоторые элементы.
	Ex:
	```
	a = [1,2,3]
	b = [*a,4,5,6] 
	print(b) # [1,2,3,4,5,6]
	```
- Использование слов `args` или `kwargs` необязательно, ключевые элементы - звездочки
- Одна звездочка создает список, две - словарь.
	Ex:
	```
	def task1(*args, **kwargs):
	    print(args)
	    print(kwargs)
	
	task1(1, 2, 3, key="value")

	stdout:
	(1, 2, 3)
	{'key': 'value'}
	```
