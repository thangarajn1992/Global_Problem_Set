#include "Binary_Tree.h"

using namespace std;

/*  Convert to its SumTree 
    Each node will contain sum of its left and right sub-tree
*/
int 
BinaryTree::toSumTree(BinaryTreeNode *node)
{
    if(node == nullptr)
        return 0;
    
    int old_value = node->data;

    node->data = toSumTree(node->left) + toSumTree(node->right);

    return node->data + old_value;
}