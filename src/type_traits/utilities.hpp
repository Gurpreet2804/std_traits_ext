#pragma once

#include <type_traits>

namespace traits
{
    namespace utilities
    {

        template <template <typename...> class, typename...>
        struct and_op;

        template <template <typename> class F, typename H, typename... T>
        struct and_op<F, H, T...> : std::conditional_t<F<H>::value, and_op<F, T...>, std::false_type>
        {
        };

        template <template <typename> class F>
        struct and_op<F> : std::true_type
        {
        };

    } // namespace utilities
} // namespace traits
