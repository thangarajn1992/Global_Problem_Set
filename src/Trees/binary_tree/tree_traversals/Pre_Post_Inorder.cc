#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::PostPreInOrderInOneFlowRecursive(BinaryTreeNode* node)
{
    // Return if root is NULL
    if (node == nullptr)
        return;

    // Pushes the root data into the pre order vector
    preorder.push_back(node->data);

    // Recursively calls for the left node
    PostPreInOrderInOneFlowRecursive(
        node->left);

    // Pushes node data into the inorder vector
    inorder.push_back(node->data);

    // Recursively calls for the right node
    PostPreInOrderInOneFlowRecursive(
        node->right);

    // Pushes the node data into the Post Order vector
    postorder.push_back(node->data);
}