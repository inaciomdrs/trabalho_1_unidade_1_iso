#include "translator.h"

Output_Interface translate(Time_Register *input, int length){
    Output_Interface resultado;

    resultado.tamanhos_vetores = new int[length];
    resultado.tempo = new double[length];
    resultado.porcentagem = new double[length];
    resultado.desvio_padrao_inferior = new double[length];
    resultado.desvio_padrao_superior = new double[length];

    for (int i = 0; i < length; ++i) {
        resultado.tamanhos_vetores[i] = input[i].array_length;
        resultado.tempo[i] = input[i].tempo_execucao;
        resultado.porcentagem[i] = input[i].percentage;
        resultado.desvio_padrao_inferior[i] = input[i].deviation[0];
        resultado.desvio_padrao_superior[i] = input[i].deviation[1];
    }

    return resultado;
}
