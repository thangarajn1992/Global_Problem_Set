#ifndef DATASTRUCT_PROBLEM_INDEX_H
#define DATASTRUCT_PROBLEM_INDEX_H
#include "all_lib.h"
#include "common.h"

class DataStructProbIndex{
private:
    std::vector<std::string> dsProblems[DSTYPE_MAX];

public:
    void add_dsProblem(dataStructType_t ds_type, std::string problemName);
    std::string get_dsProblem(dataStructType_t ds_type, unsigned int problemNum);
    unsigned int get_dsProblemCount(dataStructType_t ds_type);
};

void addDSProblems();
void addArrayProblems();
void addNDArrayProblems();
void addBitManipulationProblems();
void addGraphProblems();
void addLinkedListProblems();
void addMathematicsProblems();
void addQueueProblems();
void addStackProblems();
void addStringProblems();
void addTreeProblems();
#endif