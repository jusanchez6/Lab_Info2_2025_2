/**
 * @file main.cpp
 * @brief Conjunto de ejercicios en C++ para práctica de programación.
 *
 * Este programa implementa varios problemas de lógica, matemáticas y manejo de cadenas.
 * Incluye ejemplos de uso de arreglos, matrices, funciones recursivas e iterativas,
 * así como interacción con el sistema (abrir simulaciones en Tinkercad).
 *
 * Cada problema corresponde a un ejercicio independiente y está diseñado
 * para reforzar conceptos fundamentales de programación en C++.
 *
 * @author Julian Sanchez
 * @date 2025-08-28
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define T_MAX 20 // Tamaño máximo de la matriz para el problema 12
#define N_p14 5  // Tamaño del arreglo para el problema 14


// ==================================================================================
// ============================ FUNCIONES DE APOYO ==================================
// ==================================================================================

/**
 * @brief Funcion corregida
 *
 * El error en la función brindada es que a pesar de que pasan
 * los valores por referencia pero se trata como si fuera entregado por
 * valor
 */
void func_c(double *a, int n, double *promedio, double *suma)
{
    int i;
    *suma = 0.0;

    for (i = 0; i < n; i++)
        *suma += a[i];

    *promedio = *suma / n;
}

/**
 * @brief Convierte manualmente una cadena de caracteres a número entero.
 *
 * @param cadena Cadena que contiene dígitos numéricos.
 * @return Entero equivalente o 0 en caso de error.
 *
 * @warning Si la cadena contiene caracteres no numéricos, se devuelve 0.
 */
int ConvertirCadena(const string &cadena)
{
    int numero = 0;
    for (char c : cadena)
    { // Esto es una forma elegante de iterar en una cadena que no conocia
        if (c >= '0' && c <= '9')
        {
            numero = numero * 10 + (c - '0'); // se resta '0' para normalizar y se multiplica por 10 para correr el numero
        }
        else
        {
            cout << "Error en la cadena" << endl;
            return 0;
        }
    }
    return numero;
}

/**
 * @brief Convierte un carácter romano a su valor numérico.
 *
 * @param c Carácter en notación romana.
 * @return Valor entero correspondiente o 0 si no es válido.
 */
int conversor(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0; // Carácter no válido
    }
}

/**
 * @brief Verifica si una matriz cuadrada es mágica
 *
 * Una matriz es mágica si todas sus filas, columnas y diagonales
 * suman lo mismo.
 *
 * @param[in] matriz Matriz de enteros
 * @param[in] n Dimensión de la matriz
 * @return true si es mágica, false en caso contrario
 */
bool esMagica(int matriz[T_MAX][T_MAX], int n)
{
    int sumaFila = 0, sumaColumna = 0;
    int sumaDiagonal1 = 0, sumaDiagonal2 = 0;

    // Calcular sumas de las diagonales para tener una referencia
    for (int i = 0; i < n; i++)
    {
        sumaDiagonal1 += matriz[i][i];
        sumaDiagonal2 += matriz[i][n - i - 1];
    }

    // Verificar sumas de filas y columnas
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumaFila += matriz[i][j];
            sumaColumna += matriz[j][i];
        }

        // unico if para comparar todas las sumas
        if (sumaDiagonal1 != sumaDiagonal2 || sumaDiagonal1 != sumaFila || sumaDiagonal1 != sumaColumna)
        {
            return false;
        }
        sumaFila = 0;
        sumaColumna = 0;
    }

    return true;
}

/**
 * @brief Rota una matriz cuadrada 90 grados
 *
 * Implementa una rotación de 90° en sentido horario de una matriz NxN.
 *
 * @param[in] matriz Matriz original
 * @param[out] rotada Matriz rotada
 */
void rotar90(int matriz[N_p14][N_p14], int rotada[N_p14][N_p14])
{
    for (int i = 0; i < N_p14; i++)
    {
        for (int j = 0; j < N_p14; j++)
        {
            rotada[j][N_p14 - 1 - i] = matriz[i][j];
        }
    }
}

/**
 * @brief Imprime una matriz en consola
 *
 * @param[in] M Matriz a imprimir
 */
void imprimirMatriz(int M[N_p14][N_p14])
{
    for (int i = 0; i < N_p14; i++)
    {
        for (int j = 0; j < N_p14; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

/**
 * @brief Calcula el factorial de un número entero
 *
 * @param[in] x Número entero
 * @return Factorial de x
 */
long long factorial(int x)
{
    long long resultado = 1;
    for (int i = 2; i <= x; i++)
    {
        resultado *= i;
    }
    return resultado;
}

/**
 * @brief Calcula la n-ésima permutación de los dígitos 0-9
 *
 * Utiliza el método de factorización en posiciones (factoradic)
 * para determinar la permutación sin necesidad de generar todas.
 *
 * @param[in] n Número de permutación (1 <= n <= 10!)
 * @param[out] result Cadena con la permutación obtenida
 */
void nPer(long long n, char result[])
{
    const int N = 10; // Digitos del 0 al 9
    char digits[N + 1] = "0123456789";
    long long k = n - 1;
    int pos = 0;
    
    for (int i = N; i >= 1; i--)
    {
        long long fact = factorial(i-1);
        int idx = k / fact;
        k %= fact;

        result[pos++] = digits[idx];

        for (int j = idx; j < N - 1; j++)
        {
            digits[j] = digits[j + 1];
        }
    }

    result[pos] = '\0'; // Null-terminar la cadena

}


// ==================================================================================
// ============================ EJERCICIOS Y PROBLEMAS ==============================
// ==================================================================================



/**
 * @brief Función de caso de prueba para la corrección de la función fun_c
 *
 */
void ejercicio_2(void)
{
    double datos[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int n = 5;
    double promedio, suma;

    func_c(datos, n, &promedio, &suma);

    cout << "Suma:" << suma << endl;
    cout << "Promedio:" << promedio << endl;
}

/**
 * @brief Ejercicio 4: Abre en el navegador la simulación de thinkercad
 *
 * La simulación que se abre muestra como se puede variar la intensidad de un
 * LED mediante la lectura analógica de un potenciometro
 *
 */
void ejercicio_4(void)
{
    string url = "https://www.tinkercad.com/things/dFCu7UutNep-ejercicio4";

    cout << "Abriendo la simulación de Arduino en thinkercad..." << endl;
    string command = "xdg-open " + url + " &";
    system(command.c_str());
}

/**
 * @brief Genera un arreglo aleatorio de 200 letras mayúsculas y cuenta las frecuencias
 */
void problema_2(void)
{

    const int N = 200; // Tamaño del arreglo
    char arreglo[N];
    int contador[26] = {0};

    srand(time(0)); // Genera valores aleatorios pero de verdad

    for (int i = 0; i < N; i++)
    {
        arreglo[i] = 'A' + (rand() % 26); // 26 es por el numero de letras en el abecedario
        contador[arreglo[i] - 'A']++;     // Resta 'A' para normalizar el contador
    }

    for (int i = 0; i < N; i++)
    {
        cout << arreglo[i]; // Imprime la cadena
    }

    cout << endl;

    for (int i = 0; i < 26; i++)
    {
        if (contador[i] > 0)
        {
            cout << char('A' + i) << ": " << contador[i] << endl;
        }
    }
}


/**
 * @brief Pide al usuario un número en cadena y lo convierte a entero
 */
void problema_4(void)
{
    string cadena;
    cout << "Ingrese un numero entero positivo: ";
    cin >> cadena;

    int numero = ConvertirCadena(cadena);
    if (numero != 0)
    {
        cout << "El numero es: " << numero << endl;
    }
}

/**
 * @brief Convierte un texto ingresado a mayúsculas
 *
 * @param[in] arduino Si es true, abre también la simulación de Tinkercad correspondiente.
 */
void problema_6(bool arduino = false)
{
    string texto;

    cout << "Ingrese un texto: ";
    getline(cin, texto);

    string mayuscula = texto; // copia del texto original

    for (char &c : mayuscula)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = c - 'a' + 'A'; // al restar a se halla el indice de la letra y al sumarle A se halla la letra
        }
    }

    cout << "Original: " << texto << endl;
    cout << "En mayuscula: " << mayuscula << endl;

    if (arduino)
    {
        string url = "https://www.tinkercad.com/things/kutuTuhdpOZ-problema-6?sharecode=LWKx6Swrzji1WUXdT8BpVI5435CQSqp2NA1xf-ccmK0";

        cout << "Abriendo la simulación de Arduino en thinkercad..." << endl;
        string command = "xdg-open " + url + " &";
        system(command.c_str());
    }
}

/**
 * @brief Separa una cadena en letras y números
 */
void problema_8(void)
{
    string entrada;
    string texto = "";
    string numeros = "";

    cout << "Ingrese la cadena de texto: ";
    getline(cin, entrada);

    for (char c : entrada)
    {
        if (c >= '0' && c <= '9')
        {
            numeros += c;
        }
        else
        {
            texto += c;
        }
    }

    cout << "Original: " << entrada << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numeros << endl;
}

/**
 * @brief Convierte un número romano a decimal
 */
void problema_10(void)
{
    string entrada;
    cout << "Ingrese un numero romano en MAYUSCULA: ";
    getline(cin, entrada);

    int total = 0;
    int n = entrada.length();

    for (int i = 0; i < n; i++)
    {
        int valor = conversor(entrada[i]);

        if (i + 1 < n && valor < conversor(entrada[i + 1]))
        {
            total -= valor; // Resta si el valor actual es menor que el siguiente
        }
        else
        {
            total += valor; // Suma en caso contrario
        }
    }

    cout << "El numero ingresado fue: " << entrada << endl;
    cout << "Que corresponde a: " << total << endl;
}


/**
 * @brief Verifica si una matriz ingresada por el usuario es mágica
 */
void problema_12(void)
{
    int n;
    int matriz[T_MAX][T_MAX];

    cout << "Ingrese el numero de filas (max " << T_MAX << "): ";
    cin >> n;

    if (n > T_MAX)
    {
        cout << "Tamaño excede el máximo permitido." << endl;
        return;
    }

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Fila " << i + 1 << ": " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    if (esMagica(matriz, n))
    {
        cout << "La matriz es mágica." << endl;
    }
    else
    {
        cout << "La matriz no es mágica." << endl;
    }
}

/**
 * @brief Rota una matriz 5x5 en 90°, 180° y 270° grados
 */
void problema_14(void)
{

    int matriz[N_p14][N_p14];
    int rot90[N_p14][N_p14], rot180[N_p14][N_p14], rot270[N_p14][N_p14];

    int valor = 1;

    // Inicialización de la matriz
    for (int i = 0; i < N_p14; i++)
    {
        for (int j = 0; j < N_p14; j++)
        {
            matriz[i][j] = valor++;
        }
    }

    // Rotación 90 grados
    rotar90(matriz, rot90);
    // Rotación 180 grados
    rotar90(rot90, rot180);
    // Rotación 270 grados
    rotar90(rot180, rot270);

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);
    cout << "\nMatriz rotada 90 grados:" << endl;
    imprimirMatriz(rot90);
    cout << "\nMatriz rotada 180 grados:" << endl;
    imprimirMatriz(rot180);
    cout << "\nMatriz rotada 270 grados:" << endl;
    imprimirMatriz(rot270);
    cout << endl;
}

/**
 * @brief Calcula el número de rutas posibles en una malla NxN
 *
 * Dos métodos disponibles:
 * - Directo con factorial
 * - Optimizado con multiplicaciones sucesivas
 *
 * @param[in] optimizado Si es true, usa el método optimizado.
 */
void problema_16(bool optimizado = false)
{
    int n;
    cout << "Ingrese el tamaño de la malla (n): ";
    cin >> n;

    if (optimizado)
    {
        long long rutas = 1;
        for (int i = 0; i < n; i++)
        {
            rutas = rutas * (2 * n - i) / (i + 1);
        }
        cout << "Número de rutas posibles en una malla de " << n << "x"
             << n << " (método optimizado): " << rutas << endl;
    }
    else
    {
        long long rutas = factorial(2 * n) / (factorial(n) * factorial(n));
        cout << "Número de rutas posibles en una malla de " << n << "x"
             << n << ": " << rutas << endl;
    }
}


/**
 * @brief Imprime la n-ésima permutación de los dígitos 0-9
 */
void problema_18(void )
{
    long long n;
    cout << "Ingrese n ( 1 <= n <= 3628800): ";
    cin >> n;

    long long max_n = factorial(10);
    if (n < 1 || n > max_n)
    {
        cout << "n debe estar entre 1 y " << max_n << endl;
        return;
    }

    char result[11]; // 10 dígitos + null terminator
    nPer(n, result);
    cout << "La " << n << " permutación es: " << result << endl;

    
}


// ==================================================================================
// ==================================== MAIN ========================================
// ==================================================================================

/**
 * @brief Función principal
 *
 * Punto de entrada del programa. Actualmente ejecuta problema_18.
 *
 * @return 0 si la ejecución fue exitosa
 */
int main()
{
    cout << "Hello, World!" << endl;
    problema_16(true);
    return 0;
}
