#include "controller_functions.h"

// Retorna um vetor com 3 posições, em que: v[0] - Inicio | v[1] - Passo | v[2] - Fim
int* getRange(std::string input){
    std::string delimiter = ":";
    int *saida = new int[3];

    size_t pos = 0;
    int it = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        std::istringstream ss(token);
        ss.imbue(std::locale::classic());
        ss >> saida[it];
        input.erase(0, pos + delimiter.length());
        it++;
    }
    std::istringstream ss(input);
    ss.imbue(std::locale::classic());
    ss >> saida[it];

    return saida;
}

Time_Register* runForAnAlgorithm(std::string name, Sorting algorithm, Range *range, int iteracoes){
    int result_vector_size = range->end / range->start;

    Time_Register* time_registers = new Time_Register[result_vector_size]; // Guarda os registros de tempo
                                               // para cada tamanho de entrada

    int tempo_processamento_total = 0; // Guarda o somatório de todos os tempos para todas as entradas

    int *array;

    int it = 0;
    for (int size = range->start; size <= range->end; size += range->pass) {
        time_registers[it].algorithm = name;
        time_registers[it].array_length = size;
        time_registers[it].tempo_execucao = 0;

        double elapsed_times[iteracoes];

        for (int iteracao = 1; iteracao <= iteracoes; ++iteracao) {
            array = generateArrayOfSize(size);
            elapsed_times[iteracao] = timeElapsedByAlgorithm(algorithm,array,size);
            time_registers[it].tempo_execucao += elapsed_times[iteracao];
            tempo_processamento_total += elapsed_times[iteracao];
        }

        time_registers[it].mean = mean(elapsed_times,size);
        time_registers[it].deviation = std_dev(elapsed_times,size);

        it++;

    }

    double percentage;
    for (int time_register = 0; time_register < result_vector_size; ++time_register) {
        percentage = time_registers[time_register].tempo_execucao / tempo_processamento_total;
        time_registers[time_register].percentage = (int) (percentage * 100);
    }
    return time_registers;
}

void printVector(Time_Register * array, int size){
    std::cout << "ALGORITHM | LENGTH | MEAN | DEVIATION | TIME | PERCENTAGE\n";
    for (int element = 0; element < size; ++element) {
        std::cout << array[element].algorithm << " | " << array[element].array_length << " | "
                  << array[element].mean << " | " << array[element].deviation << " | "
                  << array[element].tempo_execucao << " | " << array[element].percentage << "\n";
    }
}
