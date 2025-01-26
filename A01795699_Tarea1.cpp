#include <iostream>
#include <omp.h>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

int main() {
    const int n = 1000;
    int arreglo1[n], arreglo2[n], resultado[n];

    // Sembrar el generador de números aleatorios con el tiempo actual
    srand(time(0));

    // Inicializar arreglos con números aleatorios
    for (int i = 0; i < n; i++) {
        arreglo1[i] = rand() % 100; // Números entre 0 y 99
        arreglo2[i] = rand() % 100;
    }

    // Suma paralela con OpenMP
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        resultado[i] = arreglo1[i] + arreglo2[i];
    }

    // Imprimir los primeros 10 valores de cada arreglo
    std::cout << "Arreglo 1: ";
    for (int i = 0; i < 10; i++) std::cout << arreglo1[i] << " ";
    std::cout << "\n";

    std::cout << "Arreglo 2: ";
    for (int i = 0; i < 10; i++) std::cout << arreglo2[i] << " ";
    std::cout << "\n";

    std::cout << "Resultado: ";
    for (int i = 0; i < 10; i++) std::cout << resultado[i] << " ";
    std::cout << "\n";

    return 0;
}