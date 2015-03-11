#include "mainwindow.h"
#include "controller.h"

#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    //    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    //    return a.exec();

    Input_Interface I;
    I.algorithm_selected = 3;
    I.iteracoes = 10;
    I.range = "1000:1000:10000";

    Output_Interface* saidas = process(&I);

    Output_Interface saida_quicksort = saidas[0];
    Output_Interface saida_bubblesort = saidas[1];

    std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA QUICKSORT\n";
    for (int i = 0; i < saida_quicksort.length; ++i) {
        std::cout << saida_quicksort.tamanhos_vetores[i] << " "
                  << saida_quicksort.tempo[i] << " "
                  << saida_quicksort.porcentagem[i] << " "
                  << saida_quicksort.desvio_padrao_inferior[i] << " "
                  << saida_quicksort.desvio_padrao_superior[i] << "\n";
    }

    std::cout << "\nIMPRIMINDO SAÍDA BRUTA PARA QUICKSORT\n";
    for (int i = 0; i < saida_bubblesort.length; ++i) {
        std::cout << saida_quicksort.tamanhos_vetores[i] << " "
                  << saida_bubblesort.tempo[i] << " "
                  << saida_bubblesort.porcentagem[i] << " "
                  << saida_bubblesort.desvio_padrao_inferior[i] << " "
                  << saida_bubblesort.desvio_padrao_superior[i] << "\n";
    }

    std::cout << "FIM\n";



}
