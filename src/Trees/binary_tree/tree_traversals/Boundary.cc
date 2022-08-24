#include "Binary_Tree.h"

using namespace std;

/* Boundary Traversal */
/*  
    1. Print all the left side Boundary in top-down
    2. Print all leaves from left-subtree in left-right
    3. Print all leaves from right-subtree in left-right
    4. Print all the right side boundary in bottom-up
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
void 
BinaryTree::boundaryTraversal()
{
    clearBoundary();
    if(root == nullptr)
        return;

    boundary.push_back(root->data);

    /* Left Boundary without leaves */
    leftBoundary(root->left);

    /* Leaves of left sub-tree */
    leaves(root->left);
    /* Leaves of right sub-tree */
    leaves(root->right);

    /* Right Boundary without leaves */
    rightBoundary(root->right);
}

void 
BinaryTree::leftBoundary(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->left != nullptr)
    {
        boundary.push_back(node->data);
        leftBoundary(node->left);
    }
    else if(node->right != nullptr)
    {
        boundary.push_back(node->data);
        leftBoundary(node->right);
    }
    else{ 
        /* Skip leaf nodes */
    }
}

void 
BinaryTree::rightBoundary(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->right != nullptr)
    {
        rightBoundary(node->right);
        boundary.push_back(node->data);
    }
    else if(node->left != nullptr)
    {
        rightBoundary(node->left);
        boundary.push_back(node->data);
    }
    else{
        /* skip the leaf nodes */
    }
}

void 
BinaryTree::leaves(BinaryTreeNode *node)
{
    if(node->left == nullptr && node->right == nullptr)
    {
        boundary.push_back(node->data);
        return;
    }

    if(node->left != nullptr)
    {
        leaves(node->left);
    }

    if(node->right != nullptr)
    {
        leaves(node->right);
    }
}