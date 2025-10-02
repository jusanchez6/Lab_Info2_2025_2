/**
 * @file app.cpp
 * @author  Julián Sánchez
 * @date 2025-10-01
 * @brief Implementación de la aplicación de gestión de red.
 *
 * Este archivo contiene la implementación de las funciones declaradas en
 * app.hpp. Proporciona la lógica del menú interactivo de consola para
 * administrar una red de routers modelada con la clase Network.
 *
 * Funcionalidades implementadas:
 * - Crear una red a partir de un archivo de configuración.
 * - Agregar y eliminar routers.
 * - Agregar, actualizar y eliminar enlaces entre routers.
 * - Consultar tablas de enrutamiento.
 * - Calcular costos de envío de paquetes.
 * - Obtener caminos mínimos entre dos routers usando Dijkstra.
 *
 * @see app.hpp
 * @see network.hpp
 */

#include <app.hpp>

void main_app(const string &file_path)
{

    auto net = make_unique<Network>();

    if (create_network(file_path, *net))
        app(*net);
}

void app(Network &net)
{
    string str_opc;
    uint8_t opc;

    do
    {
        cout << "1. Agregar Router\n2. Eliminar Router\n3. Agregar enlace\n"
             << "4. Actualizar enlace\n5. Eliminar enlace\n6. Consultar tabla de enrutamiento\n"
             << "7. Consultar costo paquete\n8. Consultar camino mas corto\n9. Salir" << endl;

        cin >> str_opc;
        opc = get_opc(str_opc);

        switch (opc)
        {
        case 1:
            add_router(net);
            break;

        case 2:
            remove_router(net);
            break;
        
        case 3:
            add_link(net);
            break;
        
        case 4:
            update_link(net);
            break;
        
        case 5:
            delete_link(net);
            break;

        case 6:
            consult_routing_table(net);
            break;
        
        case 7:
            consult_package_cost(net);
            break;
        
        case 8:
            consult_shortest_route(net);
            break;
        
        case 9:
            cout << "Adios" << endl;
            break;

        default:
            cout << "Opción no válida" << endl;
            break;
        }

    } while (opc != 9);
}


uint8_t get_opc(string &str_opc) 
{
    int16_t number;

    if (str_opc.length() > num_digis_opc) {
        return zero;
    }

    try {
        number = stoi(str_opc);
    } catch (const invalid_argument &e) {
        return 0;
    }

    if (number < zero || number > UINT8_MAX) {
        return zero;
    }

    return number;
}

void add_router(Network &net) {
    string router_id;

    if (!get_router_id(router_id)) {
        return;
    }
    net.add_network_router(router_id);
}

void remove_router(Network &net) {
    string router_id;

    if (!get_router_id(router_id)) {
        return;
    }
    net.remove_network_router(router_id);
}

void add_link(Network &net) {
    string router_id_1, router_id_2;
    
    int32_t cost;

    if (!get_link(router_id_1, router_id_2, cost)) {
        return;
    }
    net.connect_router(router_id_1, router_id_2, cost);
}

void update_link(Network &net) {
    string router_id_1, router_id_2;
    int32_t cost;
    
    if (!get_link(router_id_1, router_id_2, cost)) {
        return;
    }
    net.update_link_router(router_id_1, router_id_2, cost);
}

void delete_link(Network &net) {
    string router_id_1, router_id_2;

    cout << "Ingrese los enlaces a eliminar" << endl;

    if (!get_router_id(router_id_1)) {
        return;
    }
    if (!get_router_id(router_id_2)) {
        return;
    }

    net.remove_link_router(router_id_1, router_id_2);
}

void consult_routing_table(Network &net) {
    cout << "Router ID a consultar " << endl;
    string router_id;

    if (!get_router_id(router_id)) {
        return;
    }

    net.show_routing_table(router_id);
}

void consult_package_cost(Network &net) {
    string router_id_1, router_id_2;

    cout << "Ingrese los routers de inicio y finalización" << endl;

    if (!get_router_id(router_id_1)) {
        return;
    }

    if (!get_router_id(router_id_2)) {
        return;
    }

    int32_t cost = net.calculate_cost(router_id_1, router_id_2);

    if (cost < min_cost) {
        return;
    }

    cout << "Enviar un paquete desde " << router_id_1 << " a " << router_id_2 << " cuesta: " << cost << endl;
}

void consult_shortest_route(Network &net) {
    string router_id_1, router_id_2;
    
    cout << "Ingrese los routers de inicio y finalización." << endl;

    if (!get_router_id(router_id_1)) {
        return;
    }

    if (!get_router_id(router_id_2)) {
        return;
    }

    net.calculate_min_path(router_id_1, router_id_2);
}

bool create_network(const string &file_path, Network &net) {

    string r1, r2;

    int32_t cost;

    ifstream archivo(file_path);
    
    if (!archivo.is_open()) {
        cerr << "[create_network]: No se pudo abrir el archivo " << file_path << endl;
        return false;
    }

    while (archivo >> r1) {
        if (r1 == "-") {
            break;
        }
        if (!net.add_network_router(r1)) {
            archivo.close();
            return false;
        }
    }

    while (archivo >> r1 >> r2 >> cost) {
        if (!net.connect_router(r1, r2, cost)) {
            archivo.close();
            return false;
        }
    }

    archivo.close();
    return true;
}

// funciones aux

bool get_link(string &r1, string &r2, int32_t &cost) {

    string str_cost;
    cout << "Ingrese los Router a enlazar" << endl;

    if (!get_router_id(r1)) {
        return;
    }

    if (!get_router_id(r2)) {
        return;
    }

    cout << "Costo del enlace: ";
    cin >> str_cost;

    cost = get_cost(str_cost);
    return true;
}

bool get_router_id(string &router) {
    string router_id;
    
    if (router_id.length() > 8) {
        LOG_ERROR("get_router_id", "ID del router demasiado grande.");
        return false;
    }

    if (router_id.empty()) {
        LOG_ERROR("get_router_id", "ID del router NULO");
    }

    return true;
}

uint32_t get_cost(string &str_cost) {
    int64_t number;

    if (str_cost.length() > num_digis_cost) {
        return zero;
    }

    try
    {
        number = stoll(str_cost);
    }
    catch(invalid_argument &e)
    {
        return 0;
    }
    
    if (number < INT32_MAX || number > INT32_MAX) {
        return zero;
    }

    return number;
}