#include "Binary_Tree.h"

using namespace std;

/* Spiral Traversal using deque (double ended queue)*/
void 
BinaryTree::spiralDeque(BinaryTreeNode *root)
{
    clearSpiral();
    deque<BinaryTreeNode*> nodeDeque;
    bool oddLevel = true;

    if(root == nullptr)
        return;

    nodeDeque.push_front(root);
    spiral.push_back(root->data);

    while(nodeDeque.empty() == false)
    {
        int dequeSize = nodeDeque.size();
        while(dequeSize > 0)
        {
            BinaryTreeNode *curr = nullptr;
            if(oddLevel == false)
            {
                /* For EvenLevel, read from front and
                    Insert next level nodes in the back */
                curr = nodeDeque.front();
                nodeDeque.pop_front();
                if(curr->right != nullptr)
                {
                    spiral.push_back(curr->right->data);
                    nodeDeque.push_back(curr->right);
                }
                if(curr->left != nullptr)
                {
                    spiral.push_back(curr->left->data);
                    nodeDeque.push_back(curr->left);
                }
            }
            else
            {
                /* For OddLevel, read from back and
                    Insert next level nodes in the front */
                curr = nodeDeque.back();
                nodeDeque.pop_back();
                if(curr->left != nullptr)
                {
                    spiral.push_back(curr->left->data);
                    nodeDeque.push_front(curr->left);
                }
                if(curr->right != nullptr)
                {
                    spiral.push_back(curr->right->data); 
                    nodeDeque.push_front(curr->right);
                }
            }
            dequeSize--;
        }
        oddLevel = !oddLevel;
    }
}

/* Sprial Traversal using two stacks */
void 
BinaryTree::spiralTwoStacks()
{
    clearSpiral();
    stack<BinaryTreeNode*> oddLevelStack;
    stack<BinaryTreeNode*> evenLevelStack;

    if(root == nullptr)
        return;

    oddLevelStack.push(root);

    while(oddLevelStack.empty() == false || evenLevelStack.empty() == false)
    {
        while(oddLevelStack.empty() == false)
        {
            BinaryTreeNode *curr = oddLevelStack.top();
            oddLevelStack.pop();
            spiral.push_back(curr->data);

            if(curr->right != nullptr)
                evenLevelStack.push(curr->right);

            if(curr->left != nullptr)
                evenLevelStack.push(curr->left);
        }

        while(evenLevelStack.empty() == false)
        {
            BinaryTreeNode *curr = evenLevelStack.top();
            evenLevelStack.pop();
            spiral.push_back(curr->data);

            if(curr->left != nullptr)
                oddLevelStack.push(curr->left);

            if(curr->right != nullptr)
                oddLevelStack.push(curr->right);
        }
    }
    return;
}