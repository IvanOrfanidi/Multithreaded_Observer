## Multithreaded Observer

Пример реализации паттерна "Наблюдатель" под многопоточную систему.
Используется вместе со сборкой googletest из внешнего git репозитория.

### Установка Google Test в папку с проектом
```sh
git submodule add https://github.com/google/googletest.git
```

### Сборка с использованием CMake
Для сборки выполнить скрипт `compile.sh` :

```sh
./compile
```
Сборка будет установлена в папку `build`.