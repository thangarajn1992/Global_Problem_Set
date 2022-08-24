#include "Binary_Tree.h"

using namespace std;

/* LevelOrder Traversal or Breadth First Traversal using Queue */
void 
BinaryTree::levelorderQueue(BinaryTreeNode *root)
{
    clearLevelorder();
    queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(root);

    if(root == nullptr)
        return;

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *curr = nodeQueue.front();
        nodeQueue.pop();
        levelorder.push_back(curr->data);

        if(curr->left != nullptr)
            nodeQueue.push(curr->left);

        if(curr->right != nullptr)
            nodeQueue.push(curr->right);
    }
}

/* Reverse LevelOrder Traversal using Queue */
void
BinaryTree::levelorderReverseQueue(BinaryTreeNode *root)
{
    clearLevelorderReverse();
    queue<BinaryTreeNode*> nodeQueue;
    stack<BinaryTreeNode*> nodeStack;

    if(root == nullptr)
        return;
    
    nodeQueue.push(root);
    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *curr = nodeQueue.front();
        nodeQueue.pop();

        nodeStack.push(curr);

        /* Push right child first */
        if(curr->right != nullptr)
            nodeQueue.push(curr->right);
        
        if(curr->left != nullptr)
            nodeQueue.push(curr->left);
    }

    while(nodeStack.empty() == false)
    {
        levelorderReverse.push_back(nodeStack.top()->data);
        nodeStack.pop();
    }
}

/*  Levelorder Left/Right alternate in same Level for Perfect Binary Tree (top to Bottom level) */
/*  Algorithm:
    Instead of processing ONE node at a time, we will process TWO nodes at a time.
    And while pushing children into queue, the enqueue order will be: 
        1st node’s left child, 
        2nd node’s right child, 
        1st node’s right child and 
        2nd node’s left child.
*/
void 
BinaryTree::levelorderSameLevelAlternateToptoBottomLevelQueue(BinaryTreeNode *root)
{   
    clearLevelorderSameLevelAlternateToptoBottom();
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> nodeQueue;

    levelorderSameLevelAlternateToptoBottom.push_back(root->data);
    
    if(root->left != nullptr) /* Dont need to check for right, since it is perfect binary tree */
    {
        levelorderSameLevelAlternateToptoBottom.push_back(root->left->data);
        levelorderSameLevelAlternateToptoBottom.push_back(root->right->data);
        nodeQueue.push(root->left);
        nodeQueue.push(root->right);
    }

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode* first = nodeQueue.front(); nodeQueue.pop();
        BinaryTreeNode* second = nodeQueue.front(); nodeQueue.pop();

        levelorderSameLevelAlternateToptoBottom.push_back(first->left->data);
        levelorderSameLevelAlternateToptoBottom.push_back(second->right->data);
        levelorderSameLevelAlternateToptoBottom.push_back(first->right->data);
        levelorderSameLevelAlternateToptoBottom.push_back(second->left->data);

        if(first->left->left != nullptr)
        {
            nodeQueue.push(first->left);
            nodeQueue.push(second->right);
            nodeQueue.push(first->right);
            nodeQueue.push(second->left);
        }
    }  
}

/* Levelorder Left/Right alternate in same level for Perfect Binary Tree (Bottom to Top level) */
void 
BinaryTree::levelorderSameLevelAlternateBottomtoTopLevelQueue(BinaryTreeNode *root)
{
    clearLevelorderSameLevelAlternateBottomtoTop();
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> nodeQueue;
    stack<BinaryTreeNode*> nodeStack;

    nodeStack.push(root);

    if(root->left != nullptr) /* No need to check for right since it is perfect BinaryTree */
    {
        nodeQueue.push(root->left);
        nodeQueue.push(root->right);

        /* Push right first in the stack */
        nodeStack.push(root->right);
        nodeStack.push(root->left);
    }

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *first = nodeQueue.front(); nodeQueue.pop();
        BinaryTreeNode *second = nodeQueue.front(); nodeQueue.pop();

        nodeStack.push(second->left);
        nodeStack.push(first->right);
        nodeStack.push(second->right);
        nodeStack.push(first->left);

        if(first->left->left != nullptr)
        {
            nodeQueue.push(first->right);
            nodeQueue.push(second->left);
            nodeQueue.push(first->left);
            nodeQueue.push(second->right);
        }
    }

    while(nodeStack.empty() == false)
    {
        levelorderSameLevelAlternateBottomtoTop.push_back(nodeStack.top()->data);
        nodeStack.pop();
    }
}