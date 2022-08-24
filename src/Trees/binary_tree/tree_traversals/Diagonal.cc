#include "Binary_Tree.h"

using namespace std;

/* Diagonal Traversal using Queue 
    Time Complexity: O(N)
    Space Complexity : O(N)
*/
void 
BinaryTree::diagonalQueue(BinaryTreeNode* root)
{
    clearDiagonal();
    queue<BinaryTreeNode*> BTNodeQueue;
    
    if(root == nullptr)
        return;

    BTNodeQueue.push(root);

    while(BTNodeQueue.empty() == false)
    {
        int queueSize = BTNodeQueue.size();

        while(queueSize > 0)
        {
            BinaryTreeNode *curr = BTNodeQueue.front();
            BTNodeQueue.pop();
            queueSize--;

            while(curr)
            {
                diagonal.push_back(curr->data);
                if(curr->left != nullptr)
                {
                    BTNodeQueue.push(curr->left);
                }
                curr = curr->right;
            }
        }
    }
}