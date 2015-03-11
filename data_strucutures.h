// Define as estruturas de dados utilizadas pelo programa

#include <string>

#ifndef DATA_STRUCUTURES_H
#define DATA_STRUCUTURES_H

// Interface de entrada. Captura os dados da interface gráfica e envia para
// o "controlador"
typedef struct {
    std::string range; // std::string contendo a entrada relativa aos tamanhos dos vetores a serem gerados
    int algorithm_selected; // flag relativa ao algoritmo selecionado.
                            // 1 - Só o Quicksort | 2 - Só o Bubblesort | 3 - Ambos
    int iteracoes; // quantidade de iterações
} Input_Interface;

// Interface de saída. Organiza os dados para envio para a interface gráfica, para a produção
// do gráfico
typedef struct {
    int length; // TAMANHO DOS VETORES
    int *tamanhos_vetores;
    double *tempo;
    double *porcentagem;
    double *desvio_padrao_superior;
    double *desvio_padrao_inferior;
} Output_Interface;

typedef struct {
    int start,pass,end;
} Range;

// Estrutura responsável por guardar a média e o desvio padrão dos tempos gastos por um algoritmo
// para ordenar um vetor nas iterações
typedef struct {
    std::string algorithm; // nome do algoritmo
    int array_length; // tamanho do vetor utilizado
    double mean; // média dos tempos gastos
    double *deviation; // desvio-padrão dos tempos gastos
    double tempo_execucao;
    int percentage; // porcentagem do tempo gasto para processar vetores do tamanho especificado em
                    // relação a soma total de todos os tempos gastos.
} Time_Register;

#endif // DATA_STRUCUTURES_H

