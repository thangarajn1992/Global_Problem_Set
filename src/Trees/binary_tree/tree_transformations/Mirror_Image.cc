#include "Binary_Tree.h"

using namespace std;

/* Convert to its Mirror Image - Recursive */
void 
BinaryTree::toMirrorRecursive(BinaryTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }
    else
    {
        toMirrorRecursive(node->left);
        toMirrorRecursive(node->right);

        BinaryTreeNode *swapper = node->left;
        node->left = node->right;
        node->right = swapper;
    }
}

/* Convert to its Mirror Image - Iterative */
void 
BinaryTree::toMirrorIterative()
{
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> BTNodeQueue;
    BTNodeQueue.push(root);

    while(BTNodeQueue.empty() == false)
    {
        int queueSize = BTNodeQueue.size();
        while(queueSize > 0)
        {
            BinaryTreeNode *curr = BTNodeQueue.front();
            BTNodeQueue.pop();
            queueSize--;

            if(curr->left != nullptr)
                BTNodeQueue.push(curr->left);
            if(curr->right != nullptr)
                BTNodeQueue.push(curr->right);

            BinaryTreeNode *swapper = curr->left;
            curr->left = curr->right;
            curr->right = swapper;
        }
    }
}
