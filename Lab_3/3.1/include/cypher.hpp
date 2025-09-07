/**
 * @file cypher.hpp
 * 
 * @brief Prototipos de funciones para cifrado y descifrado de matrices binarias.
 * @author Julian Sanchez
 * @date 02/09/2025
 * 
 */

#ifndef CYPHER_HPP
#define CYPHER_HPP

#include <iostream>
#include <cstdint>

#define EACH_ONE 1
#define EACH_TWO 2
#define EACH_THREE 3

/**
 * @brief Cifra una matriz de bits siguiendo un patrón específico.
 *  
 * @param matrix Matriz de bits a cifrar.
 * @param n Número de bits en cada grupo.
 * @param rows Número de filas en la matriz.
 * @param cols Número de columnas en la matriz.
 * 
 * @return true al terminar el cifrado.
 * 
 */
bool cypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);

/**
 * @brief Cifra una matriz de bits realizando un desplazamiento circular a la derecha.
 * 
 * @param matrix Matriz de bits a cifrar.
 * @param n Número de bits en cada grupo.
 * @param rows Número de filas en la matriz.
 * @param cols Número de columnas en la matriz.
 * 
 * @return true al terminar el cifrado.
 * 
 */
bool cypher_2(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);


bool decypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);

bool decypher_2(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);

#endif // CYPHER_HPP