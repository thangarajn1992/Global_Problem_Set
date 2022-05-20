#ifndef ALGORITHM_PROBLEM_INDEX_H
#define ALGORITHM_PROBLEM_INDEX_H
#include "Stls.h"
#include "common.h"

class AlgoProbIndex{
private:
    std::vector<std::string> algoProblems[ALGO_MAX];

public:
    void add_algoProblem(algorithmType_t algo_type, std::string problemName);
    std::string get_algoProblem(algorithmType_t algo_type, unsigned int problemNum);
    unsigned get_algoProblemCount(algorithmType_t algo_type);
    
};

void addAlgoProblems();
void addBackTrackingProblems();
void addBinarySearchProblems();
void addDynamicProgrammingProblems();
void addGreedyProblems();

#endif