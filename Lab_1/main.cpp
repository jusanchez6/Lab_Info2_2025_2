#include <iostream>
#include <cstdlib>

/**
 * @brief Determina si un número ingresado es par o impar.
 * 
 * Solicita al usuario un número entero y muestra en pantalla si es par o impar.
 */
void is_even_or_odd (void) {     
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
void smaller_number (void) {     
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
 * @note No maneja el caso de exponente 0 o números negativos.
 */
void my_pow (void) {     
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
void my_factorial (void) {     
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
void multiplos (void) {     
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
void all_pows (void) {     
    std::cout << "Ingrese un numero: " << std::endl;     
    int N;     
    std::cin >> N;      

    int result = 1;
    for (int i = 1; i <= 5; i++) {      
        result *= N;  // Multiplicación iterativa para simular potencia   
        std::cout << N << "^" << i << " = " << result << std::endl;     
    }      
}


void Two_columns(void ) {
    for(int i = 1; i<=50; i++){
        std::cout << i << "\t" << 51 - i << std::endl;
    }
}

void ejercicio_16(void ) {
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

void ejercicio_20 (void ){

    int N;
    std::cout << "Ingrese un numero: " << std::endl;
    std::cin >> N;

    int original = N;
    int invertido = 0;

    while (N < 0){
        int digito = N % 10;                        // Obtener el ultimo digito
        invertido = invertido * 10 + digito;        // Lo sumo al invertido (siempre inicia por las unidades porque lo inicialize en 0)
        N = N/10;                                   // Division entera para eliminar el ultimo digito del numero original 
    }
    
    if (invertido == original)
        std::cout << original << " Es palindromo" << std::endl;
    else
        std::cout << original << " No es palindromo" << std::endl;
}


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


void ejercicio_24 (void ) {
    int N;
    std::cout << "Ingrese el numero de filas del cuadrado: " << std::endl;
    std::cin >> N;

    for (int i = 0; i < N; i++) {                                   // filas del cuadrado 
        for (int j = 0; j < N; j++){                                // columnas del cuadrado
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)      // solo quiero escribir en la primera/ultima columna y fila
                std::cout << "+";
            else
                std::cout << " ";
        }
        std::cout << "\n";                          // salto de linea al final de la fila             
    }

} 

void ejercicio_26 (void) {
    int a, b, c;
    std::cout << "Ingrese tres numeros (lasods del triangulo): ";
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


void ejercicio_30 (void ){
    int A = rand() % 101;
    int B;
    int intentos = 0;


    do {
        std::cin >> B;
        intentos++;
    
        if (A < B)
            std::cout << "El numero es mayor" << std::endl;
        else if (A > B)
            std::cout << "El numero es menor" << std::endl;
        else
            std::cout << "Correcto, Intentos: " << intentos << std::endl;
    } while (B != A);

}

int main () {
    std::cout << "Hola Mundo" << std::endl;
    Two_columns();
    return 0;
}


