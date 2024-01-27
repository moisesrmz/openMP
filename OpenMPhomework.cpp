// OpenMPhomework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // Para la generaci�n de n�meros aleatorios
#include <omp.h>   // Para OpenMP

#define N 20       // Tama�o de los arreglos
#define chunk 100    // Tama�o del chunk para la paralelizaci�n
#define mostrar 10   // Cantidad de elementos a mostrar

// Prototipo de la funci�n para imprimir arreglos
void imprimeArreglo(int* arreglo);

// Funci�n para imprimir los elementos de un arreglo
void imprimeArreglo(int* arreglo) {
    for (int i = 0; i < mostrar; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Declaraci�n de arreglos
    int a[N], b[N], c[N];

    // Inicializaci�n de arreglos a y b con valores aleatorios
    srand(0); // Semilla para la generaci�n de n�meros aleatorios
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    // Suma de los arreglos a y b en paralelo
#pragma omp parallel for shared(a, b, c, chunk) private(i)
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Impresi�n de parte de los arreglos a, b y c
    std::cout << mostrar << " elementos del arreglo a           : ";
    imprimeArreglo(a);

    std::cout << mostrar << " elementos del arreglo b           : ";
    imprimeArreglo(b);

    std::cout << mostrar << " elementos del arreglo c (suma)    : ";
    imprimeArreglo(c);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
