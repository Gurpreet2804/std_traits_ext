#pragma once

#include <utilities.hpp>

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

} // namespace traits
