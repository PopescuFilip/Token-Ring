#include <random>
#include <type_traits>

namespace tokenRingNetwork
{
    template <typename T>
    concept Arithmetic = std::integral<T> || std::floating_point<T>;

    template <Arithmetic T>
    T GetRandom(T lowerLimit, T upperLimit);

    template <Arithmetic T>
    T GetRandom(T lowerLimit, T upperLimit)
    {
        static thread_local std::random_device rd;
        static thread_local std::mt19937 gen(rd());

        if constexpr (std::is_integral<T>())
        {
            std::uniform_int_distribution<T> dis(lowerLimit, upperLimit);
            return dis(gen);
        }
        else if constexpr (std::is_floating_point<T>())
        {
            std::uniform_real_distribution<T> dis(lowerLimit, upperLimit);
            return dis(gen);
        }
        else
        {
            static_assert(std::is_arithmetic<T>(), "GetRandom requires an arithmetic type");
        }
    }
}