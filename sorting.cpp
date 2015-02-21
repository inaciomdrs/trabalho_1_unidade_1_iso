#include "sorting.h"

void bubblesort(int *v, int N){
    int i, j, aux;
    for(i = N-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int partition(int v[], int ini, int fim){
    int pivo = ini;
    for(int i = ini+1; i < fim; i++){
        if(v[i] < v[ini]){
            pivo++;
            // Troca o elemento que está em v[i] com v[pivo]
            int aux = v[pivo];
            v[pivo] = v[i];
            v[i] = aux;
        }
    }
    int aux = v[ini];
    v[ini] = v[pivo];
    v[pivo] = aux;
    return pivo;
}

void realQuickSort(int *v, int N, int ini, int fim){
    if(fim > ini){
        int pivot = partition(v,ini,fim);
        realQuickSort(v,N,ini,pivot);
        realQuickSort(v,N,pivot+1,N);
    }
}

void quicksort(int *v, int N){
    realQuickSort(v,N,0,N-1);
}
