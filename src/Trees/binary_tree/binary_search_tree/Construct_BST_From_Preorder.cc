#include "Binary_Search_Tree.h"

using namespace std;

void 
BinarySearchTree::constructBSTFromPreorderRecursive(vector<int> &pre)
{
    int preIndex = 0;
    root = BSTFromPreUtil(pre, preIndex, INT_MIN, INT_MAX);
}

BinarySearchTreeNode*
BinarySearchTree::BSTFromPreUtil(vector<int> &pre, int &preIndex,
                                int start, int end)
{
    /*  If all index in preorder are processed or
        This value doesnt fit in the given range
    */
    if(preIndex == pre.size() ||
       pre[preIndex] <= start || pre[preIndex] >= end)
    {
        return nullptr;
    }

    int key = pre[preIndex]; 
    BinarySearchTreeNode *node = new BinarySearchTreeNode(key);
    preIndex++;
        
    node->left = BSTFromPreUtil(pre, preIndex, start, key);
    node->right = BSTFromPreUtil(pre, preIndex, key, end);

    return node;
}
    
void 
BinarySearchTree::constructBSTFromPreorderIterative(vector<int> &pre)
{
    stack<BinarySearchTreeNode*> BSTNodeStack;

    root = new BinarySearchTreeNode(pre[0]);
    BSTNodeStack.push(root);

    for(int num = 1; num < pre.size(); num++)
    {
        BinarySearchTreeNode *curr = nullptr;
        /* Pop all lesser elements from stack and put this node as right node */
        while(BSTNodeStack.empty() == false &&
              pre[num] > BSTNodeStack.top()->data)
        {
            curr = BSTNodeStack.top();
            BSTNodeStack.pop();
        }
        if(curr != nullptr)
        {
            curr->right = new BinarySearchTreeNode(pre[num]);
            BSTNodeStack.push(curr->right);
        }
        else /* If no element from the stack is lesser, then this is left node */
        {
            BSTNodeStack.top()->left = new BinarySearchTreeNode(pre[num]);
            BSTNodeStack.push(BSTNodeStack.top()->left);
        }
    }
}