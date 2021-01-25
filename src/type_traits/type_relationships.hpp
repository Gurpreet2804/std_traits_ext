#pragma once

#include <utilities/utilities.hpp>

namespace traits
{

    template <typename... Args>
    using is_same_of_any = utilities::or_op<std::is_same, Args...>;

    template <typename... Args>
    constexpr bool is_same_of_any_v = is_same_of_any<Args...>::value;

    template <typename... Args>
    using is_same_of_all = utilities::and_op_1<std::is_same, Args...>;

    template <typename... Args>
    constexpr bool is_same_of_all_v = is_same_of_all<Args...>::value;

    template <typename... Args>
    using is_base_of_any = utilities::or_op<std::is_base_of, Args...>;

    template <typename... Args>
    constexpr bool is_base_of_any_v = is_base_of_any<Args...>::value;

    template <typename... Args>
    using is_base_of_all = utilities::and_op_1<std::is_base_of, Args...>;

    template <typename... Args>
    constexpr bool is_base_of_all_v = is_base_of_all<Args...>::value;

    template <typename... Args>
    using are_all_base_of = utilities::and_op_2<std::is_base_of, Args...>;

    template <typename... Args>
    constexpr bool are_all_base_of_v = are_all_base_of<Args...>::value;

    template <typename... Args>
    using is_convertible_to_any = utilities::or_op<std::is_convertible, Args...>;

    template <typename... Args>
    constexpr bool is_convertible_to_any_v = is_convertible_to_any<Args...>::value;

} // namespace traits
