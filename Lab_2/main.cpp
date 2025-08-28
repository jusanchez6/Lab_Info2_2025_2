#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Funcion corregida
 * 
 * El error en la función brindada es que a pesar de que pasan 
 * los valores por referencia pero se trata como si fuera entregado por 
 * valor
 */
void func_c (double *a, int n, double *promedio, double *suma) {
    int i;
    *suma = 0.0;
    
    for (i = 0; i < n; i++)
        *suma +=a[i];


    *promedio = *suma/n;
}


/**
 * @brief Función de caso de prueba para la corrección de la función fun_c
 * 
 */
void ejercicio_2 (void ) {
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
void ejercicio_4 (void ){
    string url = "https://www.tinkercad.com/things/dFCu7UutNep-ejercicio4";

    cout << "Abriendo la simulación de Arduino en thinkercad..." << endl;
    string command = "xdg-open " + url + " &";
    system(command.c_str());
}


// ==================================================================================
// ================================= PROBLEMAS ======================================
// ==================================================================================

void problema_2 (void) {
    
    const int N = 200;                          // Tamaño del arreglo
    char arreglo[N];
    int contador[26] = {0};

    srand(time(0));                             // Genera valores aleatorios pero de verdad

    for (int i = 0; i < N; i++) {
        arreglo[i] = 'A' + (rand() % 26);       // 26 es por el numero de letras en el abecedario
        contador[arreglo[i] - 'A']++;           // Resta 'A' para normalizar el contador
    }

    for (int i = 0; i < N; i++) {
        cout << arreglo[i];                     // Imprime la cadena
    }

    cout << endl;

    for (int i= 0; i < 26; i++) {
        if (contador[i] > 0) {
            cout << char('A' + i) << ": " << contador[i] << endl;
        }
    }

}


int ConvertirCadena (const string &cadena) {
    int numero = 0;
    for (char c : cadena) {         // Esto es una forma elegante de iterar en una cadena que no conocia
        if (c >= '0' && c <= '9') {
            numero = numero * 10 + (c -'0');    // se resta '0' para normalizar y se multiplica por 10 para correr el numero       
        } else {
            cout << "Error en la cadena" << endl;
            return 0;
        }

    }
    return numero;
}

void problema_4 (void) {
    string cadena;
    cout << "Ingrese un numero entero positivo: ";
    cin >> cadena;

    int numero = ConvertirCadena(cadena);
    if (numero != 0) {
        cout << "El numero es: " << numero << endl;
    }
}

void problema_6 (bool arduino=false) {
    string texto;

    cout << "Ingrese un texto: ";
    getline(cin, texto);

    string mayuscula = texto;       // copia del texto original

    for (char &c : mayuscula) {
    if (c >= 'a' && c<= 'z') {
        c = c - 'a' + 'A';      // al restar a se halla el indice de la letra y al sumarle A se halla la letra  
        }
    }

    cout << "Original: " << texto << endl;
    cout << "En mayuscula: " << mayuscula << endl;
    
    if (arduino) {
        string url = "https://www.tinkercad.com/things/kutuTuhdpOZ-problema-6?sharecode=LWKx6Swrzji1WUXdT8BpVI5435CQSqp2NA1xf-ccmK0";

        cout << "Abriendo la simulación de Arduino en thinkercad..." << endl;
        string command = "xdg-open " + url + " &";
        system(command.c_str());

    }
  
}

void problema_8 (void ) {
    string entrada;
    string texto = "";
    string numeros = "";

    cout << "Ingrese la cadena de texto: ";
    getline(cin, entrada);


    for (char c: entrada) {
        if (c >= '0' && c <= '9') {numeros += c;}
        else {texto += c;}
    }

    cout << "Original: " << entrada << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numeros << endl;
}

int conversor (char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Carácter no válido
    }
}

void problema_10 (void) {
    string entrada;
    cout << "Ingrese un numero romano en MAYUSCULA: ";
    getline(cin, entrada);

    int total = 0;
    int n = entrada.length();

    for (int i = 0; i < n; i++) {
        int valor = conversor(entrada[i]);

        if (i +1 < n && valor < conversor(entrada[i + 1])) {
            total -= valor; // Resta si el valor actual es menor que el siguiente
        } else {
            total += valor; // Suma en caso contrario
        }

    }

    cout << "El numero ingresado fue: " << entrada << endl;
    cout << "Que corresponde a: " << total << endl;

}




int main() {
    cout << "Hello, World!" << endl;
    problema_10();
    return 0;
}


