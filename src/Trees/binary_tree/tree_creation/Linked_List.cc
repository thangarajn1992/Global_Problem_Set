#include "Binary_Tree.h"

using namespace std;

/* Create Binary Tree from Linked List Representation */
BinaryTree::BinaryTree(SinglyLinkedList linkedListRep)
{   
    SinglyLinkedListNode *SLLNode = linkedListRep.getHead();
    queue<BinaryTreeNode*> nodeQueue;
    
    if(SLLNode == nullptr)
        return;

    root = new BinaryTreeNode(SLLNode->data);
    nodeQueue.push(root);
    SLLNode = SLLNode->next;

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *curr = nodeQueue.front();
        nodeQueue.pop();
        BinaryTreeNode *left = nullptr;
        BinaryTreeNode *right = nullptr;

        if(SLLNode != nullptr)
        {
            left = new BinaryTreeNode(SLLNode->data);
            nodeQueue.push(left);
            SLLNode = SLLNode->next;
        }
        if(SLLNode != nullptr)
        {
            right = new BinaryTreeNode(SLLNode->data);
            nodeQueue.push(right);
            SLLNode = SLLNode->next;
        } 
        curr->left = left;
        curr->right = right;
    }
}