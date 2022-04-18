#include "../include/all_lib.h"
#include "../include/common.h"
#include "../include/DataStructProbIndex.h"
#include "../include/AlgoProbIndex.h"
#include "../include/utils/dumps.h"
#define DUMP_PRINT

DataStructProbIndex dsProblemDB;
AlgoProbIndex algoProblemDB;

int main()
{
    addDSProblems();
    addAlgoProblems();
    #ifdef DUMP_PRINT
    printDSProblems();
    printAlgoProblems();
    #endif
}