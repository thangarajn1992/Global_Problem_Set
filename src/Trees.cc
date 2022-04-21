




#include<iostream>
#include<stack>
using namespace std;
 
int main()
{
    BSTNode *root = Insert(NULL, 100);
    Insert(root, 50);
    Insert(root, 150);
    Insert(root, 25);
    Insert(root, 175);
    Insert(root, 75);
    Insert(root, 125);
    Insert(root, 10);
    Insert(root, 87);

    cout << "Preorder Recursive : " ;
    preorderRecurisve(root);
    cout << endl;
    cout << "Preorder Iterative : ";
    preorderIterative(root);
    cout << endl;
    cout << "Inorder Recursive : " ;
    inorderRecursive(root);
    cout << endl;
    cout << "Inorder Iterative : ";
    inorderIterativeStack(root);
    cout << endl;
    cout << "Postorder Recursive : " ;
    postorderRecursive(root);
    cout << endl;
    cout << "Postorder Iterative two Stacks : ";
    postorderIterativeTwoStacks(root);
    cout << endl;
    cout << "Postorder Iterative Stack : ";
    postorderIterativeStack(root);
    cout << endl;
}

/*
============================================================================
Binary Search Tree:
============================================================================
BSTNode class declaration
Methods to manipulate BST:
    Insert method to insert node into BST
Tree Traversals:
    Preorder Recursive
    Inorder Recursive
    Postorder Recursive
    Preorder Iterative
    Inorder Iterative Stack
    Postorder Iterative Two Stacks
    Postorder Iterative One Stack
*/

class BSTNode
{
public:
    int data;
    BSTNode * left;
    BSTNode * right;
    BSTNode * parent;
};

BSTNode *
Insert(BSTNode * node, int data)
{
    // If BST doesn't exist create a new node as root
    // or it's reached when there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = new BSTNode;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
    }
    // If the given data is greater than
    // node's data then go to right subtree
    else if(node->data < data){
        node->right = Insert(node->right, data);
        node->right->parent = node;
    }
    // If the given data is smaller than
    // node's data then go to left subtree
    else
    {
        node->left = Insert(node->left, data);
        node->left->parent = node;
    }
    return node;
}


/* Tree Traversals - Recursive */

/* Preorder Traversal - Recursive */
void preorderRecurisve(BSTNode *node)
{
    if(node == nullptr)
        return;
    
    cout << node->data << " ";
    preorderRecurisve(node->left);
    preorderRecurisve(node->right);
}

/* Inorder Traversal - Recursive */
void inorderRecursive(BSTNode *node)
{
    if(node == nullptr)
        return;
    
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

/* Postorder Traversal - Recursive */
void postorderRecursive(BSTNode *node)
{
    if(node == nullptr)
        return;
    
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}

/* Tree Traversals - Iterative*/

/* Pre-order Traversal - Iterative Using Stack */
void preorderIterative(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;

    while(curr != nullptr || nodeStack.empty() == false)
    {
        /* Print left while exists, and 
           push right nodes into stack*/
        while(curr != nullptr)
        {
            cout << curr->data << " ";
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


/* In-order Traversal - Iterative using Stack*/
void inorderIterativeStack(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;
 
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
 
        cout << curr->data << " ";
 
        /* we have visited the node and its left subtree.
           Now, it's right subtree's turn */
        curr = curr->right;
    }
}

/* PostOrder Traversal - Iterative using Two Stacks */
void postorderIterativeTwoStacks(BSTNode *root)
{
    stack<BSTNode*> nodeStack1;
    stack<BSTNode*> nodeStack2;

    if(root == nullptr)
        return;

    nodeStack1.push(root);

    while(nodeStack1.empty() == false)
    {
        BSTNode* node = nodeStack1.top();
        nodeStack1.pop();
        nodeStack2.push(node);

        if(node->left != nullptr)
            nodeStack1.push(node->left);
        if(node->right != nullptr)
            nodeStack1.push(node->right);
    }

    while(nodeStack2.empty() == false)
    {
        BSTNode* node = nodeStack2.top();
        nodeStack2.pop();
        cout << node->data << " ";
    }
}

/* PostOrder Traversal - Iterative using Single Stack */
void postorderIterativeStack(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;
    
    while(curr != nullptr || nodeStack.empty() == false)
    {
        while(curr)
        {
            if(curr->right)
                nodeStack.push(curr->right);
            nodeStack.push(curr);
            curr = curr->left;
        }

        curr = nodeStack.top();
        nodeStack.pop();

        /* If right node is not processed yet, process it first */
        if(curr->right != nullptr && nodeStack.empty() == false && curr->right == nodeStack.top())   
        {
            nodeStack.pop(); /*Remove right node from stack*/
            nodeStack.push(curr);
            curr = curr->right;
        }
        else
        {
            cout << curr->data << " ";
            curr = nullptr;
        } 
    }
}

/* Morris Traversal */


