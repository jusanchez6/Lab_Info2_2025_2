#ifndef APP_ATM_HPP
#define APP_ATM_HPP

// standar libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdint.h>
#include <string>

// custom libraries
#include <cypher.hpp>
#include <app.hpp>
#include <binary_numbers.hpp>


// definiciones para la aplicacion de cajero

#define ADMIN_FILE "sudo.txt"
#define USERS_FILE "users.txt" 
#define SEMILLA 6
#define BITS_ON_BYTES 8
#define NULL_STR ""
#define NO_DATA 0


using metodo_ptr = bool (*)(uint8_t **, uint32_t, uint32_t, uint32_t);
using namespace std;


my_error_t main_app_atm();

my_error_t validar_usuario(const string &file_string, bool admin, string &user_data);

my_error_t validar_usuario(const string &file_string, bool admin, string &user_data);

void app_administrador(string &users_file);

void app_usuarios(string& file_string, string& user);

#endif //APP_ATM_HPP
