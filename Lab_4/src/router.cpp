/**
 * @file router.hpp
 * @author Julian Sanchez
 * @date 2025-10-01
 * @brief Definición de la clase Router.
 *
 * Este archivo contiene la declaración de la clase Router, que modela
 * un enrutador con enlaces a vecinos y una tabla de ruteo básica.
 * 
 * La clase permite agregar, actualizar y eliminar enlaces, así como
 * visualizar vecinos y la tabla de ruteo en formato tabulado.
 *
 * @note Esta es la interfaz pública de la clase. La implementación
 * se encuentra en router.cpp.
 */

#include <router.hpp>

Router::Router(const string &id) : m_id(id) {}

bool Router::link_exists(const string &id_neigh)
{
    return neighbors.count(id_neigh) > 0;
}

bool Router::add_link(const string &id_neigh, int32_t cost)
{
    if (cost < 1)
    {
        LOG_ERROR("Add_link", "El costo no puedo ser negativo")
        return false;
    }

    neighbors[id_neigh] = cost;
    LOG_SUCESS("Add_Link", m_id + " -> " + id_neigh + " - Costo: " + to_string(cost));
    return true;
}

bool Router::update_link(const string &id_neigh, int32_t cost)
{

    if (cost < 1)
    {
        LOG_ERROR("update_link", "El nuevo costo no puede ser negativo");
        return false;
    }
    if (!link_exists(id_neigh))
    {
        LOG_ERROR("update_link", m_id + " -> " + id_neigh + " - No existe");
        return false;
    }

    neighbors[id_neigh] = cost;
    LOG_SUCESS("update_link", m_id + " -> " + id_neigh + " - costo: " + std::to_string(cost));

    return true;
}

bool Router::remove_link(const string &id_neigh) {
    if (!link_exists(id_neigh)) {
        LOG_ERROR("Remove_link", m_id + " -> " + id_neigh + " - No existe");
        return false;
    }

    neighbors.erase(id_neigh);
    LOG_SUCESS("Remove_link", m_id + " -> " + id_neigh + " - Eliminado");
    return true;
        
}

void Router::show_neighbors(void ) {
    for (const auto&[id_neigh, cost] : neighbors) {
        cout << "[Router]:" << m_id << " -> " << id_neigh << " Costo: " << cost << endl;
    }
}

void Router::show_routing_table (void) {
    vector <pair<string, int>> table (
        basic_routing_table.begin(),
        basic_routing_table.end()   
    );

    sort(table.begin(), table.end());

    cout << "+---------------------+---------------------+" << endl;
    cout << "| " << left << setw(20) << "Router ID" 
              << "| " << setw(20) << "Distancia" << "|" << endl;
    cout << "+---------------------+---------------------+" << endl;

    // Filas de datos
    for (const auto& [router_id, distance] : table) {
        if (distance == INT32_MAX)
            continue;
        cout << "| " << left << setw(20) << router_id 
                  << "| " << setw(20) << distance << "|" << endl;
    }

    // Pie de tabla
    cout << "+---------------------+---------------------+" << endl;


}
