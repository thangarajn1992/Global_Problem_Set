#include "Binary_Tree.h"

using namespace std;

/* 
    Check whether Tree has Children Sum Property:
    For every node, data value must be equal to sum of data values in left and right children. 
    Leaf Node always satisfies this property.
    Consider data value as 0 for NULL children.
*/
bool
BinaryTree::hasChildrenSumProperty(BinaryTreeNode *node)
{
    /* To take care of root itself is nullptr */
    if(node == nullptr) 
        return true;
    
    /* Leaf Node is always has this property */
    if(node->left == nullptr && node->right == nullptr)
        return true;

    int sum = 0;
    if(node->left != nullptr)
        sum += node->left->data;
    if(node->right != nullptr)
        sum += node->right->data;
    
    return (sum == node->data &&
            hasChildrenSumProperty(node->left) &&
            hasChildrenSumProperty(node->right));
}