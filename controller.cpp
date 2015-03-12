#include "controller.h"

Output_Interface* process(Input_Interface *input){
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

    Output_Interface saida_quicksort, saida_bubblesort;
    Output_Interface *output = new Output_Interface[2];
    output[0].length = 0;
    output[1].length = 0;

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

    if(for_quicksort){

        for (int i = 0; i < time_register_list_size; ++i) {
            for_quicksort[i].percentage = (for_quicksort[i].tempo_execucao / total_time) * 100;
        }

        saida_quicksort = translate(for_quicksort,time_register_list_size);
        saida_quicksort.length = time_register_list_size;
        output[0] = saida_quicksort;

    }

    if(for_bubblesort){

        for (int i = 0; i < time_register_list_size; ++i) {
            for_bubblesort[i].percentage = (for_bubblesort[i].tempo_execucao / total_time) * 100;
        }

        saida_bubblesort = translate(for_bubblesort,time_register_list_size);
        saida_bubblesort.length = time_register_list_size;
        output[1] = saida_bubblesort;

    }

    return output;

}
