#include "array_handler.h"
#include <ctime>
#include <cstdlib>

// Ponteiro para "função de ordenação" que recebe como parâmetro um vetor e seu tamanho
typedef void (*Sorting) (int*,int);

// Gera um array de tamanho n
int* generateArrayOfSize(int n){
    srand(time(NULL));
    int *array = new int[n];
    for (int i = 0; i < n; ++i) {
        array[i] = 1 + rand() % n; // Produz um número aleatório entre 1 e n
    }
    return array;
}

void generateArraysOfSize(int n, int quantity, std::vector<int*>& arrays){
    for (int iArray = 0; iArray < quantity; ++iArray) {
        int *array = generateArrayOfSize(n);
        arrays.push_back(array);
    }
}

// Mede o tempo gasto por um algoritmo para ordenar um vetor de 'length' elementos
double timeElapsedByAlgorithm(Sorting sorter, int *array, int length){
    clock_t inicio, fim;
    inicio = clock();
    sorter(array,length);
    fim = clock();

    return (double) ((fim-inicio) / ((double) CLOCKS_PER_SEC));

}
