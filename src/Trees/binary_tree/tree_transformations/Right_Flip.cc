#include "Binary_Tree.h"

using namespace std;

/* 
    Right Flip Binary Tree
    1. Leftmost node becomes Root
    2. Its parent becomes its right child
    3. Its right sibling becomes its left child
    4. Same should be repeated for all left most nodes recursively
*/
BinaryTreeNode* 
BinaryTree::toRightFlip(BinaryTreeNode *node)
{
    if(node == nullptr)
        return node;
    if(node->left == nullptr && node->right == nullptr)
        return node;
    
    BinaryTreeNode* flippedRoot = toRightFlip(node->left);

    node->left->left = node->right;
    node->left->right = node;
    node->left = nullptr;
    node->right = nullptr;
    
    return flippedRoot;
}