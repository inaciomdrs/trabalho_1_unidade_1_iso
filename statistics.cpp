#include "statistics.h"
#include <cmath>

double mean(double *x, int length){
    double sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += x[i];
    }

    return sum/length;
}

double std_dev(double *x, int length){
    double var_mean = mean(x,length);
    double squareSum = 0;

    for (int i = 0; i < length; ++i) {
        squareSum += pow(x[i]-var_mean,2);
    }

    return sqrt((squareSum) / (length - 1));
}
