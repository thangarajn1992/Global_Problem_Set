#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createCompleteBTFromLevelOrderArray(vector<int> &levelorderArray)
{
    root = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 0);
}

BinaryTreeNode*
BinaryTree::createCompleteBTFromLevelOrderArrayUtil(vector<int> &levelorderArray, int index)
{
    if(index >= levelorderArray.size())
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(levelorderArray[index]);
    node->left = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 2*index + 1);
    node->right = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 2*index + 2);

    return node;
}