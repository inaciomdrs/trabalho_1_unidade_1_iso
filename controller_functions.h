#include "array_handler.h"
#include "data_strucutures.h"
#include "statistics.h"
#include "sorting.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef CONTROLLER_FUNCTIONS_H
#define CONTROLLER_FUNCTIONS_H

int* getRange(std::string input);
void printVector(Time_Register* array, int size);
void runForAnAlgorithm(std::string name, Sorting algorithm, std::vector<int*> arrays, int size,
                       Time_Register& TR, double& tempo_total_processamento);
void init_Time_Register(Time_Register* & TR_1, Time_Register* & TR_2, int flag, int size);

#endif // CONTROLLER_FUNCTIONS_H

