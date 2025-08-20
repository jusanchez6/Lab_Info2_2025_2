# Laboratorio 1 - Informática II

## Introducción

Como primer laboratorio de la asignatura de **Informática II**, se propone la implementación de un conjunto de ejercicios en C++ que permiten reforzar conceptos básicos de programación, incluyendo el uso de condicionales, bucles, funciones, validación de datos, manejo de cadenas numéricas y operaciones matemáticas.

Este proyecto no se centra en un único algoritmo, sino en la resolución de diferentes problemas clásicos que ayudan al estudiante a mejorar sus habilidades de análisis y codificación. El archivo principal, `main.cpp`, contiene la implementación de todos los ejercicios y problemas propuestos.

## Detalles del Programa

- Cada función representa un ejercicio o problema independiente.
- Se incluyen operaciones matemáticas como factoriales, potencias, verificación de primos y aproximaciones numéricas.
- Se abordan problemas de manipulación de números, validación de datos y manejo de estructuras de control.
- Todo el código está documentado en formato Doxygen para facilitar la comprensión y el mantenimiento.

## Problemas Implementados
1. **Problema 2**: Descomposición de un valor en billetes y monedas de {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50}.
2. **Problema 4**: Suma de tiempos en formato HHMM
3. **Problema 6**: Aproximación del número de Euler mediante series
4. **Problema 8**: Suma de múltiplos evitando duplicados
5. **Problema 10**: Enésimo número primo
6. **Problema 12**: Máximo factor primo de un número
7. **Problema 14**: Mayor palíndromo producto de números de 3 dígitos
8. **Problema 16**: Serie de Collatz - semilla que genera la serie más larga

## Compilación y Ejecución

```bash
# Compilar con g++
mkdir build
cd build 
cmake ..
make


# Ejecutar el programa
./Lab_1
```

## Requisitos

- Compilador compatible con **C++17** o superior
- Sistema operativo: Windows, Linux o macOS

## Estructura del Proyecto

```
├── main.cpp                # Código fuente principal con todos los problemas
├── README.md               # Documentación
└── CMakeLists.txt          # Archivos de configuración de cmake
```

## Autor

- **Nombre**: Julian Mauricio Sanchez Ceballos
- **Asignatura**: Informática II
- **Fecha**: 20/08/2025
- **Versión**: 1.0
