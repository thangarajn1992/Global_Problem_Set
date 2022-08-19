#include "../include/AlgoProbIndex.h"

void
AlgoProbIndex::add_algoProblem(algorithmType_t algo_type, std::string problemName)
{
    algoProblems[algo_type].push_back(problemName);
}

std::string
AlgoProbIndex::get_algoProblem(algorithmType_t algo_type, unsigned int problemNum)
{
    return algoProblems[algo_type][problemNum];
}

unsigned int
AlgoProbIndex::get_algoProblemCount(algorithmType_t algo_type)
{
    return algoProblems[algo_type].size();
}

void
addAlgoProblems(){
    addBackTrackingProblems();
    addBinarySearchProblems();
    addDynamicProgrammingProblems();
    addGreedyProblems();
}

std::string getAlgoType(algorithmType_t algo_type)
{
    switch(algo_type)
    {
        case ALGO_BACK_TRACKING: return "BACK_TRACKING";
        case ALGO_BINARY_SEARCH: return "BINARY_SEARCH";
        case ALGO_DYNAMIC_PROGRAMMING: return "DYNAMIC_PROGRAMMING";
        case ALGO_GREEDY: return "GREEDY";
        default: return "INVALID";
    }
}