#include "Binary_Tree.h"

using namespace std;

/*  Modify Binary Tree such that preorder traversal can be formed using right pointers alone:
    Algorithm: 
        Normal iterative preorder traversal, we keep track of predecessor and update 
        predecessor->right to current node.    
*/
void 
BinaryTree::convertTreePreorderThroughRightPointers()
{
    if(root == nullptr)
        return;
    
    BinaryTreeNode* pre = nullptr;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);

    while(nodeStack.empty() == false)
    {
        BinaryTreeNode *curr = nodeStack.top();
        nodeStack.pop();

        if(curr->right != nullptr)
            nodeStack.push(curr->right);
        if(curr->left != nullptr)
            nodeStack.push(curr->left);
        
        if(pre != nullptr)
            pre->right = curr;
        
        pre = curr;
    }
}