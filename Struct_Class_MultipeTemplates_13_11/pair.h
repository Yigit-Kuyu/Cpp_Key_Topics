#ifndef PAIR_H
#define PAIR_H


// The compiler must be able to see the full definition of templates to use them, not just a forward declaration.
// This is why templates are normally defined in header files.

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

#endif
