#include "controller.h"

void process(Input_Interface *input){
    // Captura os valores do range para o "forzao"
    int *valoresRange = getRange(input->range);
    Range *range = new Range;
    range->start = valoresRange[0];
    range->pass = valoresRange[1];
    range->end = valoresRange[2];

    std::vector<int*> vetores;
    double total_time = 0;
    int time_register_list_size = range->end / range->start;

    Time_Register* for_quicksort  = NULL;
    Time_Register* for_bubblesort = NULL;

    init_Time_Register(for_quicksort,for_bubblesort,input->algorithm_selected,time_register_list_size);

    for (int vec_size = range->start, TR_iterator = 0; vec_size <= range->end; vec_size += range->pass, TR_iterator++) {
        vetores.clear();
        generateArraysOfSize(vec_size,input->iteracoes,vetores);

        if(for_quicksort){
            runForAnAlgorithm("quicksort",quicksort,vetores,vec_size,for_quicksort[TR_iterator],total_time);
//            std::cout << "(QUICK) Tempo Parcial: " << for_quicksort[TR_iterator].tempo_execucao << "\n";
        }

        if(for_bubblesort){
            runForAnAlgorithm("bubblesort",bubblesort,vetores,vec_size,for_bubblesort[TR_iterator],total_time);
//            std::cout << "(BUBBLE) Tempo Parcial: " << for_bubblesort[TR_iterator].tempo_execucao << "\n";
        }
    }

    std::cout << "Tempo Total: " << total_time << "\n";

    if(for_quicksort){

        for (int i = 0; i < time_register_list_size; ++i) {
            for_quicksort[i].percentage = (for_quicksort[i].tempo_execucao / total_time) * 100;
        }

        printVector(for_quicksort,time_register_list_size);
    }

    if(for_bubblesort){

        for (int i = 0; i < time_register_list_size; ++i) {
            for_bubblesort[i].percentage = (for_bubblesort[i].tempo_execucao / total_time) * 100;
        }

        printVector(for_bubblesort,time_register_list_size);
    }

    std::cout << "FIM\n";

}
