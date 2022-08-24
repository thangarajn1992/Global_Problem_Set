#include "Binary_Tree.h"

using namespace std;

/* Create Binary Tree from Parent Array Representation */
void 
BinaryTree::createBTFromParentArray(vector<int> &parentArray)
{
    int totalNodes = parentArray.size();
    vector<BinaryTreeNode*> createdNodes(totalNodes, nullptr);

    for(int i = 0; i < totalNodes; i++)
    {
        createNode(i, createdNodes, parentArray);
    }
}

void 
BinaryTree::createNode(int nodeNum, vector<BinaryTreeNode*> &createdNodes, vector<int> &parentArray)
{
    if(createdNodes[nodeNum] != nullptr)
        return;

    createdNodes[nodeNum] = new BinaryTreeNode(nodeNum);

    if(parentArray[nodeNum] == -1)
    {
        root = createdNodes[nodeNum];
        return;
    }

    if(createdNodes[parentArray[nodeNum]] == nullptr)
    {
        createNode(parentArray[nodeNum], createdNodes, parentArray);
    }

    if(createdNodes[parentArray[nodeNum]]->left == nullptr)
        createdNodes[parentArray[nodeNum]]->left = createdNodes[nodeNum];
    else
        createdNodes[parentArray[nodeNum]]->right = createdNodes[nodeNum];
}