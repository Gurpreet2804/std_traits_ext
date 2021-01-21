## Introduction

This library provides additional functionalities that are not part of **Standard Template Library**

It is build upon C++ existing functionalities.

## Code Examples

```cpp
    struct A { };
    struct B { };
    static_assert(are_const<const A, const B>::value, "all const");
    static_assert(are_const_v<const A, B>, "all are not const");
```

## API's

This library provides following API's.
This library is a work in progress, new functionalities will be added with time.

Ref: [Reference](https://en.cppreference.com/w/cpp/types)

#### Type Traits

* `are_const`

## Compile & Run

Execute following commands

```
mkdir build
cd build
cmake ..
make
make test
```
Note: *Use deps.sh for google test setup.*

## Author
Gurpreet Singh [gurpreet2804](https://github.com/Gurpreet2804)
