#include "Binary_Tree.h"

using namespace std;

/*  
    Reverse nodes in alternate level in a Perfect Binary Tree - Two Inorder Traversal   
        We do inorder traversal and store the values in odd level in the stack
        When we run inorder traversal again, replace the values in odd level by popping from stack
*/
void 
BinaryTree::reverseNodesInAlternateLevelPerfectBinaryTreeTwoTraversal()
{
    if(root == nullptr)
        return;
    
    stack<int> inorder;
    inorderOddLevelFillStack(root, inorder, 0);
    inorderSwapOddLevelFromStack(root, inorder, 0);
}

void 
BinaryTree::inorderOddLevelFillStack(BinaryTreeNode *node, stack<int> &inorder, int level)
{
    if(node == nullptr)
        return;
    
    inorderOddLevelFillStack(node->left, inorder, level+1);

    if(level % 2 == 1) // Only push into stack for odd level
        inorder.push(node->data);
    
    inorderOddLevelFillStack(node->right, inorder, level+1);
}

void 
BinaryTree::inorderSwapOddLevelFromStack(BinaryTreeNode *node, stack<int> &inorder, int level)
{
    if(node == nullptr)
        return;
    
    inorderSwapOddLevelFromStack(node->left, inorder, level+1);

    if(level % 2 == 1) // Only swap for odd Level
    {
        node->data = inorder.top();
        inorder.pop();
    }

    inorderSwapOddLevelFromStack(node->right, inorder, level+1);
}

/*  
    Reverse nodes in alternate level in a Perfect Binary Tree - Single Swap Traversal
        At even level, we swap the right and left node data. i.e indirectly it changes the
        node values in odd level.
*/  
void 
BinaryTree::reverseNodesInAlternateLevelPerfectBinaryTreeSingleSwapTraversal()
{
    if(root == nullptr)
        return;
    
    reverseAlternateLevelSwapperTraversal(root->left, root->right, 0);
}

void 
BinaryTree::reverseAlternateLevelSwapperTraversal(BinaryTreeNode *left, BinaryTreeNode *right, int level)
{
    if(left == nullptr || right == nullptr)
        return;
    
    if(level % 2 == 0)
    {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
    }

    reverseAlternateLevelSwapperTraversal(left->left, right->right, level+1);
    reverseAlternateLevelSwapperTraversal(left->right, right->left, level+1);
}