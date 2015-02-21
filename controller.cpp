#include "controller.h"

void process(Input_Interface *input){
    // Captura os valores do range para o "forzao"
    int *valoresRange = getRange(input->range);
    Range *range = new Range;
    range->start = valoresRange[0];
    range->pass = valoresRange[1];
    range->end = valoresRange[2];

    int size = range->end / range->start;

    // = &runForAnAlgorithm("quicksort",quicksort,range,input->iteracoes);
    Time_Register* for_quicksort;
    Time_Register* for_bubblesort;

    switch(input->algorithm_selected){
        case 1:
            for_quicksort = runForAnAlgorithm("quicksort",quicksort,range,input->iteracoes);
            break;
        case 2:
            for_bubblesort = runForAnAlgorithm("bubblesort",bubblesort,range,input->iteracoes);
            break;
        case 3:
            for_quicksort = runForAnAlgorithm("quicksort",quicksort,range,input->iteracoes);
            for_bubblesort = runForAnAlgorithm("bubblesort",bubblesort,range,input->iteracoes);
            break;
        default: break;
    }

    if(for_quicksort){
        printVector(for_quicksort,size);
    }

    if(for_bubblesort){
        printVector(for_bubblesort,size);
    }
}
