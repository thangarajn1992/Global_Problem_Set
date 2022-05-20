#ifndef COMMON_H
#define COMMON_H

#include "Stls.h"

typedef enum operatingMode{
    OPMODE_DATASTRUCT = 1,
    OPMODE_ALGORITHM
}operatingMode_t;

typedef enum dataStructType{
    DSTYPE_ARRAY = 1,
    DSTYPE_ND_ARRAY,
    DSTYPE_BIT_MANIPULATION,
    DSTYPE_GRAPH,
    DSTYPE_LINKED_LIST,
    DSTYPE_MATHEMATICS,
    DSTYPE_QUEUE,
    DSTYPE_STACK,
    DSTYPE_STRING,
    DSTYPE_TREE,
    DSTYPE_MAX
}dataStructType_t;

typedef enum algorithmType{
    ALGO_BACK_TRACKING = 0,
    ALGO_BINARY_SEARCH,
    ALGO_DYNAMIC_PROGRAMMING,
    ALGO_GREEDY,
    ALGO_MAX
}algorithmType_t;


/* Global Parameters */
class DataStructProbIndex;
class AlgoProbIndex;

extern DataStructProbIndex dsProblemDB;
extern AlgoProbIndex algoProblemDB;

#endif