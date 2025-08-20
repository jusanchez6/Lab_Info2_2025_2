#include <iostream>
#include <cstdlib>


/**
 * @file main.cpp
 * @brief Conjunto de ejercicios de práctica en C++.
 *
 * Este programa agrupa varias funciones (ejercicios y problemas) 
 * que resuelven tareas clásicas de programación: operaciones matemáticas,
 * validación de datos, cálculos iterativos, manipulación de cadenas numéricas, etc.
 *
 * Cada función es independiente y puede ejecutarse por separado para probar
 * un problema específico.
 *
 * @author Julian Sanchez
 * @date 2025
 */

// ====================================================================================================
// ===================================== EJERCICIOS ====================================================
// ====================================================================================================


/**
 * @brief Determina si un número ingresado es par o impar.
 * 
 * Solicita al usuario un número entero y muestra en pantalla si es par o impar.
 */
void ejercicio_2 (void) {     
    std::cout << "Introduce un numero: ";     
    int number;          
    std::cin >> number;      

    if (number % 2 == 0)         
        std::cout << number << " es par\n" << std::endl;     
    else         
        std::cout << number << " es impar\n" << std::endl; 
}

/**
 * @brief Encuentra el menor de dos números enteros.
 * 
 * Pide dos números al usuario y muestra cuál de los dos es menor.
 */
void ejercicio_4 (void) {     
    std::cout << "Introduce el primer numero: ";     
    int number_1;     
    std::cin >> number_1;      

    std::cout << "Introduce el segundo numero: ";     
    int number_2;     
    std::cin >> number_2;      

    if (number_1 > number_2)         
        std::cout << "El menor es " << number_2 << std::endl;      
    else         
        std::cout << "El menor es " << number_1 << std::endl;  
}

/**
 * @brief Calcula la potencia A^B de forma iterativa.
 * 
 * Solicita dos números enteros A y B y calcula A elevado a la potencia B.
 */
void ejercicio_6 (void) {     
    std::cout << "Introduce el numero A: ";     
    int A;     
    std::cin >> A;      

    std::cout << "Introduce el numero B: ";     
    int B;     
    std::cin >> B;          

    int result = A;      

    for (int i = 1; i < B; i++) {         
        result = result * A;     
    }      

    std::cout << A << "^" << B << " = " << result << std::endl;  
}

/**
 * @brief Calcula el factorial de un número entero.
 * 
 * Solicita un número entero al usuario y calcula su factorial de forma iterativa.
 * Ejemplo: 5! = 120
 */
void ejercicio_8 (void) {     
    std::cout << "Ingrese un numero entero: " << std::endl;     
    int number;     
    std::cin >> number;     

    int result = 1;          
    for (int i = 1; i <= number; i++) {         
        result = result * i;     
    }      

    std::cout << number << "! = " << result << std::endl;  
}

/**
 * @brief Muestra todos los múltiplos de N menores o iguales a 100.
 * 
 * Solicita un número N e imprime en pantalla sus múltiplos hasta 100.
 */
void ejercicio_10 (void) {     
    std::cout << "Ingrese un numero " << std::endl;     
    int N;     
    std::cin >> N;      

    std::cout << "Multiplos de " << N << " menores o iguales a 100: " << std::endl;      

    for (int i = N; i <= 100; i += N) {         
        std::cout << i << std::endl;     
    }  
}

/**
 * @brief Muestra las potencias de un número de 1 a 5.
 * 
 * Solicita un número N y calcula N^1, N^2, ..., N^5.
 * @warning Actualmente la función solo multiplica N*i en lugar de calcular N^i.
 */
void ejercicio_12 (void) {     
    std::cout << "Ingrese un numero: " << std::endl;     
    int N;     
    std::cin >> N;      

    int result = 1;
    for (int i = 1; i <= 5; i++) {      
        result *= N;  // Multiplicación iterativa para simular potencia   
        std::cout << N << "^" << i << " = " << result << std::endl;     
    }      
}

/**
 * @brief Imprime en dos columnas números en orden ascendente y descendente.
 * 
 * Genera pares (i, 51-i) desde i=1 hasta 50.
 */
void ejercicio_14 (void ) {
    for(int i = 1; i<=50; i++){
        std::cout << i << "\t" << 51 - i << std::endl;
    }
}


/**
 * @brief Calcula el promedio de una serie de números ingresados por el usuario.
 * 
 * El ingreso termina cuando se introduce el valor 0. 
 */
void ejercicio_16 (void ) {
    int num = 0;
    int suma = 0;
    int contador = 0;

    std::cout << "Ingrese numeros (0 para terminar) " << std::endl;
    
    while (true) {
        std::cin >> num;

        if (num == 0)
            break;

        suma += num;
        contador++;
    }

    if (contador > 0) {
        double promedio = static_cast<double>(suma) / contador;
        std::cout << "El promedio es " << promedio << std::endl;
    } else {
        std::cout << "Entrada invalida" << std::endl;
    }
}

/**
 * @brief Verifica si un número es un cuadrado perfecto.
 * 
 * Recorre posibles raíces cuadradas y comprueba si alguna satisface i^2 == N.
 */
void ejercicio_18 (void ) {
    int N;

    std::cout << "Ingrese un numero" << std::endl;
    std::cin >> N;

    bool cuadrado = false;

    for (int i = 1; i * i <= N; i++){
        if (i*i == N) {
            cuadrado = true;
            break;
        }
    }

    if(cuadrado)
        std::cout << N << " Es un numero cuadrado" << std::endl;
    else
        std::cout << N << " No es un numero cuadrado" << std::endl;
}

/**
 * @brief Determina si un número entero es palíndromo.
 * 
 * Invierte los dígitos y los compara con el original.
 */
void ejercicio_20 (void ){

    int N;
    std::cout << "Ingrese un numero: " << std::endl;
    std::cin >> N;

    int original = N;
    int invertido = 0;

    while (N > 0){
        int digito = N % 10;                        // Obtener el ultimo digito
        invertido = invertido * 10 + digito;        // Lo sumo al invertido (siempre inicia por las unidades porque lo inicialize en 0)
        N = N/10;                                   // Division entera para eliminar el ultimo digito del numero original 
    }
    
    if (invertido == original)
        std::cout << original << " Es palindromo" << std::endl;
    else
        std::cout << original << " No es palindromo" << std::endl;
}

/**
 * @brief Convierte segundos a formato HH:MM:SS.
 * 
 * Divide y toma restos sucesivos para calcular horas, minutos y segundos.
 */
void ejercicio_22 (void ) {
    int segundos;

    std::cout << "Ingrese el numero de segundos " << std::endl;
    std::cin >> segundos;

    int hor = segundos / 3600;
    int res = segundos % 3600;
    int min = res/ 60;
    int seg = res % 60;


    std::cout << hor << ":" << min << ":" << seg << std::endl;
    
    //std::cout << segundos/3600 << ":" << (segundos % 3600) / 60 << ":" << segundos % 60 << std::endl;
}

/**
 * @brief Dibuja un cuadrado hueco con caracteres '+'.
 * 
 * Solicita el tamaño N y dibuja solo el contorno.
 */
void ejercicio_24 (void ) {
    int N;
    std::cout << "Ingrese el numero de filas del cuadrado: " << std::endl;
    std::cin >> N;

    for (int i = 0; i < N; i++) {                                   // filas del cuadrado 
        for (int j = 0; j < N; j++){                                // columnas del cuadrado
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)       // solo quiero escribir en la primera/ultima columna y fila
                std::cout << "+";
            else
                std::cout << " ";
        }
        std::cout << "\n";                                          // salto de linea al final de la fila             
    }

} 


/**
 * @brief Clasifica un triángulo según sus lados.
 * 
 * Verifica primero si los lados cumplen con la desigualdad triangular,
 * y luego determina si es equilátero, isósceles o escaleno.
 */
void ejercicio_26 (void) {
    int a, b, c;
    std::cout << "Ingrese tres numeros (lados del triangulo): ";
    std::cin >> a >> b >> c;

    // Verificacion mediante la desigualdad triangulasr
    if (a + b > c && a + c > b && b + c > a) {

        if (a == b && b == c)
            std::cout << "Se forma un triangulo equilatero" << std::endl;
        else if (a == b || a == c || b == c)
            std::cout << "Se forma un triangulo isosceles" << std::endl;
        else
            std::cout << "Se forma un triangulo escaleno" << std::endl;
    }
    else
        std::cout << "Las longitudes ingresadas no forman un triangulo" << std::endl;
}

/**
 * @brief Aproxima el valor de PI usando la serie de Leibniz.
 * 
 * PI = 4 * (1 - 1/3 + 1/5 - 1/7 + ...).
 */
void ejercicio_28 (void ){
    int N;
    std::cout << "Ingrese el numero de elementos para la aproximacion: ";
    std::cin >> N;

    double pi = 0.0;
    int signo = 1;

    for (int i = 0; i < N; i++) {
        int denominador = 2 * i + 1;        // que sea siempre impar
        pi += signo *(1 / denominador);     // suma de la serie
        signo *= -1;                        // cambio de signo 
    }
    
    pi *= 4;

    std::cout << "Pi es aproximadamente: " << pi << std::endl;
}


/**
 * @brief Juego de adivinar un número aleatorio.
 * 
 * Genera un número aleatorio en [0,100] y el usuario debe adivinarlo.
 * Muestra pistas "mayor" o "menor" en cada intento.
 */
void ejercicio_30 (void ){
    int A = rand() % 101;
    int B;
    int intentos = 0;

    std::cout << "Ingresa el numero: " << std::endl;

    do {
        std::cin >> B;
        intentos++;
    
        if (B < A)
            std::cout << "El numero es mayor" << std::endl;
        else if (B > A)
            std::cout << "El numero es menor" << std::endl;
        else
            std::cout << "Correcto, Intentos: " << intentos << " El numero era: " << A << std::endl;
    } while (B != A);

}

// ====================================================================================================
// ===================================== PROBLEMAS ====================================================
// ====================================================================================================


/**
 * @brief Descompone una cantidad de dinero en denominaciones.
 * 
 * Utiliza billetes y monedas de {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50}.
 */
void problema_2 (void) {
    int dinero;
    std::cout << "Ingrese la cantidad de dinero: ";
    std::cin >> dinero;

    int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};

    int n = sizeof(denominaciones) / sizeof(denominaciones[0]);

    for (int i = 0; i < n; i++) {
        int num = dinero / denominaciones[i];
        dinero = dinero % denominaciones[i];
        std::cout << denominaciones[i] << ": " << num << std::endl;
    }

    if (dinero != 0)
        std::cout << "Faltante: " << dinero << std::endl;

}

/**
 * @brief Suma un tiempo a una hora en formato HHMM (24h).
 * 
 * Maneja correctamente el acarreo de minutos y horas, así como el ciclo de 24h.
 */
void problema_4 (void ) {
    int hora, tiempo;

    std::cout << "Ingrese la hora: ";
    std::cin >> hora;
    std::cout << "Ingrese el tiempo que desea sumar: ";
    std::cin >> tiempo;

    //validar la Entrada
    int horas = hora / 100;
    int minutos = hora % 100;

    int tiempo_hora = tiempo / 100;
    int tiempo_minutos = tiempo % 100;

    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
        std::cout << "Entrada invalida" << std::endl;
        return; 
    }
    

    if (tiempo_hora < 0 || tiempo_minutos < 0 ) {
        std::cout << "Entrada invalida de tiempo" << std::endl;
        return; 
    }

    // sumar las horas y minutos
    
    int total_minutos = minutos + tiempo_minutos;           // sumar todos los minutos 
    int minutos_final = total_minutos % 60;                 // lo que quepa sobre despues de agrupar de a 60 min (1h) seran los minutos finales

    int horas_extra = total_minutos / 60;                   // division entera para hallar las horas que aportan los minutos 
    int total_horas = horas + tiempo_hora + horas_extra;    // sumar todas las horas 
    int horas_final = total_horas % 24;                     // las agrupamos en dias (analogo a los minutos)

    int resultado = (horas_final * 100) + minutos_final;

    std::cout << "La hora es: " << resultado << std::endl;


}

/**
 * @brief Aproxima el número de Euler (e) con series infinitas.
 * 
 * e = 1 + 1/1! + 1/2! + 1/3! + ... hasta N términos.
 */
void problema_6 (void ) {
    int N;
    std::cout << "Ingrese el numero de elementos de la aproximacion: ";
    std::cin >> N;

    double euler = 0.0;
    double fac = 1;

    for (int i = 0; i < N; i++) {
        euler += 1 / fac;

        // calular el siguiente factorial 
        fac *= (i + 1);
    }

    std::cout << "e Es aproximadamente: " << euler << std::endl;
}


/**
 * @brief Suma múltiplos de dos números a y b menores que c.
 * 
 * Evita duplicados al verificar si ya fueron sumados.
 */
void problema_8 (void ){
    int a, b, c;
    std::cout << "Ingrese tres numeros enteros positivos (a, b, c): " << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    
    if (a <= 0 ||b <= 0 || c <= 0) {
        std::cout << "Entrada invalida" << std::endl;
        return;
    }

    int suma = 0; 
    bool start = true;

    std::cout << "m ";
    
    // suma de los multiplos de a 
    for (int i = a; i < c; i += a){
        suma += i;
        if (start) {                        // solo se imprime el numero si es el inicio de la cadena 
           std::cout << i;          
           start = false;                   // bandera de reconocimiento de inicio de cadena 
        } else {
            std::cout << " + " << i;        // de otra forma hay que impprimir el +
        }
    }
    
    // suma de los multiplos de b que no han sido sumados aun
    for (int i = b; i < c; i+=b) {
        if(i % a != 0) {                    // Modulo para checkear los duplicados
            suma += i;
            if (start) {                    // solo se imprime el numero si es el inicio de la cadena
                std::cout << i;
                start = false;              // bandera de reconocimiento de inicio de cadena 
            } else {
                std::cout << " + " << i;    // de otra forma hay que imprimir el +
            }
        }
    }

    std::cout << " = " << suma << std::endl;
}

/**
 * @brief Determina si un número es primo.
 * 
 * Usa prueba de divisibilidad para verificar si un número es primo.
 *
 * @param num Número a verificar.
 * @return bool Indica si el número es primo.
 */
bool esPrimo(int num) {

    if (num == 2) return true;
    if (num <= 1 || num % 2 == 0) return false; 
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

/**
 * @brief Determina el N-ésimo número primo.
 * 
 * Usa prueba de divisibilidad y la función auxiliar esPrimo().
 */
void problema_10 (void ) {
    int N;
    std::cout << "Ingrese la posicion del numero primo: ";
    std::cin >> N;

    int contador = 0;
    int numero = 2;

    while (contador < N) {
        if (esPrimo(numero)) {
            contador++;
            if (contador == N) {
                std::cout << "El primo numero: " << N << " es: " << numero << std::endl;
                break;
            }
        
        }
        numero++;
    }
}

/**
 * @brief Encuentra el mayor factor primo de un número.
 * 
 * Descompone el número en factores primos y encuentra el mayor.
 * Utiliza la propiedad de que los factores primos son <= sqrt(num).
 */
void problema_12 () {
    int num;
    std::cout << "Ingrese un numero positivo mayor que 1: ";
    std::cin >> num;
    
    // Verificacion de que si sea mayor que 1 
    if (num <= 1) {
        std::cout << "El numero debe ser mayor que 1" << std::endl;
        return;
    }
    
    int original = num;
    int mfp = 1;

    // Divisiones enteras hasta que no sea divisible por 2 
    while (num % 2 == 0) {
        mfp = 2;
        num /= 2;
    }

    // verificacion de los numeros que cumplan con la condicion factor primo <= sqrt(num) propiedad matematica 
    for (int i = 3; i * i <= num; i+= 2) {
       while(num % i == 0) {        // si el modulo es diferente de cero encontramos el mayor factor primo impar  
            mfp = i;
            num /= i;
       } 
    }
    
    if (num > 1){               // si no se descompuso o no se puede descomponer hasta 1 significa que ya se encontro el mayor factor primo 
        mfp = num;
    }

    std::cout << "El mayor factor primo de " << original << " es " << mfp << std::endl;

}

/**
 * @brief Verifica si un número es palíndromo.
 * 
 * Invierte los dígitos y compara con el original.
 * @param num Número a verificar.
 * @return bool Indica si el número es palíndromo.
 */
bool esPalindromo (int num){

    int original = num;
    int invertido = 0;

    while (num > 0){
        int digito = num % 10;                        // Obtener el ultimo digito
        invertido = (invertido * 10) + digito;        // Lo sumo al invertido (siempre inicia por las unidades porque lo inicialize en 0)
        num = num/10;                                   // Division entera para eliminar el ultimo digito del numero original 
    }
    
    return original ==invertido;
}

/**
 * @brief Encuentra el mayor palíndromo producto de dos números de 3 dígitos.
 * 
 * Recorre todos los productos de números de 3 dígitos y verifica si son palíndromos.
 */
void problema_14 (void ) {
    int mayor_palindromo = 0;
    int factor_a = 0, factor_b = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int multiplicacion = i * j;

            if (esPalindromo(multiplicacion) && multiplicacion > mayor_palindromo) {
                mayor_palindromo = multiplicacion;
                factor_a = i;
                factor_b = j;
            }
            // no tiene sentido seguir buscando si la multiplicacion es menor que el palindromo que ya encontre
            if (multiplicacion < mayor_palindromo) break;
        }
    }

    std::cout << factor_a << "*" << factor_b << " = " << mayor_palindromo << std::endl;
}

/**
 * @brief Calcula la longitud de la serie de Collatz para un número n.
 * 
 * La serie termina cuando n llega a 1, aplicando las reglas:
 * - Si n es par, divide por 2.
 * - Si n es impar, multiplica por 3 y suma 1.
 * 
 * @param n Número inicial para la serie.
 * @param imprimir Indica si se debe imprimir la serie completa.
 * @return int Longitud de la serie.
 */
int coollatz (long long n, bool imprimir = false) {
    int longitud = 1;
    if (imprimir) std::cout << n;

    while (n != 1) {
        if (n % 2 == 0) {n = n / 2;}
        else {n = (3 * n) +1;}

        if (imprimir) std::cout << ", " << n;
        longitud++;
    }

    return longitud;
}


/**
 * @brief Encuentra la semilla con la serie de Collatz más larga.
 * 
 * Solicita un número k y encuentra el número entre 1 y k que genera la serie más larga.
 * Imprime la semilla y la serie completa.
 */
void problema_16 (void ) {
    int k;
    std::cout << "Ingrese el numero k: ";
    std::cin >> k;

    while (k <= 1) {
        std::cout << "Entrada invalida: ";
        std::cin >> k;
    }

    int semilla = 1;
    int longitud = 1;

    for (int j = 1; j < k; j++) {
        int long_act = coollatz(j);

        if (long_act > longitud) {
            longitud = long_act;
                semilla = j;
        }
    }

    std::cout << "La seria mas larga con la semilla: " << semilla << " teniendo " << longitud << " terminos." << std::endl;
    std::cout << "Serie: ";
    coollatz(semilla, true);

}


/**
 * @brief Función principal que ejecuta el programa.
 * 
 * Muestra un mensaje de bienvenida y permite ejecutar la funcion deseada.
 */
int main () {
    std::cout << "Hola Mundo" << std::endl;
    ejercicio_12();
    return 0;
}


