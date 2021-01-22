#pragma once

#include <utilities/utilities.hpp>

namespace traits
{
    template <typename... Args>
    using are_const = utilities::and_op<std::is_const, Args...>;

    template <typename... Args>
    constexpr bool are_const_v = are_const<Args...>::value;

    template <typename... Args>
    using are_volatile = utilities::and_op<std::is_volatile, Args...>;

    template <typename... Args>
    constexpr bool are_volatile_v = are_volatile<Args...>::value;

    template <typename... Args>
    using are_trivial = utilities::and_op<std::is_trivial, Args...>;

    template <typename... Args>
    constexpr bool are_trivial_v = are_trivial<Args...>::value;

} // namespace traits
