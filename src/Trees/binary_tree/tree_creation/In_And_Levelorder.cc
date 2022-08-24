#include "Binary_Tree.h"

using namespace std;

void
BinaryTree::createBTFromInandLevelorder()
{
    unordered_map<int,int> levelIndexMap;
    for(int i = 0; i < levelorder.size(); i++)
        levelIndexMap[levelorder[i]] = i;
    
    root = createBTFromInandLevelorderUtil(levelIndexMap, 0, levelorder.size()-1);
}

BinaryTreeNode*
BinaryTree::createBTFromInandLevelorderUtil(unordered_map<int,int> &levelIndexMap, 
                                            int inStart,
                                            int inEnd)
{
    if(inStart > inEnd)
        return nullptr;
    
    /*  Find the element in the given inorder range, which has
        least index in levelorder */
    int leastLevelIndex = INT_MAX;
    int inIndexWithLeastLevelIndex = inStart;
    for(int i = inStart; i <= inEnd; i++)
    {
        int currLevelIndex = levelIndexMap[inorder[i]];
        if(currLevelIndex < leastLevelIndex)
        {
            leastLevelIndex = currLevelIndex;
            inIndexWithLeastLevelIndex = i;
        }
    }
    
    BinaryTreeNode *node = new BinaryTreeNode(inorder[inIndexWithLeastLevelIndex]);

    node->left = createBTFromInandLevelorderUtil(levelIndexMap, inStart, inIndexWithLeastLevelIndex-1);
    node->right = createBTFromInandLevelorderUtil(levelIndexMap, inIndexWithLeastLevelIndex+1, inEnd);
    
    return node;
}