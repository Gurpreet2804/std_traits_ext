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

        template <template <typename, typename> class, typename...>
        struct or_op;

        template <template <typename, typename> class F, typename H, typename H1, typename... T>
        struct or_op<F, H, H1, T...> : std::conditional_t<F<H, H1>::value, std::true_type, or_op<F, H, T...>>
        {
        };

        template <template <typename, typename> class F, typename H>
        struct or_op<F, H> : std::false_type
        {
        };

    } // namespace utilities
} // namespace traits
