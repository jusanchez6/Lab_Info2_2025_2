/**
 * @file app.hpp
 * @author Julián Sánchez
 * @date 2025-10-01
 * @brief Interfaz de la aplicación de gestión de red.
 *
 * Este archivo contiene las declaraciones de las funciones que implementan
 * la lógica de la aplicación de consola para administrar una red de routers
 * modelada con la clase Network.
 *
 * Funcionalidades principales:
 * - Creación de la red a partir de un archivo.
 * - Menú interactivo de consola para administrar routers y enlaces.
 * - Operaciones CRUD sobre routers y enlaces.
 * - Consulta de tablas de enrutamiento.
 * - Cálculo de costos de envío de paquetes.
 * - Obtención de caminos mínimos entre routers.
 *
 * @see network.hpp
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <limits>
#include <string>

#include <network.hpp>

using namespace std;

/// Macro para registrar errores en la salida estándar de error.
/// @param fn Nombre de la función que reporta el error.
/// @param msg Mensaje descriptivo del error.
#define LOG_ERROR(fn, msg) std::cerr << "[App/" << fn << "]: " << msg << std::endl

/// Número máximo de dígitos permitidos para la opción del menú.
constexpr uint8_t num_digis_opc = 4;
/// Representa el valor cero utilizado en validaciones.
constexpr uint8_t zero = 0;
/// Número máximo de dígitos permitidos para el costo de un enlace.
constexpr uint8_t num_digis_cost = 10;
/// Costo mínimo permitido para enlaces o paquetes.
constexpr uint8_t min_cost = 0;

/**
 * @brief Función principal de la aplicación.
 * 
 * Inicializa la red desde un archivo y lanza el menú interactivo.
 * 
 * @param file_path Ruta del archivo de configuración de la red.
 */
void main_app(const string &file_path);

/**
 * @brief Crea una red a partir de un archivo de texto.
 *
 * El archivo debe contener primero los IDs de los routers (terminando con "-")
 * y luego las conexiones con sus costos.
 *
 * @param file_path Ruta al archivo de configuración.
 * @param net Referencia a la instancia de la red.
 * @return true si la red fue creada exitosamente, false en caso de error.
 */
bool create_network(const string &file_path, Network &net);

/**
 * @brief Ejecuta el menú principal de la aplicación.
 * 
 * Proporciona al usuario un menú de opciones para interactuar con la red.
 * 
 * @param net Referencia a la red gestionada.
 */
void app(Network &net);

/// @brief Agrega un router a la red.
/// @param net Referencia a la red.
void add_router(Network &net);

/// @brief Elimina un router de la red.
/// @param net Referencia a la red.
void remove_router(Network &net);

/// @brief Crea un enlace entre dos routers.
/// @param net Referencia a la red.
void add_link(Network &net);

/// @brief Actualiza el costo de un enlace existente.
/// @param net Referencia a la red.
void update_link(Network &net);

/// @brief Elimina un enlace entre dos routers.
/// @param net Referencia a la red.
void delete_link(Network &net);

/// @brief Consulta la tabla de enrutamiento de un router específico.
/// @param net Referencia a la red.
void consult_routing_table(Network &net);

/// @brief Consulta el costo de enviar un paquete entre dos routers.
/// @param net Referencia a la red.
void consult_package_cost(Network &net);

/// @brief Consulta el camino más corto entre dos routers.
/// @param net Referencia a la red.
void consult_shortest_route(Network &net);

/**
 * @brief Obtiene los datos de un enlace desde la entrada del usuario.
 * 
 * Solicita los IDs de los routers y el costo del enlace.
 * 
 * @param r1 ID del primer router (salida).
 * @param r2 ID del segundo router (salida).
 * @param cost Costo del enlace (salida).
 * @return true si la entrada es válida, false en caso contrario.
 */
bool get_link(string &r1, string &r2, int32_t &cost);

/**
 * @brief Valida y obtiene el ID de un router desde entrada del usuario.
 * 
 * @param router ID del router (salida).
 * @return true si el ID es válido, false en caso contrario.
 */
bool get_router_id(string &router);

/**
 * @brief Convierte una cadena a un número de opción válida.
 * 
 * @param str_opc Cadena de entrada.
 * @return Número de opción válido (0 si no es válido).
 */
uint8_t get_opc(string &str_opc);

/**
 * @brief Convierte una cadena a un costo válido de enlace.
 * 
 * @param str_cost Cadena con el costo.
 * @return Valor numérico del costo (0 si no es válido).
 */
uint32_t get_cost(string &str_opc);

#endif // APP_HPP
