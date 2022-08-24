#include "Binary_Tree.h"

using namespace std;

/*  
    Find density of Binary Tree
    Density: Size/Height
*/
float 
BinaryTree::density()
{
    if(root == nullptr)
        return 0;
    
    int size = 0;
    int height = findHeightAndSize(root, size);

    return (float)size/height;
}

int 
BinaryTree::findHeightAndSize(BinaryTreeNode *node, int &size)
{
    if(node == nullptr)
        return 0;
    
    size++;

    return max(findHeightAndSize(node->left, size), 
                findHeightAndSize(node->right, size)) + 1;
}