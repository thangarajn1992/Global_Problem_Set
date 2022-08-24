#include "Binary_Tree.h"

using namespace std;

/* Preorder Traversal - Recursive */
void 
BinaryTree::preorderRecurisve(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;

    preorder.push_back(node->data);
    preorderRecurisve(node->left);
    preorderRecurisve(node->right);
}

/* Pre-order Traversal - Iterative Using Stack */
void 
BinaryTree::preorderIterative(BinaryTreeNode *root)
{
    clearPreorder();
    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode *curr = root;
    while(curr != nullptr || nodeStack.empty() == false)
    {
        /* Print left while exists, and 
            push right nodes into stack*/
        while(curr != nullptr)
        {
            preorder.push_back(curr->data);
            if(curr->right)
                nodeStack.push(curr->right);
            curr = curr->left;
        }

        /* Take out the right node from the stack */
        if(nodeStack.empty() == false)
        {
            curr = nodeStack.top();
            nodeStack.pop();
        }
    }
}

/* Pre-order Traversal - Iterative Using Morris */
void
BinaryTree::preorderIterativeMorris()
{
    clearPreorder();
    if(root == nullptr)
        return;
    
    BinaryTreeNode *curr = root;

    while(curr != nullptr)
    {
        /*  We find inorder predecessor exactly as we do in Morris inorder 
            Traversal but we update the preorder vector in different manner
        */
        
        if(curr->left == nullptr)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            BinaryTreeNode *pre = curr->left;
            while(pre->right != nullptr && pre->right != curr)
            {
                pre = pre->right;
            }

            if(pre->right == nullptr)
            {
                pre->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else /* We have already visited this node */
            {
                pre->right = nullptr;
                curr = curr->right;
            }
        }
    }
}