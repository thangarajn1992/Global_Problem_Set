#include "Binary_Tree.h"

using namespace std;


vector<vector<int>>
BinaryTree::getAncestorMatrixBacktracking()
{
    ancestorMatrix.clear();
    totalNodes = getTotalNodes(root);
    ancestorMatrix.resize(totalNodes, vector<int>(totalNodes, 0));
    vector<int> ancestors;
    
    getAncestorMatrixBacktrackingUtil(root, ancestors);

    return ancestorMatrix;
}

void
BinaryTree::getAncestorMatrixBacktrackingUtil(BinaryTreeNode* node,
                                              vector<int> &ancestors)
{
    if(node == nullptr)
        return;

    for(int ancestor : ancestors)
    {   
        ancestorMatrix[ancestor][node->data] = 1;
    }
    ancestors.push_back(node->data);
    getAncestorMatrixBacktrackingUtil(node->left, ancestors);
    getAncestorMatrixBacktrackingUtil(node->right, ancestors);
    ancestors.pop_back();
}

vector<vector<int>>
BinaryTree::getAncestorMatrixTransitiveClosure()
{
    ancestorMatrix.clear();
    totalNodes = getTotalNodes(root);
    ancestorMatrix.resize(totalNodes, vector<int>(totalNodes, 0));

    /*  Find adjacency Matrix for tree similar to graph 
        Where parent->child is considered as path */
    getAncestorMatrixTransitiveClosureAdjFill(root, -1);

    /* From adjacency matrix, convert it into reachability matrix
       by finding the transitive closure of this matrix */
    for(int i = 0; i < totalNodes; i++)
    {
        for(int j = 0; j < totalNodes; j++)
        {
            for(int k = 0; k < totalNodes; k++)
            {
                ancestorMatrix[j][k] = ancestorMatrix[j][k] ||
                                       (ancestorMatrix[j][i] && ancestorMatrix[i][k]);
            }
        }
    }

    return ancestorMatrix;
}

void 
BinaryTree::getAncestorMatrixTransitiveClosureAdjFill(BinaryTreeNode *node,
                                                      int parentValue)
{
    if(node == nullptr)
        return;
    
    if(parentValue != -1)
        ancestorMatrix[parentValue][node->data] = 1;
    
    getAncestorMatrixTransitiveClosureAdjFill(node->left, node->data);
    getAncestorMatrixTransitiveClosureAdjFill(node->right, node->data);
}
