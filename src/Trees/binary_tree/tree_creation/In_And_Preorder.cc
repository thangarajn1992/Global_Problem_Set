#include "Binary_Tree.h"

using namespace std;


/*  Creating Binary Tree from given Inorder and Preorder
    Similar Logic can be used to get Postorder from In and Preorder */
void 
BinaryTree::createBTFromInandPreorder()
{
    int preIndex = 0;
    unordered_map<int,int> inorderIndexMap;
    for(int i = 0; i < inorder.size(); i++)
        inorderIndexMap[inorder[i]] = i;

    root = createBTFromInandPreorderUtil(inorderIndexMap, 0, preorder.size() - 1, preIndex);
}

BinaryTreeNode* 
BinaryTree::createBTFromInandPreorderUtil(unordered_map<int,int> &inorderIndexMap,
                                          int inStart,
                                          int inEnd,
                                          int &preIndex)
{
    if(inStart > inEnd)
        return nullptr;

    int rootIndex = inorderIndexMap[preorder[preIndex++]];

    BinaryTreeNode *node = new BinaryTreeNode(inorder[rootIndex]);

    node->left = createBTFromInandPreorderUtil(inorderIndexMap, inStart, rootIndex-1, preIndex);
    node->right = createBTFromInandPreorderUtil(inorderIndexMap, rootIndex+1, inEnd, preIndex);

    return node;
}