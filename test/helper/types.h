#pragma once

struct A
{
};

struct B
{
    void foo() {}
};

struct D : B
{
};

struct V
{
    ~V(){};
};

struct POD
{
    char c;
    int i;
    float f;
};
