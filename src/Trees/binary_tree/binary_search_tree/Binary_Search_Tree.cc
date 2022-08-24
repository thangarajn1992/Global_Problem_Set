#include "Binary_Search_Tree.h"

using namespace std;

BinarySearchTreeNode* 
BinarySearchTree::getRoot()    
{
    return root;
}

void 
BinarySearchTree::Insert(int data)
{
    if(root == nullptr)
    {
        root = new BinarySearchTreeNode(data);
       return;
    }
    BinarySearchTreeNode *node = root;
    while(true)
    {
        if(node->data < data)
        {
            if(node->right == nullptr)
            {
                node->right = new BinarySearchTreeNode(data);
                return;
            }
            else
            {
                node = node->right;
            }
        }
        else if(node->data > data)
        {
            if(node->left == nullptr)
            {
                node->left = new BinarySearchTreeNode(data);
                return;
            }
            else
            {
                node = node->left;
            }
        }
        else /* Node already exists with this value */
        {
            std::cout << "Error: Node Already exists in Binary Search Tree" << std::endl;
            return;
        }
    }
}  

BinarySearchTreeNode*
BinarySearchTree::Search(int key)
{
    BinarySearchTreeNode *curr = root;

    while(curr != nullptr)
    {
        if(curr->data == key)
            return curr;
        if(curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

    /* Basic Recursive Traversal: To print BSTs */
        /* Preorder Traversal - Recursive */
void
BinarySearchTree::preorderRecurisve(BinarySearchTreeNode *node, vector<int> &preorder)
{
    if(node == nullptr)
        return;

    preorder.push_back(node->data);
    preorderRecurisve(node->left, preorder);
    preorderRecurisve(node->right, preorder);
}

/* Inorder Traversal - Recursive */
void 
BinarySearchTree::inorderRecursive(BinarySearchTreeNode *node, vector<int> &inorder)
{
    if(node == nullptr)
        return;

    inorderRecursive(node->left, inorder);
    inorder.push_back(node->data);
    inorderRecursive(node->right, inorder);
}

/* Postorder Traversal - Recursive */
void 
BinarySearchTree::postorderRecursive(BinarySearchTreeNode *node, vector<int> &postorder)
{
    if(node == nullptr)
        return;

    postorderRecursive(node->left, postorder);
    postorderRecursive(node->right, postorder);
    postorder.push_back(node->data);
}