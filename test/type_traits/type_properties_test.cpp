#include "gtest/gtest.h"

#include "type_properties.hpp"
#include "types.h"

using namespace traits;

#define TEST_LABEL TYPE_PROPERTIES

TEST(TEST_LABEL, are_const)
{
    ASSERT_TRUE((are_const<const A, const B>::value));
    ASSERT_FALSE((are_const<const A, B>::value));
    ASSERT_TRUE((are_const<A *const>::value));
    ASSERT_FALSE((are_const<const A *>::value));
    ASSERT_TRUE((are_const<>::value));
    ASSERT_EQ((are_const<A *const>::value), (are_const_v<A *const>));
    ASSERT_TRUE((are_const_v<const A>));
    ASSERT_FALSE((are_const_v<A *const, const B *, const D>));
    ASSERT_TRUE((are_const_v<A *const, const B *const, const D>));
}

TEST(TEST_LABEL, are_volatile)
{
    ASSERT_EQ((are_volatile<int>::value), (are_volatile_v<int>));
    ASSERT_TRUE((are_volatile_v<volatile char>));
    ASSERT_FALSE((are_volatile_v<volatile double, int, volatile float>));
    ASSERT_TRUE((are_volatile_v<volatile double,
                                volatile int, volatile float>));
}

TEST(TEST_LABEL, are_trivial)
{
    ASSERT_EQ((are_trivial<A>::value), (are_trivial_v<A>));
    ASSERT_TRUE((are_trivial_v<A>));
    ASSERT_TRUE((are_trivial_v<int, char, float>));
    ASSERT_TRUE((are_trivial_v<POD, int, char>));
    ASSERT_FALSE((are_trivial_v<A, B, V, D>));
    ASSERT_TRUE((are_trivial_v<A, int, B[], char[], D>));
}
