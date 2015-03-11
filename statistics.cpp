#include "statistics.h"
#include <cmath>

#define NIVEL_CONFIANCA 1.96

double mean(double *x, int length){
    double sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += x[i];
    }

    return sum/length;
}

double * std_dev(double *x, int length){
    double var_mean = mean(x,length);
    double squareSum = 0;

    for (int i = 0; i < length; ++i) {
        squareSum += pow(x[i]-var_mean,2);
    }

    double std_dev = sqrt((squareSum) / (length - 1));
    double e = (NIVEL_CONFIANCA * std_dev)/sqrt(length);

    double resultado[2];
    resultado[0] = var_mean - e; // Limite Inferior
    resultado[1] = var_mean + e; // Limite Superior

    return resultado;
}
