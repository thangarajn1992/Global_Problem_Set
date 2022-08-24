#include "Binary_Tree.h"

using namespace std;

/*  Replace all Node with the sum of its inorder predecessor and
    successor */
void 
BinaryTree::toInorderPredecessorSuccessor(BinaryTreeNode *node)
{
    int previousVal = -1;
    BinaryTreeNode *previous = nullptr;
    toInorderPredecessorSuccessorUtil(node, previous, previousVal);
    previous->data = previousVal;
}

void 
BinaryTree::toInorderPredecessorSuccessorUtil(BinaryTreeNode *node,
                                              BinaryTreeNode* &previous,
                                              int &prevVal)
{
    if(node == nullptr)
        return;

    toInorderPredecessorSuccessorUtil(node->left, previous, prevVal);

    if(previous == nullptr)
    {
        previous = node;
        prevVal = 0;
    }
    else
    {
        int temp = previous->data;
        previous->data = node->data + prevVal;
        previous = node;
        prevVal = temp;
    }

    toInorderPredecessorSuccessorUtil(node->right, previous, prevVal);
}