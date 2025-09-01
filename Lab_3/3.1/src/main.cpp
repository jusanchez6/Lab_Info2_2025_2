#include <iostream>
#include "binary_numbers.hpp"

int main() {
    u_int8_t num = 42;
    u_int8_t binary[BITS_ON_BYTES] = {0};

    int_to_binary(num, binary);
    std::cout << "Binary representation of " << (int)num << ": ";
    for (int i = 0; i < BITS_ON_BYTES; i++) {
        std::cout << (int)binary[i];
    }
    std::cout << std::endl;

    u_int8_t converted = binary_to_int(binary);
    std::cout << "Converted back to integer: " << (int)converted << std::endl;

    return 0;
}