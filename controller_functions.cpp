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

void printVector(Time_Register * array, int size){
    std::setw(15);
    std::cout << "ALGORITHM\tLENGTH\tMEAN\tDEVIATION\tTIME\tPERCENTAGE\n";
    for (int element = 0; element < size; ++element) {
        std::cout << array[element].algorithm << "\t" << array[element].array_length << "\t"
                  << std::setprecision(3) << array[element].mean << "\t" << array[element].deviation << "\t"
                  << array[element].tempo_execucao << "\t" << array[element].percentage << "%\n";
    }
}

// Pega a média e o desvio padrão dos tempos gastos por um algoritmo para ordenar um conjunto de vetores
void runForAnAlgorithm(std::string name, Sorting algorithm, std::vector<int*> arrays, int size,
                       Time_Register& TR, double& tempo_total_processamento){

    TR.algorithm = name;
    TR.array_length = size;
    TR.tempo_execucao = 0;

    int *array_it; // Iterador sobre a lista de vetores
    double times[arrays.size()]; // Guarda o tempo que cada vetor levou para ser ordenado

    for (int var = 0; var < arrays.size(); ++var) {
        array_it = arrays[var];
        times[var] += timeElapsedByAlgorithm(algorithm,array_it,size);
        TR.tempo_execucao += times[var];
        tempo_total_processamento += times[var];
    }

    TR.mean = mean(times,arrays.size());
    TR.deviation = std_dev(times,arrays.size());
}

void init_Time_Register(Time_Register* & TR_1, Time_Register* & TR_2, int flag, int size){
    switch(flag){
        case 1:
            TR_1 = new Time_Register[size];
            TR_2 = NULL;
            break;
        case 2:
            TR_1 = NULL;
            TR_2 = new Time_Register[size];
            break;
        case 3:
            TR_1 = new Time_Register[size];
            TR_2 = new Time_Register[size];
            break;
        default: break;
    }
}
