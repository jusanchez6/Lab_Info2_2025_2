#include <iostream>
#include "app.hpp"



int main(int argc, char * argv[])
{
    if (argc != 5)
    {
        std::cerr << "Uso: " << argv[0] << " [origen] [destino] [metodo] [semilla]" << std::endl;
        return -1;
    }

    if (app_main(argv) == ERROR)
    {
        std::cerr << "Error en la aplicación" << std::endl;
        return -1;
    }

    return 0;
}
