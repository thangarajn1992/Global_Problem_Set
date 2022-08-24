#include "Binary_Tree.h"

using namespace std;

/* Check whether any path has sum of all nodes in that path equal to given target */
bool
BinaryTree::hasPathSum(BinaryTreeNode* node, int target)
{
    if(node == nullptr)
        return false;
    
    if(node->left == nullptr && node->right == nullptr)
    {
       return node->data == target;
    }

    return  hasPathSum(node->left, target - node->data) ||
            hasPathSum(node->right, target - node->data);
}
