#include "Binary_Tree.h"

using namespace std;

bool 
BinaryTree::isSymmetric()
{
    return isSymmetricUtil(root, root);   
}    

bool 
BinaryTree::isSymmetricUtil(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if(node1 == nullptr && node2 == nullptr)                
        return true;
    
    if(node1 != nullptr && node2 != nullptr && 
       node1->data == node2->data &&
       isSymmetricUtil(node1->left, node2->right) &&
       isSymmetricUtil(node1->right, node2->left))
    {
        return true;
    }

    return false;
}