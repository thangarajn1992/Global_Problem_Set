#include "Binary_Tree.h"

using namespace std;


void 
BinaryTree::AllPossibleBinaryTreeForInorder(vector<int> &in)
{
    allBTsForInorder = GenerateBTForInorderUtil(in, 0, in.size()-1);
}

vector<BinaryTreeNode*>
BinaryTree::GenerateBTForInorderUtil(vector<int> &in, int start, int end)
{
    vector<BinaryTreeNode *> btrees;
    if(start > end)
    {
        btrees.push_back(nullptr);
        return btrees;
    }

    for(int i = start; i <= end; i++)
    {
        vector<BinaryTreeNode*> leftSubTrees = GenerateBTForInorderUtil(in, start, i-1);
        vector<BinaryTreeNode*> rightSubTrees = GenerateBTForInorderUtil(in, i+1, end);

        for(BinaryTreeNode* left : leftSubTrees)
        {
            for(BinaryTreeNode *right : rightSubTrees)
            {
                BinaryTreeNode *node = new BinaryTreeNode(in[i]);
                node->left = left;
                node->right = right;
                btrees.push_back(node);
            }
        }
    }
    return btrees;
}

void 
BinaryTree::printAllBTsForInorder()
{
    cout << "Preorder for All possible BTs for given Inorder: " << endl;
    for(int i = 0; i < allBTsForInorder.size(); i++)
    {
        preorderIterative(allBTsForInorder[i]);
        cout << "Tree " << i+1 << ": "  << getPreOrder();
    }
}