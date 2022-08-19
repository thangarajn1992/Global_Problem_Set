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

std::string getDSType(dataStructType_t ds_type)
{
    switch(ds_type)
    {
        case DSTYPE_ARRAY: return "ARRAY";
        case DSTYPE_ND_ARRAY: return "ND_ARRAY";
        case DSTYPE_BIT_MANIPULATION: return "BIT_MANIPULATION";
        case DSTYPE_GRAPH: return "GRAPH";
        case DSTYPE_LINKED_LIST: return "LINKED_LIST";
        case DSTYPE_MATHEMATICS: return "MATHEMATICS";
        case DSTYPE_QUEUE: return "QUEUE";
        case DSTYPE_STACK: return "STACK";
        case DSTYPE_STRING: return "STRING";
        case DSTYPE_TREE: return "TREE";
        default: return "Invalid";
    }
}