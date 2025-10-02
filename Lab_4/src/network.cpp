/**
 * @file network.cpp
 * @author Julián Sánchez
 * @date 2025-10-01
 * @brief Implementación de la clase Network.
 *
 * Este archivo contiene la implementación de los métodos declarados en
 * network.hpp. La clase Network administra un conjunto de routers y permite:
 * 
 * - Agregar y eliminar routers.
 * - Conectar routers mediante enlaces con costo.
 * - Actualizar o eliminar enlaces existentes.
 * - Calcular tablas de enrutamiento para todos los routers.
 * - Obtener caminos mínimos entre dos routers usando Dijkstra.
 * - Consultar el costo de dichos caminos.
 *
 * @see network.hpp
 */

#include <network.hpp>

bool Network::router_exists(const string &router_id)
{
    return routers.count(router_id) > 0;
}

bool Network::add_network_router(const string &router_id)
{
    if (router_exists(router_id))
    {
        LOG_ERROR("add_network_router", "Router: " + router_id + " ya existe");
        return false;
    }

    routers[router_id] = make_unique<Router>(router_id);
    calculate_all_routing_tables();
    LOG_SUCESS("add_network_router", "Router: " + router_id + " creado");
    return true;
}

bool Network::remove_network_router(const string &router_id)
{

    vector<string> to_delete;
    if (!router_exists(router_id))
    {
        LOG_ERROR("remove_network_router", "Router: " + router_id + " no existe");
        return false;
    }

    for (auto &[id_neigh, _] : routers[router_id]->get_neighbors())
    {
        to_delete.push_back(id_neigh);
    }

    for (auto &id_neigh : to_delete)
    {
        remove_link_router(router_id, id_neigh);
    }

    LOG_SUCESS("remove_network_router", "Router: " + router_id + " Eliminado");
    routers.erase(router_id);
    calculate_all_routing_tables();

    return true;
}

bool Network::connect_router(const string &router_1_id, const string &router_2_id, int32_t cost)
{
    if (!router_exists(router_1_id) || !router_exists(router_2_id))
    {
        LOG_ERROR("connect_router", "Ambos routers deben existir para poderlos conectar");
        return false;
    }

    if (cost < 1)
    {
        LOG_ERROR("connect_router", "El costo debe ser positivo");
        return false;
    }

    if (!routers[router_1_id]->add_link(router_2_id, cost))
    {
        return false;
    }

    if (!routers[router_2_id]->add_link(router_1_id, cost))
    {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("connect_router", "Enlace establecido.");
    return true;
}

bool Network::update_link_router(const string &router_1_id, const string &router_2_id, int32_t cost)
{
    if (!router_exists(router_1_id) || !router_exists(router_2_id))
    {
        LOG_ERROR("update_link_router", "Ambos routers deben existir para poder actualizar su costo");
        return false;
    }

    if (cost < 1)
    {
        LOG_ERROR("update_link_router", "El costo debe ser positivo");
        return false;
    }

    if (!routers[router_1_id]->update_link(router_2_id, cost))
    {
        return false;
    }

    if (!routers[router_2_id]->update_link(router_1_id, cost))
    {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("update_link_router", "Enlace actualizado");
    return true;
}

bool Network::remove_link_router(const string &router_1_id, const string &router_2_id)
{
    if (!router_exists(router_1_id) || !router_exists(router_2_id))
    {
        LOG_ERROR("remove_link_router", "Ambos routers deben existir para poder actualizarlos eliminar");
        return false;
    }

    if (!routers[router_1_id]->remove_link(router_2_id))
    {
        return false;
    }

    if (!routers[router_2_id]->remove_link(router_1_id))
    {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("remove_link_router", "Enlace eliminado");
    return true;
}

void Network::show_connections(void)
{
    for (const auto &[router_id, router] : routers)
    {
        router->show_neighbors();
    }
}

void Network::calculate_all_routing_tables(void)
{
    for (auto &[router_id, router] : routers)
    {
        find_shortest_path(router_id, router_id, router->get_routing_table());
    }
}

bool Network::show_routing_table(const string &router_id)
{
    if (!router_exists(router_id))
    {
        LOG_ERROR("show_routing_table", "No existe el router" + router_id);
        return false;
    }

    routers[router_id]->show_routing_table();
    return true;
}

bool Network::calculate_min_path(const string &start, const string &end)
{
    if (!router_exists(start) || !router_exists(end))
    {
        LOG_ERROR("calculate_min_path", "Ambos routers deben existir");
        return false;
    }

    vector<string> path;
    path = find_shortest_path(start, end, routers[start]->get_routing_table());

    if (path.empty())
    {
        LOG_ERROR("calculate_min_path", "No existe camino entre: " + start + " y " + end);
        return false;
    }

    for (auto router_id : path)
    {
        cout << "->" << router_id;
    }

    cout << "\n";

    return true;
}

int32_t Network::calculate_cost(const string &start, const string &end)
{

    if (!router_exists(start) || !router_exists(end))
    {
        LOG_ERROR("calculate_cost", "Ambos routers deben existir");
        return false;
    }

    return (routers[start]->get_routing_table())[end];
}

vector<string> Network::find_shortest_path(const string &start, const string &end, unordered_map<string, int> &distance)
{
    //Definición de cola de prioridad
    using queue_entry = pair<int, string>;

    //Creo una cola de prioridad de elementos tipo queue_entry, almacenados en un vector
    //y que en el top siempre esté la menor distancia
    priority_queue<queue_entry, vector<queue_entry>, greater<queue_entry>> queue;
    
    //Limpiemos todas las distancias del router
    distance.clear();

    //Y mantener el último router visitado
    unordered_map<string, string> previous;

    //Para mantener el camino
    vector<string> path;

    // Todas las distancias se inicializan muy grandes
    for (const auto& [id, _] : routers) {
        distance[id] = INT32_MAX;
    }

    //La primera no se cuenta es 0
    distance[start] = 0;
    //El primer router a evaluar es el inicio
    queue.push({0, start});
    
    while (!queue.empty()) {
        //Mientras existan routers en el camino habrá que seguir buscando cuál da la mejor distancia 
        auto [dist, current] = queue.top();
        queue.pop();

        //Ahora hay que evaluar tooodos los vecinos del router actual y ver cuál es la mejor distancia a los vecinos
        for (const auto &[neighbor, cost] : routers[current]->get_neighbors()) {
            uint32_t new_dist = dist + cost;
            //Si la nueva distancia desde el router mejora la distancia actual hasta el vecino
            if (new_dist < distance[neighbor]) {
                distance[neighbor] = new_dist;
                previous[neighbor] = current;
                queue.push({new_dist, neighbor});
                //Ahora se tiene la menor distancia
            }
        }
    }

    for (string at=end; at != ""; at = previous[at]) {
        path.push_back(at);
        if (at == start)
            break;
    }

    if (path.back() != start)
        return {};

    reverse(path.begin(), path.end());
    return path;
}
