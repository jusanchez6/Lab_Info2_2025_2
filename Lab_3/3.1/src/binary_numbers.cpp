#include "binary_numbers.hpp"

bool int_to_binary(u_int8_t num, u_int8_t *binary)
{

    int8_t bits = BITS_ON_BYTES - 1;
    for (; bits >= 0; bits--)
    {
        *(binary + bits) = num % 2;
        num = num / 2;
    }
    return true;
}

u_int8_t binary_to_int(const u_int8_t *binary)
{
    u_int8_t num = 0;
    for (u_int8_t i = 0; i < BITS_ON_BYTES; i++)
    {
        num = 2 * num + binary[i];
    }
    return num;
}
