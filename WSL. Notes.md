#wsl #misc

# Заметки

* Стянуть дистрибутив для WSL без Microsoft Store: https://stackoverflow.com/questions/52512026/is-it-possible-install-ubuntu-in-windows-10-wsl-without-microsoft-store/64872285#64872285

* Проблемы с установкой локальных пакетов Permission denied

```
pip install build
python -m build
pip install dist/*.whl
```

[1] https://github.com/pypa/packaging-problems/issues/258
