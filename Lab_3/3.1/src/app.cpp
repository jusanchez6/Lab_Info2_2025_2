#include "app.hpp"


my_error_t app_main (char * argv[]) {
    my_error_t result;
    char *origen = argv[1];
    char *destino = argv[2];
    char *metodo = argv[3];
    int16_t semilla = atoi(argv[4]);

    if (semilla <= 0) {
        cerr << "Semilla invalida" << endl;
        return ERROR;
    }

    if (strcmp(metodo, "c1") == 0) {
        result = app(cypher_1, origen, destino, semilla);
    } else if (strcmp(metodo, "c2") == 0) {
        result = app(cypher_2, origen, destino, semilla);
    } else if (strcmp(metodo, "d1") == 0) {
        result = app(decypher_1, origen, destino, semilla);
    } else if (strcmp(metodo, "d2") == 0) {
        result = app(decypher_2, origen, destino, semilla);
    } else {
        cout << "Metodo no valido" << endl;
        result = ERROR;
    }
    
    if (result ==  ERROR) {
        cout << "Error en la aplicacion." << endl;
        return ERROR;
    }

    return OK;
}


my_error_t app (metodo_ptr metodo, char *origen, char *destino, uint8_t semilla) {
    uint8_t * memory;
    uint8_t ** matrix_binaria;
    int32_t size;

    size = read_file(origen, &memory);
    
    if (size == 0) 
        return ERROR;

    if (assing_memory(&matrix_binaria, size) == 0) {
        cout << "Error. No se pudo asignar memoria.\n";
        return ERROR;
    }

    if (int_to_bynary_convert(memory, matrix_binaria, size) == 0) {
        cout << "Error al convertir el contenido a binario" << endl;
        
        delete[] memory;
        delete_memory(&matrix_binaria, size);
        return ERROR;
    }


    delete[] memory;

    if (!metodo(matrix_binaria, semilla, size, BITS_ON_BYTES)) {
        cout << "Error aplicando el metodo requerido." << endl;
        delete_memory(&matrix_binaria, size);
        return ERROR;
    }

    memory = new uint8_t[size];

    if (memory == NULL) {
        cout << "Error, sin memoria disponible" << endl;
        delete_memory(&matrix_binaria, size);
        return ERROR;
    }

    binary_to_char(matrix_binaria, memory, size);

    cout << "Matrix binaria: " << endl;

    for (int i=0; i < size; i++)
        for (int j=0; j < BITS_ON_BYTES; j++) 
            std::cout << (int)matrix_binaria[i][j];
        
    std::cout << std::endl;
    delete_memory(&matrix_binaria, size);

    if (write_file(destino, memory, size) == ERROR) {
        cout << "Error al escribir el archivo destino." << endl;
        delete[] memory;
        return ERROR;
    }

    cout << "Archivo escrito" << endl;

     for (int i=0; i < size; i++) {
        std::cout <<(memory[i]);
    }

    delete[] memory;

    return OK;

}


int read_file(const char *filename, uint8_t ** memory) {
    
    int size;

    ifstream file(filename, ios::binary | ios::ate | ios::in);   // ate es util para saber el tamaño del archivo

    // Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        cout << "Error al abrir el archivo: " << filename << endl;
        return ERROR;
    } else {
        size = file.tellg();            // obtener el tamaño del archivo
        
        file.seekg(0, ios::beg);        // Volver a poner el puntero en inicio del archivo
        *memory = new uint8_t[size];    // Reservar la memoria necesaria para el archivo

        if (*memory == NULL) {
            cout << "Error. No se pudo reservar la memoria" << endl;
            file.close();
            return ERROR;
        }

        file.read((char *)*memory, size);       // Leer el archivo
        file.close();                           // cerrar el archivo
    }

    return size;
}


my_error_t assing_memory(uint8_t *** matrix_binaria, int size) {
    
    // 1. Reservamos memoria para un arreglo de punteros a uint8_t
    //    Cada elemento de este arreglo será una "fila" de la matriz binaria
    *matrix_binaria = new uint8_t *[size];

    // 2. Verificamos que la memoria se haya asignado correctamente
    if (*matrix_binaria == NULL) {
        cout << "Error. No se pudo asignar la memoria" << endl;
        return ERROR;
    }

    // 3. Para cada fila, asignamos memoria para un arreglo de uint8_t
    //    Cada fila tendrá BITS_ON_BYTES columnas (por ejemplo 8, si quieres representar 1 byte en binario)
    for (uint32_t i = 0; i < size; i++) {
        (*matrix_binaria)[i] = new uint8_t[BITS_ON_BYTES];
        
        // 4. Comprobamos que la memoria de esa fila se asignó bien
        if ((*matrix_binaria)[i] == NULL) {
            cout << "No se pudo asignar la memoria dinamica" << endl;
            return ERROR;
        }
    }

    // 5. Si todo salió bien, devolvemos OK
    return OK;
}


void delete_memory(uint8_t ***matrix_binaria, uint8_t size) {
    
    for (uint32_t i = 0; i < size; i++) {
        delete[] (*matrix_binaria)[i];
    }

    delete[] (*matrix_binaria);

}

my_error_t write_file(const char *filename, uint8_t *memory, int32_t size) {
    ofstream file (filename, ios::out|ios::binary);

    if (!file.is_open()) {
        cout << "Error al abrir el archivo en escritura" << filename << endl;
        return ERROR;
    }

    // que trate los datos como si fueran un const char (?) ok?
    file.write(reinterpret_cast<const char*>(memory), size);
    file.close();
    return OK;    

}

my_error_t int_to_bynary_convert(uint8_t *memory, uint8_t ** bin_matrix, uint size) {
    
    for (int i = 0; i < size; i++) {
        if (!int_to_binary(memory[i], bin_matrix[i]))
            return ERROR;
    }
    return OK;
}

void binary_to_char(uint8_t **matrix_binaria, uint8_t *memory, int32_t size) {
    
    for (uint32_t i=0; i < size; i++) {
        *(memory + i) = binary_to_int(*(matrix_binaria + i));
    }
    return;
}