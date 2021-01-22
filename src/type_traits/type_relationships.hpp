#pragma once

#include <utilities/utilities.hpp>

namespace traits
{

    template <typename... Args>
    using is_first_same_of_any = utilities::or_op<std::is_same, Args...>;

    template <typename... Args>
    constexpr bool is_first_same_of_any_v = is_first_same_of_any<Args...>::value;

} // namespace traits
