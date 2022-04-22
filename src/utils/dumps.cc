#include "../../include/utils/dumps.h"

void
printDSProblems()
{
    for(int dsType = DSTYPE_ARRAY; dsType < DSTYPE_MAX; dsType++)
    {
        // TODO: Add utility to convert enum to string
        // std::cout << dsType << std::endl;
        unsigned int size = dsProblemDB.get_dsProblemCount(static_cast<dataStructType_t>(dsType));
        for(unsigned int probNum = 0; probNum < size; probNum++)
        {
            std::cout << probNum+1 << ". " << dsProblemDB.get_dsProblem(static_cast<dataStructType_t>(dsType), probNum) << std::endl;
        }
        std::cout << std::endl;
    }
}

void
printAlgoProblems()
{
    for(int algoType = ALGO_BACK_TRACKING; algoType < ALGO_MAX; algoType++)
    {
        // TODO: Add utility to convert enum to string
        // std::cout << algoType << std::endl;
        unsigned int size = algoProblemDB.get_algoProblemCount(static_cast<algorithmType_t>(algoType));
        for(unsigned int probNum = 0; probNum < size; probNum++)
        {
            std::cout << probNum+1 << ". " << algoProblemDB.get_algoProblem(static_cast<algorithmType_t>(algoType), probNum) << std::endl;
        }
        std::cout << std::endl;
    }
}


/* Overloading cout to print vector of any type */
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    os << "[ ";
    for(auto elem : vec)
    {
        os << elem<< " ";
    }
    os << "]\n";
    return os;
}