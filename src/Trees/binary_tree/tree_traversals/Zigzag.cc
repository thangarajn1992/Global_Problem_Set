#include "Binary_Tree.h"

using namespace std;

/* ZigZag Traversal using Queue */
void 
BinaryTree::zigzagQueue()
{
    clearZigzag();
    queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(root);
    bool oddLevel = true;

    if(root == nullptr)
        return;

    while(nodeQueue.empty() == false)
    {
        vector<int> level;
        int queueSize = nodeQueue.size();
        while(queueSize > 0)
        {
            BinaryTreeNode* curr = nodeQueue.front();
            nodeQueue.pop();
            queueSize--;

            if(curr->left != nullptr)
            {
                nodeQueue.push(curr->left);
            }
            if(curr->right != nullptr)
            {
                nodeQueue.push(curr->right);
            }

            level.push_back(curr->data);
        }
        int levelSize = level.size();
        if(oddLevel) /* left to right */
        {
            zigzag.insert(zigzag.end(), level.begin(), level.end());

        }
        else /* right to left */
        {
            zigzag.insert(zigzag.end(), level.rbegin(), level.rend());
        }
        oddLevel = !oddLevel;
    }
}

/* ZigZag Traversal using deque (double ended queue)*/
void 
BinaryTree::zigzagDeque(BinaryTreeNode *root)
{
    clearZigzag();
    deque<BinaryTreeNode*> nodeDeque;
    bool oddLevel = true;

    if(root == nullptr)
        return;

    nodeDeque.push_front(root);
    zigzag.push_back(root->data);

    while(nodeDeque.empty() == false)
    {
        int dequeSize = nodeDeque.size();
        while(dequeSize > 0)
        {
            BinaryTreeNode *curr = nullptr;
            if(oddLevel == true)
            {
                /* For OddLevel, read from front and
                    Insert next level nodes in the back */
                curr = nodeDeque.front();
                nodeDeque.pop_front();
                if(curr->right != nullptr)
                {
                    zigzag.push_back(curr->right->data);
                    nodeDeque.push_back(curr->right);
                }
                if(curr->left != nullptr)
                {
                    zigzag.push_back(curr->left->data); 
                    nodeDeque.push_back(curr->left);
                }
            }
            else
            {
                /* For evenLevel, read from back and
                    Insert next level nodes in the front */
                curr = nodeDeque.back();
                nodeDeque.pop_back();
                if(curr->left != nullptr)
                {
                    zigzag.push_back(curr->left->data);
                    nodeDeque.push_front(curr->left);
                }
                if(curr->right != nullptr)
                {
                    zigzag.push_back(curr->right->data);
                    nodeDeque.push_front(curr->right);
                }
            }
            dequeSize--;
        }
        oddLevel = !oddLevel;
    }
}

/* ZigZag Traversal using Two Stacks */
void 
BinaryTree::zigzagTwoStacks()
{
    clearZigzag();
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
            zigzag.push_back(curr->data);

            if(curr->left != nullptr)
                evenLevelStack.push(curr->left);

            if(curr->right != nullptr)
                evenLevelStack.push(curr->right);
        }

        while(evenLevelStack.empty() == false)
        {
            BinaryTreeNode *curr = evenLevelStack.top();
            evenLevelStack.pop();
            zigzag.push_back(curr->data);

            if(curr->right != nullptr)
                oddLevelStack.push(curr->right);

            if(curr->left != nullptr)
                oddLevelStack.push(curr->left);
        }
    }
}