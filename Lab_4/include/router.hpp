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

using namespace std;

class Router {

public:
    Router(const string &id);
    bool add_link(const string &id_neigh, int32_t cost);
    bool update_link(const string &id_neigh, int32_t cost);
    void show_neighbors(void );
    bool remove_link(const string &id_neigh);
    void show_routing_table(void );
    unordered_map<string, int> &get_neighbors(void );
    unordered_map<string, int> &get_routing_table(void );
    

private:
    string m_id;
    unordered_map<string, int> neighbors;
    unordered_map<string, int> basic_routing_table;
    bool link_exists(const string id_neigh);

};




#endif // ROUTER_HPP
