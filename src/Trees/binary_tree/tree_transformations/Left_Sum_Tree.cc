#include "Binary_Tree.h"

using namespace std;

/* Node's data should contain Sum of its left sub-tree nodes */
int
BinaryTree::toLeftSumTree(BinaryTreeNode *node)
{
    if(node == nullptr)
        return 0;
    
    int leftSum = toLeftSumTree(node->left);
    int rightSum = toLeftSumTree(node->right);

    node->data += leftSum;

    return node->data + rightSum;
}