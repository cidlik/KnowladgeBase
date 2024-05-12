#yaml #anchors #alias

### Ресурсы
1. Статья: https://levelup.gitconnected.com/6-yaml-features-most-programmers-dont-know-164762343af3


### Заметки
1. Теги обозначаются `!!` - "дескриптор двойного тега"
2. Можно выполнять простые преобразования
_Пример_
```
  vars:
    var1: !!float 42
    var2: !!str 42

  tasks:
    - name: Print my_vars1
      debug:
        msg: "var1: {{ var1 * 2 }}; var2: {{ var2 * 2 }}"
```
_Результат_
```
TASK [Print vars] **************************************************************
ok: [rkuznecov@impact-pc] => {
    "msg": "var1: 84.0; var2: 4242"
}
```
