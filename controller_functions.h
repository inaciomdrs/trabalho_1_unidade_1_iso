#include "array_handler.h"
#include "data_strucutures.h"
#include "statistics.h"
#include "sorting.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#ifndef CONTROLLER_FUNCTIONS_H
#define CONTROLLER_FUNCTIONS_H

int* getRange(std::string input);
Time_Register* runForAnAlgorithm(std::string name, Sorting algorithm, Range *range, int iteracoes);
void printVector(Time_Register* array, int size);

#endif // CONTROLLER_FUNCTIONS_H

