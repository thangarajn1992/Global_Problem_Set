#include "Binary_Tree.h"

using namespace std;

void
BinaryTree::createSplBTGreaterParent(vector<int> &in)
{
    root = createSplBTGreaterParentUtil(in, 0, in.size() - 1);
}

BinaryTreeNode*
BinaryTree::createSplBTGreaterParentUtil(vector<int>&in,
                                         int inStartIndex,
                                         int inEndIndex)
{   
    if(inStartIndex > inEndIndex)
        return nullptr;
    
    int maxIndex = max_element(in.begin() + inStartIndex, in.begin() + inEndIndex + 1) -
                    in.begin();
    
    BinaryTreeNode *node = new BinaryTreeNode(in[maxIndex]);

    if(inStartIndex == inEndIndex)
        return node;
    
    node->left = createSplBTGreaterParentUtil(in, inStartIndex, maxIndex-1);
    node->right = createSplBTGreaterParentUtil(in, maxIndex+1, inEndIndex);
    
    return node;
}