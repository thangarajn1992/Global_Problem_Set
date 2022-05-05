#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Trees.h"
using namespace std;
/*
Binary Search Tree Operations:
    Insert New node into Binary Search Tree
    Search Binary Search Tree for given key

Traversals:
    Generate Postorder from preorder
    Find Inorder Sucessor node for a given node

Tree Construction:
    Construct BST from preorder

*/

class BinarySearchTreeNode
{
public:
    int data;
    BinarySearchTreeNode * left;
    BinarySearchTreeNode * right;
    BinarySearchTreeNode * parent;

    BinarySearchTreeNode(int value) : data {value}, left(nullptr), right(nullptr), parent(nullptr) {}
}; 

class BinarySearchTree{
private:
    BinarySearchTreeNode *root;

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTreeNode* getRoot();
    void Insert(int data);
    BinarySearchTreeNode* Search(int key);

    void preorderRecurisve(BinarySearchTreeNode *node, vector<int> &preorder);
    void inorderRecursive(BinarySearchTreeNode *node, vector<int> &inorder);
    void postorderRecursive(BinarySearchTreeNode *node, vector<int> &postorder);

    void constructBSTFromPreorderRecursive(vector<int> &pre);
    BinarySearchTreeNode *BSTFromPreUtil(vector<int> &pre, int &preIndex,
                                         int start, int end);
    void constructBSTFromPreorderIterative(vector<int> &pre);

    vector<int> BSTPostorderFromPreorder(vector<int> &pre);
    void BSTPostorderFromPreorderUtil(vector<int> &pre, int &preIndex,
                                     int rangeStart, int rangeEnd, vector<int> &post);

    BinarySearchTreeNode* getInorderSucessor(BinarySearchTreeNode *node);

    int NumberOfBSTsForNkeys(int n);
};



#endif