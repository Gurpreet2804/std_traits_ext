#include "gtest/gtest.h"

#include "type_relationships.hpp"
#include "types.h"

namespace
{

#define TEST_LABEL TYPE_RELATIONSHIPS

    using namespace traits;

    TEST(TEST_LABEL, is_same_of_any)
    {
        ASSERT_TRUE((is_same_of_any<int, int, float>::value));
        ASSERT_TRUE((is_same_of_any<int, float, int>::value));
        ASSERT_FALSE((is_same_of_any<int, float, char, float>::value));
        ASSERT_TRUE((is_same_of_any<int, char, int, float, int>::value));
        ASSERT_TRUE((is_same_of_any<int, int>::value));
        ASSERT_FALSE((is_same_of_any<int, float>::value));
        ASSERT_FALSE((is_same_of_any<int>::value));
        ASSERT_FALSE((is_same_of_any_v<int, float, char>));

        ASSERT_EQ((is_same_of_any<B, B>::value), (is_same_of_any_v<B, B>));
        ASSERT_FALSE(is_same_of_any_v<B>);
        ASSERT_TRUE((is_same_of_any<B, D, B, A>::value));
        ASSERT_FALSE((is_same_of_any_v<B, A, D>));
    }

    TEST(TEST_LABEL, is_same_of_all)
    {
        ASSERT_TRUE((is_same_of_all<int, int, int>::value));
        ASSERT_TRUE((is_same_of_all<int>::value));
        ASSERT_FALSE((is_same_of_all<int, char, float>::value));
        ASSERT_FALSE((is_same_of_all_v<int, const int>));

        ASSERT_EQ((is_same_of_all<B, B>::value), (is_same_of_all_v<B, B>));
        ASSERT_TRUE(is_same_of_all_v<B>);
        ASSERT_TRUE((is_same_of_all_v<B, B, B, B>));
        ASSERT_FALSE((is_same_of_all_v<B, B, A, D>));
    }

    TEST(TEST_LABEL, is_base_of_any)
    {
        ASSERT_EQ((is_base_of_any<B, D>::value), (is_base_of_any_v<B, D>));
        ASSERT_FALSE(is_base_of_any_v<B>);
        ASSERT_TRUE((is_base_of_any_v<B, B, A>));
        ASSERT_TRUE((is_base_of_any_v<B, A, D>));
        ASSERT_FALSE((is_base_of_any_v<B, A>));
    }

    TEST(TEST_LABEL, is_base_of_all)
    {
        ASSERT_EQ((is_base_of_all<B, B>::value), (is_base_of_all_v<B, B>));
        ASSERT_TRUE(is_base_of_all_v<B>);
        ASSERT_FALSE((is_base_of_all_v<B, A, B, D>));
        ASSERT_TRUE((is_base_of_all_v<B, B, D>));
    }

    TEST(TEST_LABEL, are_all_base_of)
    {
        ASSERT_TRUE((are_all_base_of_v<D, B>));
        ASSERT_EQ((are_all_base_of<B, A>::value), (are_all_base_of_v<B, A>));
        ASSERT_TRUE(are_all_base_of_v<B>);
        ASSERT_FALSE((are_all_base_of_v<D, A, B, D>));
        ASSERT_TRUE((are_all_base_of_v<D, D, D, D>));
        ASSERT_TRUE((are_all_base_of_v<D, D, B>));
    }

    TEST(TEST_LABEL, is_convertible_to_any)
    {
        ASSERT_TRUE((is_convertible_to_any_v<int, float>));
        ASSERT_FALSE((is_convertible_to_any_v<int, std::string>));
        ASSERT_TRUE((is_convertible_to_any_v<float, int, std::string>));

        ASSERT_EQ((is_convertible_to_any<B, A>::value), (is_convertible_to_any_v<B, A>));
        ASSERT_TRUE((is_convertible_to_any_v<C, A>));
        ASSERT_FALSE((is_convertible_to_any_v<B>));
        ASSERT_TRUE((is_convertible_to_any_v<D, A, B>));
        ASSERT_FALSE((is_convertible_to_any_v<B, A>));
    }

} // namespace
