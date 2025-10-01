/**
 * @file router.cpp
 * @author Julián Sánchez
 * @date 2025-10-01
 * @brief Implementación de la clase Router.
 *
 * Este archivo contiene la implementación de los métodos definidos en router.hpp
 * para la clase Router. Incluye operaciones para:
 *  - Agregar, actualizar y eliminar enlaces.
 *  - Mostrar vecinos directos.
 *  - Mostrar la tabla de ruteo básica en formato tabular.
 *
 * @see router.hpp
 */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <limits>

/// Macro para registrar errores en la salida de error estándar.
#define LOG_ERROR(fn, msg) cerr << "[Router/" << fn << "]:" << msg << endl;

/// Macro para registrar mensajes de éxito en la salida de error estándar.
#define LOG_SUCESS(fn, msg) cerr << "[Router/" << fn << "]:" << msg << endl;

using namespace std;

/**
 * @class Router
 * @brief Clase que representa un enrutador en una red.
 *
 * La clase Router administra enlaces hacia otros enrutadores (vecinos),
 * mantiene una tabla de ruteo básica y permite mostrar el estado de la red.
 */
class Router {
public:
    /**
     * @brief Constructor de la clase Router.
     * @param id Identificador único del router.
     */
    Router(const string &id);

    /**
     * @brief Agrega un enlace hacia un router vecino.
     * @param id_neigh Identificador del vecino.
     * @param cost Costo del enlace (debe ser mayor a 0).
     * @return true si el enlace fue agregado con éxito, false en caso de error.
     */
    bool add_link(const string &id_neigh, int32_t cost);

    /**
     * @brief Actualiza el costo de un enlace existente.
     * @param id_neigh Identificador del vecino.
     * @param cost Nuevo costo del enlace (debe ser mayor a 0).
     * @return true si la actualización fue exitosa, false si no existe o el costo es inválido.
     */
    bool update_link(const string &id_neigh, int32_t cost);

    /**
     * @brief Muestra la lista de vecinos y sus costos asociados.
     */
    void show_neighbors(void);

    /**
     * @brief Elimina un enlace hacia un router vecino.
     * @param id_neigh Identificador del vecino.
     * @return true si se eliminó con éxito, false si el enlace no existe.
     */
    bool remove_link(const string &id_neigh);

    /**
     * @brief Muestra la tabla de ruteo básica del router.
     *
     * Presenta los destinos y sus distancias de forma tabulada.
     */
    void show_routing_table(void);

    /**
     * @brief Obtiene la lista de vecinos del router.
     * @return Referencia al mapa de vecinos.
     */
    unordered_map<string, int> &get_neighbors(void) { return neighbors; }

    /**
     * @brief Obtiene la tabla de ruteo básica del router.
     * @return Referencia al mapa de la tabla de ruteo.
     */
    unordered_map<string, int> &get_routing_table(void) { return basic_routing_table; }

private:
    /// Identificador único del router.
    string m_id;

    /// Mapa de vecinos directos y sus costos asociados.
    unordered_map<string, int> neighbors;

    /// Tabla de ruteo básica (destinos y distancias).
    unordered_map<string, int> basic_routing_table;

    /**
     * @brief Verifica si existe un enlace hacia un vecino específico.
     * @param id_neigh Identificador del vecino.
     * @return true si el enlace existe, false en caso contrario.
     */
    bool link_exists(const string &id_neigh);
};

#endif // ROUTER_HPP
