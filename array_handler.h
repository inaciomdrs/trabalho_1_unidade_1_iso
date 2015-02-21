// Implementa funções de manipulação de vetores (geração e ordenação)

#include <vector>

#ifndef UTIL_H
#define UTIL_H

typedef void (*Sorting) (int*,int); // Ponteiro para "função de ordenação" que recebe como parâmetro um vetor e seu tamanho

int* generateArrayOfSize(int n); // Gera um array de tamanho n
void generateArraysOfSize(int n, int quantity, std::vector<int*>& arrays);
double timeElapsedByAlgorithm(Sorting sorter, int *array, int length); // Mede o tempo gasto por um algoritmo
                                                                     // para ordenar um vetor de 'length'
                                                                     // elementos

#endif // UTIL_H

