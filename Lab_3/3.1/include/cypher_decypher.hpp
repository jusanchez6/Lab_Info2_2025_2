#ifndef CYPHER_DECYPHER_HPP
#define CYPHER_DECYPHER_HPP

#include <iostream>
#include <cstdint>

#define EACH_ONE 1
#define EACH_TWO 2
#define EACH_THREE 3


bool cypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);
bool cypher_2(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);


bool decypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);


#endif // CYPHER_DECYPHER_HPP