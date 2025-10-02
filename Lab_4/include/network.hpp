/**
 * @file network.hpp
 * @author Julián Sánchez
 * @date 2025-10-01
 * @brief Definición de la clase Network.
 *
 * Este archivo contiene la declaración de la clase Network, la cual administra
 * un conjunto de routers y sus conexiones. Permite agregar o eliminar routers,
 * establecer enlaces con costos, calcular rutas mínimas usando Dijkstra y
 * mostrar tablas de enrutamiento.
 *
 * @see router.hpp
 */

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>
#include <string>
#include <stdint.h>
#include <vector>
#include <set>
#include <queue>
#include <limits>
#include <algorithm>
#include <router.hpp>

/// Macro para registrar errores en la salida estándar de error.
#define LOG_ERROR(fn, msg) std::cerr << "[Network/" << fn << "]: " << msg << std::endl

/// Macro para registrar mensajes de éxito en la salida estándar.
#define LOG_SUCESS(fn, msg) std::cout << "[Network/" << fn << "]: " << msg << std::endl

using namespace std;

/**
 * @class Network
 * @brief Representa una red compuesta por múltiples routers.
 *
 * La clase Network administra un conjunto de routers, sus enlaces y costos asociados.
 * Permite calcular rutas mínimas entre routers utilizando el algoritmo de Dijkstra.
 */
class Network
{
public:
    /**
     * @brief Agrega un router a la red.
     * @param router_id Identificador único del router.
     * @return true si fue agregado con éxito, false si ya existe.
     */
    bool add_network_router(const string &router_id);

    /**
     * @brief Elimina un router de la red.
     * @param router_id Identificador del router.
     * @return true si fue eliminado con éxito, false si no existe.
     */
    bool remove_network_router(const string &router_id);

    /**
     * @brief Conecta dos routers con un costo dado (enlace bidireccional).
     * @param router_1_id Identificador del primer router.
     * @param router_2_id Identificador del segundo router.
     * @param cost Costo del enlace (debe ser mayor a 0).
     * @return true si la conexión fue establecida, false en caso de error.
     */
    bool connect_router(const string &router_1_id, const string &router_2_id, int32_t cost);

    /**
     * @brief Actualiza el costo de un enlace existente entre dos routers.
     * @param router_1_id Identificador del primer router.
     * @param router_2_id Identificador del segundo router.
     * @param cost Nuevo costo del enlace (debe ser mayor a 0).
     * @return true si la actualización fue exitosa, false en caso de error.
     */
    bool update_link_router(const string &router_1_id, const string &router_2_id, int32_t cost);

    /**
     * @brief Elimina un enlace entre dos routers.
     * @param router_1_id Identificador del primer router.
     * @param router_2_id Identificador del segundo router.
     * @return true si se eliminó con éxito, false en caso de error.
     */
    bool remove_link_router(const string &router_1_id, const string &router_2_id);

    /**
     * @brief Muestra todas las conexiones (vecinos) de cada router en la red.
     */
    void show_connections(void);

    /**
     * @brief Calcula las tablas de ruteo de todos los routers en la red.
     *
     * Internamente usa Dijkstra para llenar las distancias mínimas.
     */
    void calculate_all_routing_tables(void);

    /**
     * @brief Muestra la tabla de ruteo de un router específico.
     * @param router_id Identificador del router.
     * @return true si el router existe y se muestra la tabla, false en caso contrario.
     */
    bool show_routing_table(const string &router_id);

    /**
     * @brief Calcula y muestra el camino mínimo entre dos routers.
     * @param router_1_id Identificador del router inicial.
     * @param router_2_id Identificador del router destino.
     * @return true si existe un camino, false si no hay conexión.
     */
    bool calculate_min_path(const string &router_1_id, const string &router_2_id);

    /**
     * @brief Calcula el costo del camino mínimo entre dos routers.
     * @param start Identificador del router de inicio.
     * @param end Identificador del router destino.
     * @return Costo total del camino, o INT32_MAX si no existe.
     */
    int32_t calculate_cost(const string &start, const string &end);

private:
    /// Contenedor de routers en la red (clave: identificador, valor: puntero único a Router).
    unordered_map<string, unique_ptr<Router>> routers;

    /**
     * @brief Verifica si un router existe en la red.
     * @param router_id Identificador del router.
     * @return true si existe, false en caso contrario.
     */
    bool router_exists(const string &router_id);

    /**
     * @brief Calcula el camino más corto entre dos routers usando Dijkstra.
     * @param start Router de inicio.
     * @param end Router de destino.
     * @param distance Referencia al mapa donde se guardarán las distancias mínimas desde start.
     * @return Vector con la secuencia de routers que forman el camino mínimo.
     */
    vector<string> find_shortest_path(const string &start, const string &end, unordered_map<string, int> &distance);
};

#endif // NETWORK_HPP
