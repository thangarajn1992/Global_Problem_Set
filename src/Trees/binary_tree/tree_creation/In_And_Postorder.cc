#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createBTFromInandPostorderRecursive()
{
    int totalNodes = postorder.size();
    if(totalNodes == 0)
        return;

    unordered_map<int,int> inorderIndexMap;
    int postIndex = totalNodes - 1;
    for(int inIndex = 0; inIndex < totalNodes; inIndex++)
    {
        inorderIndexMap[inorder[inIndex]] = inIndex;
    }

    root = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, 0, totalNodes-1, postIndex);
}

BinaryTreeNode* 
BinaryTree::createBTFromInandPostorderRecursiveUtil(unordered_map<int,int> &inorderIndexMap,
                                                    int inStart,
                                                    int inEnd,
                                                    int &postIndex)
{
    if(inStart > inEnd)
        return nullptr;
    
    int inIndex = inorderIndexMap[postorder[postIndex]];
    postIndex--;

    BinaryTreeNode* node = new BinaryTreeNode(inorder[inIndex]);

    node->right = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, inIndex+1, inEnd, postIndex);
    node->left = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, inStart, inIndex-1, postIndex);

    return node;
}

void 
BinaryTree::createBTFromInandPostorderIterative()
{
    int inIndex = inorder.size()-1, postIndex = postorder.size()-1;
    BinaryTreeNode *prev = nullptr;
    stack<BinaryTreeNode*> nodeStack;
    bool left = false;

    if(postorder.size() == 0)
        return;
    
    prev = root = new BinaryTreeNode(postorder[postIndex]);
    postIndex--;
    nodeStack.push(root);

    while(postIndex >= 0)
    {
        if(nodeStack.empty() == false && inorder[inIndex] == nodeStack.top()->data)
        {
            prev = nodeStack.top();
            nodeStack.pop();
            inIndex--;
            left = true;
        }
        else
        {
            BinaryTreeNode* node = new BinaryTreeNode(postorder[postIndex]);
            postIndex--;
            nodeStack.push(node);
            if(left == true)
            {
                prev->left = node;
                prev = prev->left;
                left = false;
            }
            else
            {
                prev->right = node;
                prev = prev->right;
            }
        }
    }
}
