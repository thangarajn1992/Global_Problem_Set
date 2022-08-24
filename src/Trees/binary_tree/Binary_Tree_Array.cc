#include "Binary_Tree.h"

using namespace std;

/* Binary Tree Array Operations */
void 
BinaryTreeArray::addLeftNode(int parentIndex, int value)
{
    if(BinaryTree[parentIndex] == -1)
    {
        cout << "Invalid Parent Node.." << endl;
    }
    else
    {
        BinaryTree[(parentIndex*2) + 1] = value;  
    }
}

void 
BinaryTreeArray::addRightNode(int parentIndex, int value)
{
    if(BinaryTree[parentIndex] == -1)
    {
        cout << "Invalid Parent Node.." << endl;
    }
    else
    {
        BinaryTree[(parentIndex*2) + 2] = value;
    }
}