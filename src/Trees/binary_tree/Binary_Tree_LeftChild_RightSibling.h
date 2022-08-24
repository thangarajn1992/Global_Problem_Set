#ifndef BINARY_TREE_LCHILD_RSIBLING
#define BINARY_TREE_LCHILD_RSIBLING

#include "Binary_Tree.h"

using namespace std;

class BinaryTreeLChildRSibling{
private:
    /* 
        left pointer is used to point first child
        right pointer is used to point the next sibling
    */
    BinaryTreeNode *root;
    vector<int> dfs;
    vector<int> bfs;
public:
    BinaryTreeNode* getRoot() { return root; }
    void setRoot(BinaryTreeNode *node) { root = node; }
    vector<int> getDFS() { return dfs; }
    vector<int> getBFS() { return bfs; }

    BinaryTreeNode* addNewNode(int value) 
    { 
        return root = new BinaryTreeNode(value);
    }

    BinaryTreeNode* addChild(BinaryTreeNode *node, int value)
    {
        if(node->left == nullptr)
            return node->left = new BinaryTreeNode(value);
        else
            return addSibling(node->left, value);
    }

    BinaryTreeNode *addSibling(BinaryTreeNode *node, int value)
    {
        while(node->right != nullptr)
            node = node->right;
        
        return node->right = new BinaryTreeNode(value);
    }

    void depthFirstSearch(BinaryTreeNode *node)
    {
        if(node == nullptr)
            return;
        
        dfs.push_back(node->data);
        depthFirstSearch(node->left);
        depthFirstSearch(node->right);
    } 

    void breadthFirstSearch()
    {
        bfs.clear();
        if(root == nullptr)
            return;
        
        queue<BinaryTreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(nodeQueue.empty() == false)
        {
            BinaryTreeNode *curr = nodeQueue.front();
            nodeQueue.pop();
            
            while(curr != nullptr)
            {
                bfs.push_back(curr->data);
                if(curr->left != nullptr)
                    nodeQueue.push(curr->left);
                curr = curr->right;
            }
        }
    }

    void convertToLChildRSibling(BinaryTreeNode *node)
    {
        if(node == nullptr)
            return;
        
        convertToLChildRSibling(node->left);
        convertToLChildRSibling(node->right);
        
        if(node->left == nullptr)
        {
            node->left = node->right;
        }
        else
        {
            node->left->right = node->right;
        }
        node->right = nullptr;
    }
};
#endif