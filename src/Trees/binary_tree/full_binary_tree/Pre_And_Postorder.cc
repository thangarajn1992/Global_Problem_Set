#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createFullBTfromPreAndPostorder(vector<int> &pre, 
                                            vector<int> &post)
{
    int preIndex = 0;
    unordered_map<int,int> postIndexMap;
    for(int postIndex = 0; postIndex < post.size(); postIndex++)
    {
        postIndexMap[post[postIndex]] = postIndex;
    }
    root = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, 0, post.size()-1);
}

BinaryTreeNode* 
BinaryTree::createFullBTfromPreAndPostorderUtil(vector<int> &pre,
                                                unordered_map<int,int> &postIndexMap,
                                                int &preIndex,
                                                int postStartIndex,
                                                int postEndIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    if(postStartIndex > postEndIndex)
        return nullptr;
    
    BinaryTreeNode* node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(postStartIndex == postEndIndex) // Only one node in sub-tree, return this node
        return node;
    
    int postIndex = postIndexMap[pre[preIndex]];

    if(postIndex >= postStartIndex && postIndex <= postEndIndex)
    {
        node->left = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, postStartIndex, postIndex);
        /* postEndIndex - 1 is used, because postEndIndex will be the root at this iteration */
        node->right = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, postIndex+1, postEndIndex-1);
    }
    return node;
}
