/**
 * @file binary_numbers.hpp
 * 
 * @brief Prototipos de funciones para conversión entre enteros y representaciones binarias.
 * 
 * @author Julian Sanchez
 * @date 01/09/2025
 */

#ifndef BINARY_NUMBERS_HPP
#define BINARY_NUMBERS_HPP

#include <iostream>

// Define el número de bits en un byte
#define BITS_ON_BYTES 8


/**
 * @brief Convierte un número entero a su representación binaria.
 * 
 * @param num El número entero a convertir.
 * @param binary Un arreglo donde se almacenará la representación binaria.
 * 
 * @return true al terminar la conversion.
 * 
 */
bool int_to_binary(u_int8_t num, u_int8_t *binary);

/**
 * @brief Convierte una representación binaria a su valor entero.
 * 
 * @param binary Un puntero que apunta a un arreglo que contiene la representación binaria.
 * 
 * @return El valor entero correspondiente a la representación binaria.
 * 
 */
u_int8_t binary_to_int(const u_int8_t *binary);



#endif // BINARY_NUMBERS_HPP