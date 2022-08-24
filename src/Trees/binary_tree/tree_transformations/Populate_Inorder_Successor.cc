#include "Binary_Tree.h"

using namespace std;

/* Populate inorder successor for each node in Binary Tree */
void 
BinaryTree::populateInorderSuccessor(BinaryTreeNode *node)
{
    static BinaryTreeNode* inorderSucessor = nullptr;

    if(node != nullptr)
    {
        populateInorderSuccessor(node->right);

        node->inorderSucessor = inorderSucessor;

        inorderSucessor = node;

        populateInorderSuccessor(node->left);
    }
}