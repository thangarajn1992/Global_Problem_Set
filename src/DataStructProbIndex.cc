#include "../include/DataStructProbIndex.h"

void
DataStructProbIndex::add_dsProblem(dataStructType_t ds_type, std::string problemName)
{
    dsProblems[ds_type].push_back(problemName);
}

std::string
DataStructProbIndex::get_dsProblem(dataStructType_t ds_type, unsigned int problemNum)
{
    return dsProblems[ds_type][problemNum];
}

unsigned int
DataStructProbIndex::get_dsProblemCount(dataStructType_t ds_type)
{
    return dsProblems[ds_type].size();
}

void 
addDSProblems()
{
    addArrayProblems();
    addNDArrayProblems();
    addBitManipulationProblems();
    addGraphProblems();
    addLinkedListProblems();
    addMathematicsProblems();
    addQueueProblems();
    addStackProblems();
    addStringProblems();
    addTreeProblems();
}