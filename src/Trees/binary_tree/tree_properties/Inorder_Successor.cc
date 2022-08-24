#include "Binary_Tree.h"

using namespace std;

/* Get Inorder Successor for given node in Binary Tree */
BinaryTreeNode*
BinaryTree::getInorderSuccessor(BinaryTreeNode *node)
{
    BinaryTreeNode *successor = nullptr;
    getInorderSuccessorUtil(root, node, successor);
    return successor;
}

void 
BinaryTree::getInorderSuccessorUtil(BinaryTreeNode *root,
                                   BinaryTreeNode* node,
                                   BinaryTreeNode* &successor)
{
    static BinaryTreeNode *next = nullptr;

    if(root == nullptr)
        return;

    if(successor == nullptr) // If not found
    {
        getInorderSuccessorUtil(root->right, node, successor);

        if(root->data == node->data)
            successor = next;

        next = root;

        getInorderSuccessorUtil(root->left, node, successor);
    }
}