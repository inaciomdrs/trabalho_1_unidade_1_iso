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

int comparar(const void * x, const void * y){
    int *m = (int*) x;
    int *n = (int*) y;

    return ( (*m) - *(n) );
}

void quicksort(int *v, int N){
    qsort(v,N,sizeof(int),comparar);
}
