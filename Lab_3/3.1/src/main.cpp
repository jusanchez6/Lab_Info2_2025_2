#include <iostream>

#include <cassert>
#include "binary_numbers.hpp"
#include "cypher_decypher.hpp"
#include <iostream>
#include <string>
#include <cstdint>
#include <cassert>

// Declaración (la función la tienes implementada en otro archivo)
bool cypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols);

int main() {
    // Entrada y esperado (para método 1 debería ser 10110100001111010001011010011011)
    std::string input    = "01000001011000100100001101100100";
    std::string expected = "10110100001111010001011010011011";  
    int n = 4;
    int rows = 1;
    int cols = input.size();

    // Crear matriz dinámica de 1xN
    uint8_t **matrix = new uint8_t*[rows];
    matrix[0] = new uint8_t[cols];

    // Copiar bits
    for (int j = 0; j < cols; j++) {
        matrix[0][j] = (input[j] == '1') ? 1 : 0;
    }

    // 🔎 Imprimir la matriz de entrada
    std::cout << "Matriz de entrada (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << (int)matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Ejecutar cifrado
    cypher_1(matrix, n, rows, cols);

    // Reconstruir string de salida
    std::string result;
    for (int j = 0; j < cols; j++) {
        result.push_back(matrix[0][j] ? '1' : '0');
    }

    // Mostrar y verificar
    std::cout << "Resultado: " << result << std::endl;
    assert(result == expected && "El resultado del cifrado NO coincide con lo esperado");

    std::cout << "✅ Test pasado: la salida es correcta." << std::endl;

    // Liberar memoria
    delete[] matrix[0];
    delete[] matrix;

    return 0;
}
