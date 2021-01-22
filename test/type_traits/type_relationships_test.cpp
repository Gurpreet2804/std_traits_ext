#include "gtest/gtest.h"

#include "type_relationships.hpp"
#include "types.h"

using namespace traits;

#define TEST_LABEL TYPE_RELATIONSHIPS

TEST(TEST_LABEL, is_first_same_of_any)
{
    ASSERT_TRUE((is_first_same_of_any<int, int, float>::value));
    ASSERT_TRUE((is_first_same_of_any<int, float, int>::value));
    ASSERT_FALSE((is_first_same_of_any<int, float, char, float>::value));
    ASSERT_TRUE((is_first_same_of_any<int, char, int, float, int>::value));
    ASSERT_TRUE((is_first_same_of_any<int, int>::value));
    ASSERT_FALSE((is_first_same_of_any<int, float>::value));
    ASSERT_FALSE((is_first_same_of_any<int>::value));
    ASSERT_FALSE((is_first_same_of_any_v<int, float, char>));

    ASSERT_EQ((is_first_same_of_any<B, B>::value), (is_first_same_of_any_v<B, B>));
    ASSERT_FALSE(is_first_same_of_any_v<B>);
    ASSERT_TRUE((is_first_same_of_any<B, D, B, A>::value));
    ASSERT_FALSE((is_first_same_of_any_v<B, A, D>));
}
