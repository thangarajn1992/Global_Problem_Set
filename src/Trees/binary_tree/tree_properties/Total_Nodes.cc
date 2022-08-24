#include "Binary_Tree.h"

using namespace std;

int 
BinaryTree::getTotalNodes(BinaryTreeNode *node)
{
    if(node == nullptr)
        return 0;
    
    return 1 + getTotalNodes(node->left) + getTotalNodes(node->right);
}
