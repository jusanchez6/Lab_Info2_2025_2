#include "binary_numbers.hpp"

bool int_to_binary(u_int8_t num, u_int8_t *binary) {
    
    int8_t bits = BITS_ON_BYTES - 1;
    while (num > 0) {
        binary[bits] = num % 2;
        num /= 2;
        bits--;
    }

    return true;
}

u_int8_t binary_to_int(const u_int8_t *binary) {
    u_int8_t num = 0;
    for (int i = 0; i < BITS_ON_BYTES; i++) {
        num += binary[BITS_ON_BYTES - 1 - i] << i;
    }
    return num;
}
