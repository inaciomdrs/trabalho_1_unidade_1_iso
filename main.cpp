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
    I.range = "10:10:50";

    // esse método process pega uma Input_Interface, faz o muido todo de medição, ordenação
    // etc. etc. e devolve os resultados todos prontins, só os vetores de int e double show
    // de bola, todos guardados num ponteiro de 'Output_Interface'

    // Na verdade, na verdade, a saída...
    Output_Interface* saidas = process(&I);

    Output_Interface saida_quicksort = saidas[0];
    Output_Interface saida_bubblesort = saidas[1];

    if(saida_quicksort.length != 0) {
        std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA QUICKSORT\n";
        for (int i = 0; i < saida_quicksort.length; ++i) {
            std::cout << saida_quicksort.tamanhos_vetores[i] << " "
                      << saida_quicksort.tempo[i] << " "
                      << saida_quicksort.porcentagem[i] << " "
                      << saida_quicksort.desvio_padrao_inferior[i] << " "
                      << saida_quicksort.desvio_padrao_superior[i] << "\n";
        }
    }

    if(saida_bubblesort.length != 0){
        std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA BUBBLESORT\n";
        for (int i = 0; i < saida_bubblesort.length; ++i) {
            std::cout << saida_bubblesort.tamanhos_vetores[i] << " "
                      << saida_bubblesort.tempo[i] << " "
                      << saida_bubblesort.porcentagem[i] << " "
                      << saida_bubblesort.desvio_padrao_inferior[i] << " "
                      << saida_bubblesort.desvio_padrao_superior[i] << "\n";
        }
    }

    std::cout << "FIM\n";

}
