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

#define LOG_ERROR(fn, msg) std::cerr << "[Network/" << fn << "]: " << msg << std::endl
#define LOG_SUCESS(fn, msg) std::cout << "[Network/" << fn << "]: " << msg << std::endl

using namespace std;

class Network
{

public:
    bool add_network_router(const string &router_id);
    bool remove_network_router(const string &router_id);
    bool connect_router(const string &router_1_id, const string &router_2_id, int32_t cost);
    bool update_link_router(const string &router_1_id, const string &router_2_id, int32_t cost);
    bool remove_link_router(const string &router_1_id, const string &router_2_id);

    void show_connections(void);
    void calculate_all_routing_tables(void);
    
    bool show_routing_table(const string &router_id);
    bool calculate_min_path(const string &router_1_id, const string &router_2_id);
    int32_t calculate_cost(const string &start, const string &end);
    bool remove_network_router(const string router_id);

private:
    unordered_map<string, unique_ptr<Router>> routers;
    bool router_exists(const string &router_id);
    vector<string> find_shortest_path(const string &start, const string &end, unordered_map<string, int> &distance); 
};

#endif // NETWORK_HPP