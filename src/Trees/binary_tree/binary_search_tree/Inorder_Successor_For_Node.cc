#include "Binary_Search_Tree.h"

using namespace std;

/*  Find Inorder successor for a give Node 
    Algorithm:
    1. If node->right != null, then successor is min value of right sub-tree
    2. else, sucessor is in the ancestor. The nearby ancestor whose left sub-tree contains
        this node
*/
BinarySearchTreeNode*
BinarySearchTree::getInorderSucessor(BinarySearchTreeNode *node)
{
    if(node == nullptr) // invalid input
        return node;
    
    if(node->right != nullptr)
    {
        /* Find minimum value in the right sub-tree (i.e left most node) */
        BinarySearchTreeNode* curr = node->right;
        while(curr->left != nullptr)
            curr = curr->left;
        return curr;
    }
    else
    {
        /* Find the nearby ancestor whose left subtree has this node */
        BinarySearchTreeNode* successor = nullptr; /* To take care of scenario where there is no sucessor */
        BinarySearchTreeNode* curr = root;
        while(curr != nullptr)
        {
            if(curr->data > node->data)
            {
                successor = curr;
                curr = curr->left;
            }
            else if(curr->data < node->data)
            {
                curr = curr->right;
            }
            else
                break;
        }
        return successor;
    }
}