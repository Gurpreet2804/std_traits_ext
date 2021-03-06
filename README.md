## Introduction

This library provides additional functionalities that are not part of **Standard Template Library**

It is build upon C++ existing functionalities.

## Code Examples

Examples for below mentioned functionalities are:

* **are_const**

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

##### Type Properties

* `are_const`
* `are_volatile`
* `are_trivial`

##### Type Relationship

* `is_same_of_any`
* `is_same_of_all`
* `is_base_of_any`
* `is_base_of_all`
* `are_all_base_of`
* `is_convertible_to_any`

## Compile & Run

Execute following commands

```
mkdir build
cd build
cmake ..
make
make test
```
Note: *Use **deps.sh** for google test setup.*

## Author
Gurpreet Singh [gurpreet2804](https://github.com/Gurpreet2804)
