#include "cypher_decypher.hpp"

namespace
{

    /**
     * @brief Compara la cantidad de ceros y unos en una matriz de bits.
     *
     * @param bits Matriz de bits a comparar.
     * @param n Número de filas en la matriz.
     *
     * @return EACH_ONE si hay igual cantidad de ceros y unos, EACH_TWO si hay más ceros, EACH_THREE si hay más unos.
     *
     */
    uint8_t compare_zeros_ones(uint8_t **bits, uint32_t n)
    {
        uint8_t zeros = 0, ones = 0;

        for (uint32_t i = 0; i < n; i++)
        {
            if (!(*bits[i]))
                zeros++;

            ones = n - zeros;
        }

        if (ones > zeros)
            return EACH_THREE;
        else if (ones < zeros)
            return EACH_TWO;
        else
            return EACH_ONE;
    }

    /**
     * @brief Cambia los bits en una matriz de bits cada m posiciones.
     *
     * @param n Número de filas en la matriz.
     * @param m Intervalo para cambiar los bits.
     * @param gropup Matriz de bits a modificar.
     *
     */
    void change_bits(uint32_t n, uint32_t m, uint8_t **grupo)
    {
        uint32_t bits = 0;

        for (uint32_t i = 0; i < n; i++)
        {
            bits++;
            if (bits == m)
            {
                *grupo[i] = !(*grupo[i]);
                bits = 0;
            }
        }
    }

}


/**
 * @brief Cifra una matriz de bits según un patrón específico.
 *
 * @param matrix Matriz de bits a cifrar.
 * @param n Número de bits en cada grupo.
 * @param rows Número de filas en la matriz.
 * @param cols Número de columnas en la matriz.
 *
 * @return true al terminar el cifrado.
 */
bool cypher_1(uint8_t **matrix, uint32_t n, uint32_t rows, uint32_t cols)
{

    uint8_t **grupo = new uint8_t *[n];
    uint8_t m, aux;
    uint32_t k = 0;

    m = EACH_ONE;

    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < cols; j++)
        {
            grupo[k++] = &matrix[i][j];

            if (k == n)
            {
                aux = compare_zeros_ones(grupo, n);
                change_bits(n, m, grupo);
                m = aux;
                k = 0;
            }
        }
    }

    if (k)
        change_bits(k, m, grupo);

    delete[] grupo;
    return true;
}
