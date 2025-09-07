#include <app_atm.hpp>
#include <string>

namespace
{

    string read_data(const char *file, metodo_ptr metodo, uint32_t semilla)
    {
        uint8_t *memory;
        uint8_t **matrix_binaria;
        uint32_t size;

        std::string user_file = NO_DATA;

        size = read_file(file, &memory);

        if (size == -1)
            return NULL_STR;

        if (size == 0)
            return USERS_FILE;

        if (assing_memory(&matrix_binaria, size) == ERROR)
        {
            cout << "No se pudo asignar memoria dinamica para la aplicación" << endl;
            return NULL_STR;
        }

        if (int_to_bynary_convert(memory, matrix_binaria, size) == ERROR)
        {
            cout << "No se pudo convertir los datos a binario" << endl;
            delete[] memory;
            return NULL_STR;
        }

        delete[] memory;

        if (!metodo(matrix_binaria, semilla, size, BITS_ON_BYTES))
        {
            cout << "Error al aplicar la operacion" << endl;
            delete_memory(&matrix_binaria, size);
            return NULL_STR;
        }

        memory = new uint8_t[size];

        if (memory == NULL)
        {
            cout << "Sin memoria disponible" << endl;
            delete_memory(&matrix_binaria, size);
            return NULL_STR;
        }

        binary_to_char(matrix_binaria, memory, size);
        delete_memory(&matrix_binaria, size);

        user_file = string((char *)memory);

        delete[] memory;

        return user_file;
    }

    bool validate_credentials(string &user, string &password, const string &file_string, bool admin, string &user_data)
    {
        istringstream stream(file_string);
        string line, new_line;

        while (getline(stream, line))
        {
            new_line = line;

            if (!admin)
                line = line.substr(0, line.find_last_of(','));

            if (line == user + "," + password)
            {
                user_data = new_line;
                return true;
            }
        }
        return false;
    }

    my_error_t crear_usuario (string &users_file) {
        
    }

}

my_error_t main_app_atm()
{
    uint16_t opcion;
    string user_data = NO_DATA;
    string admin_file = read_data(ADMIN_FILE, decypher_1, SEMILLA);
    string users_file = read_data(USERS_FILE, decypher_1, SEMILLA);

    if (admin_file.empty())
    {
        cout << "Error al leer el archivo de administradores" << endl;
        return ERROR;
    }

    if (users_file.empty())
    {
        users_file = NULL_STR;
    }

    do
    {
        cout << "1. Administrador\n2. Usuario\n3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "=========================" << endl;
            if (validar_usuario(admin_file, true, user_data))
            {
                cout << "=========================" << endl;

                app_administrador(users_file);
            }

            break;
        case 2:
            break;

        case 3:
            break;

        default:
            break;
        }
    } while (opcion != 3);

    return OK;
}

my_error_t validar_usuario(const string &file_string, bool admin, string &user_data)
{

    if (file_string.empty())
    {
        cout << "Error al leer el archivo" << endl;
        return ERROR;
    }

    string user_id;
    string pass;

    cout << "Ingrese usuario: ";
    cin >> user_id;

    cout << "Ingrese su contraseña: ";
    cin >> pass;

    if (validate_credentials(user_id, pass, file_string, admin, user_data))
    {
        cout << "Autentificación exitosa!\n";
        return OK;
    }
    else
    {
        cout << "Error de autentificación\n";
        return ERROR;
    }
}

void app_administrador(string &users_file)
{
    cout << "Bienvenido Administrador! \n";

    uint8_t opcion;

    do
    {
        std::cout << "1. Crear usuario\n2. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            
            break;
        
        default:
            break;
        }

    } while (opcion != 2);
}