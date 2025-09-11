#include <app_atm.hpp>
#include <app.hpp>
#include <string>


my_error_t main_app_atm()
{
    uint16_t opcion;
    string user_data = NO_DATA;
    string admin_file = read_data(ADMIN_FILE, decypher_1, SEMILLA);
    string users_file = read_data(USERS_FILE, decypher_1, SEMILLA);

    if (admin_file ==  NO_DATA)
        admin_file = NULL_STR;
    
    if (admin_file.empty())
    {
        cout << "Error al leer el archivo de administradores" << endl;
        return ERROR;
    }

    if (users_file.empty())
    {
        cout << "Error al leer el archivo de usuarios" << endl;
        return ERROR;
    }

    if (users_file == NO_DATA)
        users_file = NULL_STR;

    do
    {
        cout << "=========================" << endl;
        cout << "1. Administrador\n2. Usuario\n3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            opcion = 0;
        }

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
            cout << "=========================" << endl;
            if (validar_usuario(users_file, false, user_data))
            {
                cout << "=========================" << endl;

                app_usuarios(users_file, user_data);
            }
            break;

        case 3:
            cout << "Salir.\n";
            cout << "=========================" << endl;
            break;

        default:
            cout << "Opción invalida.\n";
            break;
        }
    } while (opcion != 3);

    return OK;
}

string read_data(const char *file, metodo_ptr metodo, uint32_t semilla)
{
    uint8_t *memory;
    uint8_t **matrix_binaria;
    uint32_t size;

    std::string user_file = NO_DATA;

    size = read_file(file, &memory);

    if (size == -1){
        cout << "Error, No se pudo abrir el archivo\n";
        return NULL_STR;
        
    }
    if (size == 0)
        return user_file;

    if (assing_memory(&matrix_binaria, size) == ERROR)
    {
        cout << "Error. No se pudo asignar memoria dinamica para la aplicación" << endl;
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
        cout << "Error. Sin memoria disponible" << endl;
        delete_memory(&matrix_binaria, size);
        return NULL_STR;
    }

    binary_to_char(matrix_binaria, memory, size);
    delete_memory(&matrix_binaria, size);

    user_file = string((char *)memory);

    delete[] memory;

    return user_file;
}

my_error_t write_data(const char *data_file, metodo_ptr metodo, uint32_t semilla, string &file_string)
{
    uint8_t *memory;
    uint8_t **matrix_binaria;
    int32_t size = file_string.size();

    if (size == 0)
    {
        cout << "Sin datos para escribir.\n";
        return ERROR;
    }

    memory = new uint8_t[size];

    if (memory == NULL)
    {
        cout << "Error, sin memoria disponible" << endl;
        return ERROR;
    }

    copy(file_string.begin(), file_string.end(), memory);

    if (assing_memory(&matrix_binaria, size) == ERROR)
    {
        cout << "Error, sin memoria disponible" << endl;
        return ERROR;
    }

    if (!int_to_bynary_convert(memory, matrix_binaria, size))
    {
        cout << "Error. No se pudo convertir el contenido a binario.\n";
        delete[] memory;
        delete_memory(&matrix_binaria, size);
        return ERROR;
    }

    delete[] memory;

    if (!metodo(matrix_binaria, semilla, size, BITS_ON_BYTES))
    {
        cout << "Error al cifrar los datos.\n";
        delete_memory(&matrix_binaria, size);
        return ERROR;
    }

    binary_to_char(matrix_binaria, memory, size);
    delete_memory(&matrix_binaria, size);

    ofstream file_out(data_file, ios::binary | ios::trunc);

    if (!file_out.is_open())
    {
        cout << "Error. No se pudo abrir el archivo de escritura.\n";
        delete[] memory;
        return ERROR;
    }

    file_out.write((char *)memory, size);
    file_out.close();

    return OK;
}

bool validate_credentials(string &user, string &password, const string &file_string, bool admin, string &user_data)
{
    istringstream stream(file_string);
    string line;

    cout << "Revisando credenciales\n";

    while (getline(stream, line))
    {
        string temp_line = line;

        // Si es usuario normal, solo comparamos la cedula + contraseña
        if (!admin)
            line = line.substr(0, line.find_last_of(','));

        if (line == user + "," + password)
        {
            // Asignamos user_data correctamente con la línea original del archivo
            user_data = temp_line;
            cout << "Usuario encontrado: " << user_data << "\n";
            return true;
        }
    }

    return false;
}


bool is_number(const string &str_number)
{
    for (char c : str_number)
        if (!isdigit(c))
            return false;
    return true;
}

bool new_user_check(const string user_data, string &id)
{

    istringstream stream(user_data);
    string line;

    while (getline(stream, line))
    {
        if (line.substr(0, line.find(',')) == id)
        {
            cout << "El usuario ya se encuentra registrado.\n";
            return false;
        }
    }
    return true;
}

my_error_t crear_usuario(string &users_file)
{
    string id;
    string pass;
    string str_saldo;
    string new_user;
    int32_t saldo;

    cout << "Ingrese la cedula: ";
    cin >> id;
    cout << "Ingrese la contraseña: ";
    cin >> pass;
    cout << "Ingrese el saldo del nuevo usuario: ";
    cin >> saldo;

    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error. Ingrese todos los campos.\n";
        return ERROR;
    }

    if (saldo < 0)
    {
        cout << "Error. El saldo debe ser positivo.\n";
        return ERROR;
    }

    if (!is_number(id) | !is_number(to_string(saldo)))
    {
        cout << "Error. El saldo y el usuario deben ser numericos.\n";
        return ERROR;
    }

    if (id.empty() || pass.empty()) {
        cout << "Error. Todos los campos son obligatorios.\n";
        return ERROR;
    }

    if (!new_user_check(users_file, id))
        return ERROR;

    new_user = id + ',' + pass + ',' + to_string(saldo) + '\n';
    users_file += new_user;

    cout << users_file << endl;

    if (!write_data(USERS_FILE, cypher_1, SEMILLA, users_file))
    {
        cout << "Error al escribir en el archivo.\n";
        return ERROR;
    }

    return OK;
}

my_error_t consultar_saldo(string &file_string, string &user)
{
    string id   = user.substr(0, user.find(','));
    string pass = user.substr(user.find(',') + 1, user.find_last_of(',') - user.find(',') - 1);
    uint32_t saldo = stoi(user.substr(user.find_last_of(',') + 1));

    // Cobro de 1000 por consulta
    if (saldo < 1000)
    {
        cout << "Error. Saldo insuficiente para consulta\n";
        return ERROR;
    }

    saldo -= 1000;
    cout << "Saldo disponible (descontando 1000 por consulta): " << saldo << endl;

    // Actualizamos user y archivo
    string new_user = id + "," + pass + "," + to_string(saldo);
    file_string.replace(file_string.find(user), user.length(), new_user);
    
    if (write_data(USERS_FILE, cypher_1, SEMILLA, file_string) == ERROR)
    {
        cout << "Error al actualizar el saldo\n";
        return ERROR;
    }

    user = new_user;
    return OK;
}



my_error_t retirar(string &file_string, string &user)
{
    string id   = user.substr(0, user.find(','));
    string pass = user.substr(user.find(',') + 1, user.find_last_of(',') - user.find(',') - 1);
    int32_t saldo = stoi(user.substr(user.find_last_of(',') + 1));

    int32_t retiro;
    cout << "Ingrese el saldo a retirar: ";
    cin >> retiro;

    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error. Entrada inválida\n";
        return ERROR;
    }

    if (retiro <= 0) {
        cout << "Error. El monto a retirar debe ser mayor a 0.\n";
        return ERROR;
    }

    if (retiro > saldo) {
        cout << "Error. El monto a retirar es mayor al saldo disponible.\n";
        return ERROR;
    }

    saldo -= retiro;
    cout << "Retiro por: " << retiro << endl;

    string new_user = id + "," + pass + "," + to_string(saldo);
    size_t pos = file_string.find(user);
    if (pos != string::npos)
        file_string.replace(pos, user.length(), new_user);
    else {
        cout << "Error interno: usuario no encontrado en archivo\n";
        return ERROR;
    }

    user = new_user;

    if (write_data(USERS_FILE, cypher_1, SEMILLA, file_string) == ERROR) {
        cout << "Error al actualizar el saldo\n";
        return ERROR;
    }

    return OK;
}


// ==========================================================================================
// ==========================================================================================
// ==========================================================================================



my_error_t validar_usuario(const string &file_string, bool admin, string &user_data)
{

    if (file_string.empty())
    {
        cout << "Error al leer el archivo" << endl;
        return ERROR;
    }

    string user_id;
    string pass;

    cout << "Ingrese usuario:";
    cin >> user_id;

    cout << "Ingrese su contraseña:";
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
    cout << "=========================" << endl;
    cout << "Bienvenido Administrador! \n";

    int opcion;

    do
    {
        std::cout << "1. Crear usuario\n2. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            opcion = 0;
        }

        switch (opcion)
        {
        case 1:
            cout << "=========================" << endl;
            cout << "Crear Usuario\n";
            if (crear_usuario(users_file) == ERROR)
            {
                cout << "Error. No se pudo crear el usuario.\n";
            }
            else
            {
                cout << "Nuevo usuario creado con exito.\n";
            }
            break;

        case 2:
            cout << "=========================" << endl;
            cout << "Salir\n";
            break;

        default:
            cout << "Opción invalida.\n";
            break;
        }

    } while (opcion != 2);
}

void app_usuarios(string &file_string, string &user)
{
    cout << "=========================" << endl;
    std::cout << "Bienvenido usuario\n";
    cout << "=========================" << endl;
    uint16_t opcion;
    do
    {
        std::cout << "1. Consultar saldo\n2. Retirar\n3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "=========================" << endl;
            std::cout << "Consultar saldo\n";
            consultar_saldo(file_string, user);
            break;
        case 2:
            cout << "=========================" << endl;
            std::cout << "Retirar\n";
            retirar(file_string, user);
            break;
        case 3:
            cout << "=========================" << endl;
            std::cout << "Salir\n";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}