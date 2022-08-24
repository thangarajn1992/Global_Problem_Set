#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createBTFromAncestorMatrix(vector<vector<int>> &ancestor)
{
    vector<vector<int>> totalDescendents(ancestor.size());
    vector<bool> parentSet(ancestor.size(), false);
    vector<BinaryTreeNode*> nodes(ancestor.size(), nullptr);

    for(int row = 0; row < ancestor.size(); row++)
    {
        int sum = 0;
        for(int col = 0; col < ancestor[row].size(); col++)
        {
            sum += ancestor[row][col];
        }
        totalDescendents[sum].push_back(row);
    }

    for(int i = 0; i < totalDescendents.size(); i++)
    {
        for(int nodeNum = 0; nodeNum < totalDescendents[i].size(); nodeNum++)
        {
            int nodeVal = totalDescendents[i][nodeNum];
            nodes[nodeVal] = new BinaryTreeNode(nodeVal);
            root = nodes[nodeVal];
            if(i != 0) // non-leaf Nodes
            {
                for(int col = 0; col < ancestor[nodeVal].size(); col++)
                {
                    if(ancestor[nodeVal][col] == 1 && parentSet[col] == false)
                    {
                        if(nodes[nodeVal]->left == nullptr)
                            nodes[nodeVal]->left = nodes[col];
                        else if(nodes[nodeVal]->right == nullptr)
                            nodes[nodeVal]->right = nodes[col];
                        parentSet[col] = true;
                    }
                }
            }
        }   
    }
}