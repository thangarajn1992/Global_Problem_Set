#include "Stls.h"
#include "common.h"
#include "DataStructProbIndex.h"
#include "AlgoProbIndex.h"
#include "dumps.h"


#include "All_Linked_List.h"
#include "All_Tree.h"
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


    unsigned int op_mode;
    cout << "Enter Operating Mode: " << endl;
    cout << "1. Data Structures" << endl;
    cout << "2. Algorithms" << endl;
    cin >> op_mode;

    switch(static_cast<operatingMode_t>(op_mode))
    {
        case OPMODE_DATASTRUCT:
        {
            unsigned int dsType;
            cout << "Enter DataStructure Type:" << endl;
            cout << "1. Arrays " << endl;
            cout << "2. ND Arrays " << endl;
            cout << "3. Bit Manipulation " << endl;
            cout << "4. Graph" << endl;
            cout << "5. Linked List " << endl;
            cout << "6. Mathematics" << endl;
            cout << "7. Queue" << endl;
            cout << "8. Stack" << endl;
            cout << "9. String" << endl;
            cout << "10. Tree" << endl;
            cin >> dsType;

            switch(static_cast<operatingMode_t>(dsType))
            {
                case DSTYPE_ARRAY:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_ND_ARRAY:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_BIT_MANIPULATION:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_GRAPH:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_LINKED_LIST:
                {
                    linkedListMain();
                    break;
                }
                case DSTYPE_MATHEMATICS:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_QUEUE:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_STACK:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_STRING:
                {
                    cout << "Unimplemented " << endl;
                    break;
                }
                case DSTYPE_TREE:
                {
                    treesMain();
                    break;
                }
            }
            break;
        }
        case OPMODE_ALGORITHM:
        {
            break;
        }
        default:
            cout << "Error: Invalid Operating Mode" << endl;
    }
    
    #endif
}