#include "mainwindow.h"
#include "controller.h" // Inclua isso no começo do arquivo da interface gráfica

#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    // Por detrás da interface gráfica, defina essa variável para guardar nela os valores de entrada
    // das caixas de texto
    Input_Interface I;


    // Aqui é o seguinte: como vai ter duas checkboxs (uma pro bubblesort e outra pro quicksort)
    // tu vai fazer o seguinte: se só o quick tiver sido selecionado, então vai I.algorithm_selected
    // vai ser 1. Se só o bubble tiver sido selecionado, então vai ser 2. Se os dois tiverem sido
    // selecionados, então vai ser 3.
    I.algorithm_selected = 3;

    // No código com interface gráfica, aqui seria algo do tipo:
    // I.iteracoes = ui->numIteracoes->intValue()
    // Considerando que tem um textbox de nome 'numIteracoes'
    I.iteracoes = 10;

    // Mesma coisa pra cá
    I.range = "25000:25000:100000";

    // esse método process pega uma Input_Interface, faz o muido todo de medição, ordenação
    // etc. etc. e devolve os resultados todos prontins, só os vetores de int e double show
    // de bola, todos guardados num ponteiro de 'Output_Interface'

    // Na verdade, na verdade, a saída vai ser um vetor com dois 'Output_Interface': um pro
    // quick e outro pro bubble. Pra saber se um 'Output_Interface' está "vazio" (ou seja,
    // não foi rodado um algoritmo específico), é só ver o atributo length.
    Output_Interface* saidas = process(&I);

    Output_Interface saida_quicksort = saidas[0];
    Output_Interface saida_bubblesort = saidas[1];


    // Vetores inteiros e double de saída
    // ------------------------------------------
    // QUICKSORT
    //===========================================
    int *QeixoXtamanhos; // Tamanhos dos vetores
    double *QeixoYtempos; // Tempo total para ordenar todos os vetores de um determinado tamanho
    double *QeixoYporcentagem; // Porcentagem de cada tempo total acima sobre a soma de todos os tempos
    double *QeixoYdesvioPadraoInferior; // desvio padrão inferior
    double *QeixoYdesvioPadraoSuperior; // desvio padrão superior
    //===========================================
    // BUBBLESORT
    //===========================================
    int *BeixoXtamanhos; // Tamanhos dos vetores
    double *BeixoYtempos; // Tempo total para ordenar todos os vetores de um determinado tamanho
    double *BeixoYporcentagem; // Porcentagem de cada tempo total acima sobre a soma de todos os tempos
    double *BeixoYdesvioPadraoInferior; // desvio padrão inferior
    double *BeixoYdesvioPadraoSuperior; // desvio padrão superior
    //===========================================



    // Se o quicksort foi selecionado anteriormente, então o atributo "length" de saida_quicksort
    // é maior que zero.
    if(saida_quicksort.length != 0) {
        // EXTRAINDO OS VETORES (Todos os vetores vão ter o mesmo tamanho, que vai ser saida_quicksort.length)
        // ==================================================
        QeixoXtamanhos = saida_quicksort.tamanhos_vetores;
        QeixoYtempos = saida_quicksort.tempo;
        QeixoYporcentagem = saida_quicksort.porcentagem;
        QeixoYdesvioPadraoInferior = saida_quicksort.desvio_padrao_inferior;
        QeixoYdesvioPadraoSuperior = saida_quicksort.desvio_padrao_superior;
        // ==================================================

        std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA QUICKSORT\n";
        for (int i = 0; i < saida_quicksort.length; ++i) {
            std::cout << QeixoXtamanhos[i] << " "
                      << QeixoYtempos[i] << " "
                      << QeixoYporcentagem[i] << " "
                      << QeixoYdesvioPadraoInferior[i] << " "
                      << QeixoYdesvioPadraoSuperior[i] << "\n";
        }
    }


    // Se o bubblesort foi selecionado anteriormente, então o atributo "length" de saida_quicksort
    // é maior que zero.
    if(saida_bubblesort.length != 0){
        // EXTRAINDO OS VETORES (Todos os vetores vão ter o mesmo tamanho, que vai ser saida_quicksort.length)
        // ==================================================
        BeixoXtamanhos = saida_bubblesort.tamanhos_vetores;
        BeixoYtempos = saida_bubblesort.tempo;
        BeixoYporcentagem = saida_bubblesort.porcentagem;
        BeixoYdesvioPadraoInferior = saida_bubblesort.desvio_padrao_inferior;
        BeixoYdesvioPadraoSuperior = saida_bubblesort.desvio_padrao_superior;
        // ==================================================

        std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA BUBBLESORT\n";
        for (int i = 0; i < saida_bubblesort.length; ++i) {
            std::cout << BeixoXtamanhos[i] << " "
                      << BeixoYtempos[i] << " "
                      << BeixoYporcentagem[i] << " "
                      << BeixoYdesvioPadraoInferior[i] << " "
                      << BeixoYdesvioPadraoSuperior[i] << "\n";
        }
    }

    std::cout << "FIM\n";

}
