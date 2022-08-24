#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::reversePathToNode(int data)
{
    map<int,int> levelMap;
    int nextpos = 0;
    reversePathToNodeUtil(root, data, levelMap, 0, nextpos);
}

bool 
BinaryTree::reversePathToNodeUtil(BinaryTreeNode* node, int data, map<int,int>& levelMap, int level, int &nextpos)
{
    if(node == nullptr)
        return false;
    
    levelMap[level] = node->data;

    if(node->data == data)
    {
        node->data = levelMap[nextpos++];
        return true;
    }

    bool leftFound = false, rightFound = false;
    leftFound = reversePathToNodeUtil(node->left, data, levelMap, level+1, nextpos);
    if(leftFound == false)
        rightFound = reversePathToNodeUtil(node->right, data, levelMap, level+1, nextpos);
    
    if(leftFound || rightFound) // This node is in the interested path
    {
        node->data = levelMap[nextpos++];
        return true;
    }
    return false;
        
}
