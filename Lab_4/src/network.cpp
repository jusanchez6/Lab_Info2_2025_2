#include <network.hpp>

bool Network::router_exists(const string &router_id) {
    return routers.count(router_id) > 0;
}

bool Network::add_network_router(const string &router_id) {
    if (router_exists(router_id)) {
        LOG_ERROR("add_network_router", "Router: " + router_id + " ya existe");
        return false;
    }

    routers[router_id] = make_unique<Router>(router_id);
    calculate_all_routing_tables();
    LOG_SUCESS("add_network_router", "Router: " + router_id + " creado");
    return true;
}

bool Network::remove_network_router(const string &router_id) {
    
    vector<string> to_delete;
    if (!router_exists(router_id)) {
        LOG_ERROR("remove_network_router", "Router: " + router_id + " no existe");
        return false;
    }

    for (auto &[id_neigh, _] : routers[router_id]->get_neighbors()) {
        to_delete.push_back(id_neigh);
    }

    for (auto &id_neigh : to_delete) {
        remove_link_router(router_id, id_neigh);
    }

    LOG_SUCESS("remove_network_router", "Router: " + router_id + " Eliminado");
    routers.erase(router_id);
    calculate_all_routing_tables();

    return true;

}

bool Network::connect_router(const string &router_1_id, const string &router_2_id, int32_t cost) {
    if (!router_exists(router_1_id) || !router_exists(router_2_id)) {
        LOG_ERROR("connect_router", "Ambos routers deben existir para poderlos conectar");
        return false;
    }

    if (cost < 1) {
        LOG_ERROR("connect_router", "El costo debe ser positivo");
        return false;
    }

    if (!routers[router_1_id]->add_link(router_2_id, cost)) {
        return false;
    }

    if (!routers[router_2_id]->add_link(router_1_id, cost)) {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("connect_router", "Enlace establecido.");
    return true;
}

bool Network::update_link_router(const string &router_1_id, const string &router_2_id, int32_t cost) 
{
    if (!router_exists(router_1_id) || !router_exists(router_2_id)) {
        LOG_ERROR("update_link_router", "Ambos routers deben existir para poder actualizar su costo");
        return false;
    }

    if (cost < 1) {
        LOG_ERROR("update_link_router", "El costo debe ser positivo");
        return false;
    }

    if (!routers[router_1_id]->update_link(router_2_id, cost)) {
        return false;
    }

    if (!routers[router_2_id]->update_link(router_1_id, cost)) {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("update_link_router", "Enlace actualizado");
    return true;
}

bool Network::remove_link_router(const string &router_1_id, const string &router_2_id) 
{
    if (!router_exists(router_1_id) || !router_exists(router_2_id)) {
        LOG_ERROR("remove_link_router", "Ambos routers deben existir para poder actualizarlos eliminar");
        return false;
    }

    if (!routers[router_1_id]->remove_link(router_2_id)) {
        return false;
    }

    if (!routers[router_2_id]->remove_link(router_1_id)) {
        return false;
    }

    calculate_all_routing_tables();
    LOG_SUCESS("remove_link_router", "Enlace eliminado");
    return true;
}


void Network::show_connections(void ) {
    for (const auto &[router_id, router] : routers) {
        router->show_neighbors();
    }
}


void Network::calculate_all_routing_tables(void ) {
    for (auto &[router_id, router] : routers) {
        find_shortest_path(router_id, router_id, router->get_routing_table());
    }
}

bool Network::show_routing_table(const string &router_id) {
    if (!router_exists(router_id)) {
        LOG_ERROR("show_routing_table", "No existe el router" + router_id);
        return false;
    }

    routers[router_id]->show_routing_table();
    return true;
}

bool Network::calculate_min_path(const string &start, const string &end) {
    if (!router_exists(start) || !router_exists(end)) {
        LOG_ERROR("calculate_min_path", "Ambos routers deben existir");
        return false;
    }

    vector<string> path;
    path = find_shortest_path(start, end, routers[start]->get_routing_table());

    if (path.empty()) {
        LOG_ERROR("calculate_min_path", "No existe camino entre: " + start + " y " + end);
        return false;
    }

    for (auto router_id: path) {
        cout << "->" << router_id;
    }

    cout << "\n";

    return true;
}



int32_t Network::calculate_cost(const string &start, const string &end) {

    if (!router_exists(start) || !router_exists(end)) {
        LOG_ERROR("calculate_cost", "Ambos routers deben existir");
        return false;
    }

    return (routers[start]->get_routing_table())[end];
}


