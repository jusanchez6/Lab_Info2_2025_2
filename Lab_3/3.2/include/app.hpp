#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <fstream>
#include <cstring>

#include "cypher.hpp"
#include "binary_numbers.hpp"

/**
 * @brief Declaración del tipo my_error_t para el manejo de excepciones y errores
 */
typedef enum {
    ERROR,      // ERROR GENERAL
    OK,         // OK
    TIMEOUT     // TIMEOUT, NO CREO USARLO
} my_error_t;



// Prototipo de la función para métodos de cifrado/descifrado
using metodo_ptr = bool (*)(uint8_t **, uint32_t, uint32_t, uint32_t);
using namespace std;

/**
 * @brief Main de la aplicación de encriptación
 * 
 * @param argv: Arreglo de arguemntos de entrada
 */
my_error_t app_main(char *argv[]);

/**
 * @brief Función con la logica principal del cifrado
 * 
 * @param metodo: nombre de la función con el metodo que se desea aplicar
 * @param origen: puntero a la dirección donde se encuentra almacenado el nombre del archivo fuente
 * @param destino: Puntero a la dirección donde se encuentra almacenado el nombre del archivo destino
 * @param semilla: Numer de bits a rotar o comparar
 * 
 * @return OK: SI todo salió bien
 */
my_error_t app (metodo_ptr metodo, char *origen, char *destino, uint8_t semilla);



/**
 * @brief Abre un archivo y lee el contenido del archivo
 * 
 * @param filename: nombre del archivo
 * @param memory: puntero al bloque de memoria donde se almacena el contenido del texto
 * 
 * @return int: Tamaño del archivo leido.
 */
int read_file(const char *filename, uint8_t **memory);


/**
 * @brief abre un archivo y escribe el contenido del bloque de memoria
 * 
 * @param filename: Nombre del archivo
 * @param memory: Puntero al bloque de memoria donde se almacena el contenido del texto que se escribira
 * 
 * @return Ok: si todo salio bien
 */
my_error_t write_file(const char *filename, uint8_t *memory, int32_t size);


/**
 * @brief Asigna la memoria dinamica para la matrix donde se almacenara la informacion binaria
 * 
 * @param matrix_binaria: un puntero triple porque soy un malote
 * @param size: Tamaño del arreglo del cual se necesita reservar memoria
 * 
 * @return OK: Si todo salio bien 
 * 
 */
my_error_t assing_memory(uint8_t *** matrix_binaria, int size);



/**
 * @brief Libera la memoria dinamica usada en la matrix de contenido
 * 
 * @param matrix_binaria: puntero triple, direccion de la direccion del arreglo (matrix)
 * @param size: tamaño de la matrix
 */
void delete_memory(uint8_t ***matrix_binaria, uint8_t size);

/**
 * @brief Convierte el contenido del archivo a binario
 * 
 * @param memory: puntero al bloque de memoria donde esta el contenido
 * @param bin_matrix: Puntero al bloque de memoria donde se guardará el contenido convertido en binario
 * @param size: Tamaño del contenido
 * 
 * @return 1: OK
 * 
 */
my_error_t int_to_bynary_convert(uint8_t *memory, uint8_t ** bin_matrix, uint size);


/**
 * @brief Convierte una matrix binaria a char y lo guarda en un espacio de la memoria
 * 
 * @param matrix_binaria: Puntero al arreglo donde se almacena la información en binario
 * @param memory: Espacio de memoria donde se almacenará el nuevo contenido
 * @param size: Tamaño del contenido
 * 
 */
void binary_to_char(uint8_t **matrix_binaria, uint8_t *memory, int32_t size);


#endif // APP_HPP