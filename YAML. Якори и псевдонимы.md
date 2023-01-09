#yaml #anchors #alias

### Ресурсы
1. Гайд: https://medium.com/@kinghuang/docker-compose-anchors-aliases-extensions-a1e4105d70bd


### Заметки
1. Якори (anchors) и псевдонимы (alias) используются, чтобы избавиться от копирования кода.
2. Якорь позволяет создать ссылку на элемент, а псевдоним - сослаться на этот элемент.
3. Якори обозначаются `&`; псевдонимы - `*`.
---
_Пример_:
```
- &flag Apple 
- Beachball 
- Cartoon 
- Duckface 
- *flag
```
_Результат_:
```
- Apple 
- Beachball 
- Cartoon 
- Duckface 
- Apple
```
---
_Пример_:
```
---
- project:
    check:
      jobs:
        - mcom03-linux-fast-tests:
            files: &observered_files
              - .*\.py$
              - mcom03_flash_tools/.*
        - mcom03-tl-linux-fast-tests:
            files: *observered_files
        - tox
```
_Результат_:
```
---
- project:
    check:
      jobs:
        - mcom03-linux-fast-tests:
            files:
              - .*\.py$
              - mcom03_flash_tools/.*
        - mcom03-tl-linux-fast-tests:
            files:
              - .*\.py$
              - mcom03_flash_tools/.*
        - tox
```
---

4. `<<` - Ключ слияния
_Пример_
```
  vars: &pattern
    my_vars1:
      - value1
      - value2

  tasks:
    - name: Set fact
      set_fact:
        my_vars2:
          <<: *pattern
          my_vars2: value3
```

_Результат_
```
TASK [Print my_vars1] **********************************************************
ok: [rkuznecov@impact-pc] => {
    "msg": [
        "value1",
        "value2"
    ]
}

TASK [Print my_vars2] **********************************************************
ok: [rkuznecov@impact-pc] => {
    "msg": {
        "my_vars1": [
            "value1",
            "value2"
        ],
        "my_vars2": "value3"
    }
}
```