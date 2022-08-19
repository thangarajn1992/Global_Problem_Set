#include "../../include/utils/dumps.h"

void
printDSProblems()
{
    for(int dsType = DSTYPE_ARRAY; dsType < DSTYPE_MAX; dsType++)
    {
        std::cout << "===================================" << std::endl;
        std::cout << getDSType(static_cast<dataStructType_t>(dsType)) << std::endl;
        std::cout << "===================================" << std::endl;
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
        std::cout << "===================================" << std::endl;
        std::cout << getAlgoType(static_cast<algorithmType_t>(algoType)) << std::endl;
        std::cout << "===================================" << std::endl;
        unsigned int size = algoProblemDB.get_algoProblemCount(static_cast<algorithmType_t>(algoType));
        for(unsigned int probNum = 0; probNum < size; probNum++)
        {
            std::cout << probNum+1 << ". " << algoProblemDB.get_algoProblem(static_cast<algorithmType_t>(algoType), probNum) << std::endl;
        }
        std::cout << std::endl;
    }
}