#include "Binary_Tree.h"

using namespace std;

/* Inorder Traversal - Recursive */
void 
BinaryTree::inorderRecursive(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;

    inorderRecursive(node->left);
    inorder.push_back(node->data);
    inorderRecursive(node->right);
}

/* In-order Traversal - Iterative using Stack*/
void 
BinaryTree::inorderIterativeStack(BinaryTreeNode *root)
{
    clearInorder();
    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode *curr = root;
    while (curr != nullptr || nodeStack.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr !=  nullptr)
        {
            /* Push curr Node pointer to stack before 
                traversing into its left subtree */
            nodeStack.push(curr);
            curr = curr->left;
        }
        /* Current must be NULL at this point */
        curr = nodeStack.top();
        nodeStack.pop();

        inorder.push_back(curr->data);

        /* we have visited the node and its left subtree.
            Now, it's right subtree's turn */
        curr = curr->right;
    }
}

/* Inorder Traversal - Iterative using Morris Traversal */
void 
BinaryTree::inorderIterativeMorris()
{
    clearInorder();
    BinaryTreeNode* curr = root;
    while(curr != nullptr)
    {
        /* If no left, print curr and move to its right */
        if(curr->left == nullptr)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            BinaryTreeNode *pre = curr->left;
            /* Move the rightmost node which will be predecessor
                of current in inorder traversal */
            while(pre->right != nullptr && pre->right != curr)
            {
                pre = pre->right;
            }

            /* If we are visiting for first time, make current as prev
                right pointer */
            if(pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else /* We are reaching here for second time, reset the right ptr */ 
            {
                pre->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

void
BinaryTree::getNthInorderNode(BinaryTreeNode* node, int N, int &value, int &count)
{
    if(node == nullptr)
        return;

    if(count <= N)
    {
        getNthInorderNode(node->left, N, value, count);
        count++;
        if(count == N)
            value = node->data;
        getNthInorderNode(node->right, N, value, count);
    }
}