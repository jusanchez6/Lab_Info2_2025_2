#ifndef BINARY_NUMBERS_HPP
#define BINARY_NUMBERS_HPP

#include <iostream>

#define BITS_ON_BYTES 8

bool int_to_binary(u_int8_t num, u_int8_t *binary);
u_int8_t binary_to_int(const u_int8_t *binary);



#endif // BINARY_NUMBERS_HPP