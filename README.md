## Multithreaded Observer

Пример реализации паттерна "Наблюдатель" под многопоточную систему.
Используется вместе со сборкой googletest из внешнего git репозитория.

### Установка Google Test в папку с проектом
```sh
git submodule add https://github.com/google/googletest.git
```

### Сборка с использованием CMake
```sh
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DTEST=true ..
cmake --build .
```