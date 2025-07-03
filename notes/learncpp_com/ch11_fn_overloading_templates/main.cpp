#include <iostream>
#include <cmath>

void foo (int)
{

}

void foo (double)
{

}

void printInt(const int x)
{
    std::cout << x << '\n';
}

// void printInt(char) = delete;
// void printInt(bool) = delete;

// delete all non-exact-matches
template <typename T>
void printInt(T x) = delete;

template <typename T>
T max(T x, T y)
{
    // std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

int max(int x, int y)
{
    // std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

// if you want to forward declare a fn, you need to be explicit about the return type
template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>;

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
    return (x < y) ? y : x;
}

// this is the same as the above fn in C++20; auto max(T x, U y);
// auto max(auto x, auto y)
// {
//     return (x < y) ? y : x;
// }

template <typename T>
T addOne(const T x)
{
    return x + 1;
}

// tell the compiler that addOne(const char*) should emit a compilation error
template <>
const char* addOne (const char* x) = delete;

// non-type template param
// template <typename T, T N>
template <int N>
void print()
{
    std::cout << N << '\n';
}

template <double D>
double getSqrt()
{
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");
    if constexpr (D >= 0) return std::sqrt(D);
    return 0.0;
}

template <int N>
constexpr int factorial()
{
    static_assert(N >= 0, "factorial(): N must be non-negative");
    if constexpr (N == 0) return 1;
    int prod { 1 };
    for (int n {2}; n <= N; ++n) prod *= n;
    return prod;
}

int main()
{
    // foo(5L); // this call is ambiguous

    printInt(2340);

    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls max(int, int)

    // using templates with multiple types
    // option 1: use static_cast
    std::cout << max(static_cast<double>(2), 3.5) << '\n';
    // option 2: use an explicit template type arg
    std::cout << max<double>(2, 3.5) << '\n';
    // option 3: create a fn template with multiple template type params
    std::cout << max(2, 3.5) << '\n';

    print<5>();
    print<'c'>();

    std::cout << getSqrt<5.0>() << '\n';
    // we can use non-type template params to use constexpr
    // std::cout << getSqrt<-5.0>() << '\n'; // fails due to compiler error

    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // factorial<-3>(); // should fail to compile
    return 0;
}