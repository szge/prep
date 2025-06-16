#pragma once

#include <chrono>
#include <random>

/*
 * This header-only namespace implements a self-seeding Mersenne twister
 * requires C++17 for uniform_int_distribution template
 */

namespace Random
{
    // returns a seeded Mersenne Twister
    // we can't copy seed_seq, so instead we return an instance of std::mt19937
    inline std::mt19937 generate()
    {
        std::random_device rd{};
        std::seed_seq ss { // create seed_seq with clock and 7 numbers from random_device
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd()
        };
        return std::mt19937 { ss };
    }

    // global std::mt19937 object
    inline std::mt19937 mt { generate() };

    // generate a random int between [min, max] in cases where args can be converted to int
    inline int get(const int min, const int max)
    {
        return std::uniform_int_distribution<> { min, max }(mt);
    }

    // generate a random value between [min, max] in cases where min and max have the same type
    // sample call: `Random::get(1l, 6l);`
    // sample call: `Random::get(1u, 6u);`
    template <typename T>
    T get(const T min, const T max)
    {
        return std::uniform_int_distribution<T> { min, max }(mt);
    }

    template <typename R, typename S, typename T>
    R get(const S min, const T max)
    {
        return std::uniform_int_distribution<R> { static_cast<R>(min), static_cast<R>(max) }(mt);
    }
}