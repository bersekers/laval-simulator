#include <algorithm>
#include <array>
#include <bitset>


template<class T>
T Tools::umaxof()
{
    T t;
    auto ptr = reinterpret_cast<char *>(&t);
    std::fill(ptr, ptr + sizeof(T), 0xff);
    return t;
}

constexpr unsigned long Tools::upper_power_of_two(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

constexpr size_t Tools::log2(size_t n)
{
    return ((n < 2) ? 1 : 1 + log2(n / 2));
}

constexpr uint8_t Tools::three_pow(unsigned long n)
{
    return std::array{1_u8, 3_u8, 9_u8, 27_u8, 81_u8, 243_u8}.at(n);
}
