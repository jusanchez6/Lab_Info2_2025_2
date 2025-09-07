# Laboratorio 2 – Informática II

Este proyecto contiene la implementación de un conjunto de ejercicios en **C++** diseñados para reforzar conceptos fundamentales de programación.  
Incluye desde operaciones básicas con cadenas y matrices hasta algoritmos combinatorios y simulaciones en **Arduino (Tinkercad)**.  

---

## Objetivos
- Practicar el uso de **estructuras de control**: condicionales, bucles, validaciones.
- Reforzar el concepto de **funciones** y paso de parámetros (valor y referencia).
- Implementar algoritmos clásicos de:
  - Conversión de cadenas y validación de entradas.
  - Operaciones matemáticas (factoriales, permutaciones, rutas en mallas).
  - Manipulación de matrices (rotaciones, verificación de matrices mágicas).
- Vincular programación con aplicaciones prácticas en **electrónica** mediante simulaciones de Arduino.

---

## Estructura del Proyecto
- `main.cpp` → Contiene todos los ejercicios y problemas implementados.
- `CMakeLists.txt` → Script de configuración para compilar con **CMake**.
- `Teclado` → Implementación de un teclado mediante arduino (Ejercicio bonus)
- Documentación generada con **Doxygen** (`html/`, `latex/`).

Cada **función** corresponde a un ejercicio independiente. Ejemplos:
- `problema_2()` → Genera letras aleatorias y cuenta sus frecuencias.
- `problema_4()` → Convierte una cadena en número entero validando errores.
- `problema_10()` → Convierte números romanos a enteros.
- `problema_12()` → Verifica si una matriz es mágica.
- `problema_14()` → Rota matrices en 90°, 180° y 270°.
- `problema_16()` → Calcula el número de rutas en una malla NxN.
- `problema_18()` → Encuentra la n-ésima permutación de los dígitos 0-9.


- **Problema bonus:** → Escribe letras como un teclado (w,a,s,d), implementado en arduino mediante la libreria `Keyboard.h` se encuentra en la carpeta `Teclado`
---

## Requisitos
- [CMake](https://cmake.org/) (versión 3.10 o superior).
- Compilador compatible con **C++17** o superior (`g++`, `clang++`).
- [Doxygen](https://www.doxygen.nl/) (opcional, para generar documentación).
- En Linux: se usa `xdg-open` para abrir simulaciones de Arduino en navegador.

---

## Compilación y Ejecución

1. Crear directorio de compilación:
   ```bash
   mkdir build && cd build
   ```
2. Configurar el proyecto con CMake:
   ```bash
   cmake ..
   ```
3. Compilar:
   ```bash
   make
   ```
   
4. Ejecutar:
   ```bash
   ./Lab_2
   ```

> Para probar otros ejercicios, modifica la llamada en `main()` del archivo `main.cpp`.

---

## Simulaciones en Tinkercad

Algunos ejercicios incluyen simulaciones prácticas en Arduino:

* **Ejercicio 4** → Potenciómetro + LED (variación de intensidad).
* **Problema 6** → Entrada de texto con Arduino.

Cada simulación se abre automáticamente en el navegador si estás en Linux.

---

## Autor

* **Nombre**: Julian Mauricio Sánchez Ceballos
* **Asignatura**: Informática II
* **Fecha**: Agosto 2025
* **Versión**: 1.0

---

## Notas

* El código está diseñado con fines **académicos y de aprendizaje**.
* Todos los ejercicios se pueden usar como base para prácticas más avanzadas en algoritmia y sistemas embebidos.

```

