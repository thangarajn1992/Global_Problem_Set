#include "Binary_Tree.h"

using namespace std;

/*  Convert BT to a tree which holds Children Sum Property  */
void
BinaryTree::convertBTToChildSumBT(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->left == nullptr && node->right == nullptr)
        return;
    
    convertBTToChildSumBT(node->left);
    convertBTToChildSumBT(node->right);

    int childSum = 0;
    if(node->left != nullptr)
        childSum += node->left->data;
    if(node->right != nullptr)
        childSum += node->right->data;
    
    int diff = childSum - node->data;

    if(diff >= 0)
        node->data += diff;
    else
        convertBTToChildSumBTIncrement(node, -diff);
}

void 
BinaryTree::convertBTToChildSumBTIncrement(BinaryTreeNode *node, int increment_value)
{
    if(node->left != nullptr)
    {
        node->left->data += increment_value;
        convertBTToChildSumBTIncrement(node->left, increment_value);
    }
    else if(node->right != nullptr)
    {
        node->right->data += increment_value;
        convertBTToChildSumBTIncrement(node->right, increment_value);
    }
}
