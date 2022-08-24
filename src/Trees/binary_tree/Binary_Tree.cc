#include "Binary_Tree.h"

using namespace std;

/* Tree Operations */
/*  
Insert in Binary Tree:
Find the first free space available and insert new node 
*/
void 
BinaryTree::Insert(int value)
{
    BinaryTreeNode *temp = nullptr;
    queue<BinaryTreeNode*> BTNodeQueue;

    BinaryTreeNode *newNode = new BinaryTreeNode(value);

    if(root == nullptr)
    {
        root = newNode;
        return;
    }

    BTNodeQueue.push(root);

    while(BTNodeQueue.empty() == false)
    {
        temp = BTNodeQueue.front();
        BTNodeQueue.pop();

        if(temp->left != nullptr)
            BTNodeQueue.push(temp->left);
        else
        {
            temp->left = newNode;
            return;
        }

        if(temp->right != nullptr)
            BTNodeQueue.push(temp->right);
        else
        {
            temp->right = newNode;
            return;
        }
    }
}

/* 
Delete in Binary Tree:
Replace the deleted node with the last node
So the tree shrinks from the bottom
Run a BFS to find node to be deleted, deepest node
and parent of deepest node.
*/
void 
BinaryTree::Delete(int value)
{
    if(root == nullptr)
        return;

    if(root->left == nullptr && root->right == nullptr)
    {
        if(root->data == value)
        {
            delete(root);
            root = nullptr;
        }
        return;
    }

    BinaryTreeNode *toDelete = nullptr;
    BinaryTreeNode *deepestNode = nullptr;
    BinaryTreeNode *parentOfDeepestNode = nullptr;

    queue<BinaryTreeNode*> BTNodeQueue;
    BTNodeQueue.push(root);

    while(BTNodeQueue.empty() == false)
    {
        deepestNode = BTNodeQueue.front();
        BTNodeQueue.pop();

        if(deepestNode->data == value)
            toDelete = deepestNode;

        if(deepestNode->left != nullptr)
        {
            parentOfDeepestNode = deepestNode;
            BTNodeQueue.push(deepestNode->left);
        }
        if(deepestNode->right != nullptr)
        {
            parentOfDeepestNode = deepestNode;
            BTNodeQueue.push(deepestNode->right);
        }
    }
    if(toDelete != nullptr)
    {
        toDelete->data = deepestNode->data;
        if(parentOfDeepestNode->right == deepestNode)
        {
            parentOfDeepestNode->right = nullptr;
        }
        else
        {
            parentOfDeepestNode->left = nullptr;
        }
        delete(deepestNode);
    }
}

BinaryTreeNode*
BinaryTree::Search(int value)
{
    if(root == nullptr)
        return root;

    queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(root);

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode* curr = nodeQueue.front();
        nodeQueue.pop();

        if(curr->data == value)
            return curr;
        
        if(curr->left != nullptr)
            nodeQueue.push(curr->left);
        
        if(curr->right != nullptr)
            nodeQueue.push(curr->right);
    }
    return nullptr;
}

void 
BinaryTree::printRightPointers()
{
    if(root == nullptr)
        return;
    
    cout << "[ " ;
    BinaryTreeNode* curr = root;
    while(curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << "]" << endl;
}

void
BinaryTree::printInorderUsingInorderSuccessorPtr()
{
    BinaryTreeNode *node = root;
    /* Left most node is the first element in Inorder */
    while(node->left != nullptr)
        node = node->left;

    cout << "[ ";
    while(node != nullptr)
    {
        cout << node->data << " ";
        node = node->inorderSucessor;   
    }
    cout << "]" << endl;
}

/* Tree Transformations */

/* Number of Full Binary Trees with N+1 leaves */
int 
BinaryTree::NumberOfFullBinaryTreeWithNPlus1Leaves(int n)
{
    return 0;
}