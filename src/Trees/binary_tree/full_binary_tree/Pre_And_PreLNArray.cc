#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createFullBTFromPreandPreLNArrayRecursive(vector<int> &pre, vector<char> &preLN)
{
    int preIndex = 0;
    root = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
}

BinaryTreeNode* 
BinaryTree::createFullBTFromPreandPreLNArrayRecursiveUtil(vector<int> &pre,
                                                          vector<char> &preLN,
                                                          int &preIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(preLN[preIndex-1] == 'N')
    {
        node->left = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
        node->right = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
    }
    return node;
}
    
void 
BinaryTree::createFullBTFromPreandPreLNArrayIterative(vector<int> &pre, vector<char> &preLN)
{
    if(pre.size() == 0)
        return;
    
    stack<BinaryTreeNode*> nodeStack;

    root = new BinaryTreeNode(pre[0]);
    if(preLN[0] == 'N')
        nodeStack.push(root);
    
    for(int preIndex = 1; preIndex < pre.size(); preIndex++)
    {
        BinaryTreeNode* curr = new BinaryTreeNode(pre[preIndex]);
        // If top->left is free, insert there
        if(nodeStack.top()->left == nullptr)
        {
            nodeStack.top()->left = curr;
        }
        else if(nodeStack.top()->right == nullptr) // if top->right is free, insert there
        {
            nodeStack.top()->right = curr;
        }
        else // if both are filled, then keep poping until we find free place
        {
            while(nodeStack.top()->left != nullptr && nodeStack.top()->right != nullptr)
                nodeStack.pop();
            
            nodeStack.top()->right = curr;
        }
        if(preLN[preIndex] == 'N')
            nodeStack.push(curr);
    }
}