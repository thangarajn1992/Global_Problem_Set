




#include<iostream>
#include<stack>
#include<queue>
using namespace std;
 
/* Overloading cout to print vector of any type */
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    os << "[ ";
    for(auto elem : vec)
    {
        os << elem << " ";
    }
    os << "]\n";
    return os;
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
    Inorder Iterative using Morris Traversal
    Postorder Iterative Two Stacks
    Postorder Iterative One Stack
    Levelorder Queue/Bread-First Traversal
    ZigZag using Queue
    Zigzag using Deque (double ended Queue)
    ZigZag using Two Stacks
    Spiral using Deque (double ended Queue)
    Spiral using Two Stacks
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
void preorderRecurisve(BSTNode *node, vector<int> &preorder)
{
    if(node == nullptr)
        return;
    
    preorder.push_back(node->data);
    preorderRecurisve(node->left, preorder);
    preorderRecurisve(node->right, preorder);
}

/* Inorder Traversal - Recursive */
void inorderRecursive(BSTNode *node, vector<int> &inorder)
{
    if(node == nullptr)
        return;
    
    inorderRecursive(node->left, inorder);
    inorder.push_back(node->data);
    inorderRecursive(node->right, inorder);
}

/* Postorder Traversal - Recursive */
void postorderRecursive(BSTNode *node, vector<int> &postorder)
{
    if(node == nullptr)
        return;
    
    postorderRecursive(node->left, postorder);
    postorderRecursive(node->right, postorder);
    postorder.push_back(node->data);
}

void PostPreInOrderInOneFlowRecursive(BSTNode* root,
                                      vector<int>& preorder,
                                      vector<int>& postorder,
                                      vector<int>& inorder)
{
    // Return if root is NULL
    if (root == NULL)
        return;
 
    // Pushes the root data into the pre order vector
    preorder.push_back(root->data);
 
    // Recursively calls for the left node
    PostPreInOrderInOneFlowRecursive(
        root->left, preorder, postorder, inorder);
 
    // Pushes node data into the inorder vector
    inorder.push_back(root->data);
 
    // Recursively calls for the right node
    PostPreInOrderInOneFlowRecursive(
        root->right, preorder, postorder, inorder);
 
    // Pushes the node data into the Post Order vector
    postorder.push_back(root->data);
}

/* Tree Traversals - Iterative*/

/* Pre-order Traversal - Iterative Using Stack */
vector<int> preorderIterative(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;
    vector<int> preorder;
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
    return preorder;
}

/* In-order Traversal - Iterative using Stack*/
vector<int> inorderIterativeStack(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;
    vector<int> inorder;
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
    return inorder;
}

/* Inorder Traversal - Iterative using Morris Traversal */
vector<int> inorderIterativeMorris(BSTNode *root)
{
    BSTNode* curr = root;
    vector<int> inorder;
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
            BSTNode *pre = curr->left;
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
    return inorder;
}

/* PostOrder Traversal - Iterative using Two Stacks */
vector<int> postorderIterativeTwoStacks(BSTNode *root)
{
    stack<BSTNode*> nodeStack1;
    stack<BSTNode*> nodeStack2;
    vector<int> postorder;

    if(root == nullptr)
        return postorder;

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
        postorder.push_back(node->data);
    }
    return postorder;
}

/* PostOrder Traversal - Iterative using Single Stack */
vector<int> postorderIterativeStack(BSTNode *root)
{
    stack<BSTNode*> nodeStack;
    BSTNode *curr = root;
    vector<int> postorder;

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
            postorder.push_back(curr->data);
            curr = nullptr;
        } 
    }
    return postorder;
}

/* LevelOrder Traversal or Breadth First Traversal using Queue */
vector<int> levelorderQueue(BSTNode *root)
{
    queue<BSTNode*> nodeQueue;
    nodeQueue.push(root);
    vector<int> levelorder;

    if(root == nullptr)
        return levelorder;
    
    while(nodeQueue.empty() == false)
    {
        BSTNode *curr = nodeQueue.front();
        nodeQueue.pop();
        levelorder.push_back(curr->data);
        
        if(curr->left != nullptr)
            nodeQueue.push(curr->left);
        
        if(curr->right != nullptr)
            nodeQueue.push(curr->right);
    }
    return levelorder;
}

/* ZigZag Traversal using Queue */
vector<int> zigzagQueue(BSTNode *root)
{
    
    queue<BSTNode*> nodeQueue;
    nodeQueue.push(root);
    bool oddLevel = true;
    vector<int> zigzag;

    if(root == nullptr)
        return zigzag;
    
    while(nodeQueue.empty() == false)
    {
        vector<int> level;
        int queueSize = nodeQueue.size();
        while(queueSize > 0)
        {
            BSTNode* curr = nodeQueue.front();
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
    return zigzag;
}

/* ZigZag Traversal using deque (double ended queue)*/
vector<int> zigzagDeque(BSTNode *root)
{
    deque<BSTNode*> nodeDeque;
    vector<int> zigzag;
    bool oddLevel = true;

    if(root == nullptr)
        return zigzag;
    
    nodeDeque.push_front(root);
    zigzag.push_back(root->data);
    
    while(nodeDeque.empty() == false)
    {
        int dequeSize = nodeDeque.size();
        while(dequeSize > 0)
        {
            BSTNode *curr = nullptr;
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
    return zigzag;
}

/* ZigZag Traversal using Two Stacks */
vector<int> zigzagTwoStacks(BSTNode *root)
{
    
    stack<BSTNode*> oddLevelStack;
    stack<BSTNode*> evenLevelStack;
    vector<int> zigzag;
    
    if(root == nullptr)
        return zigzag;

    oddLevelStack.push(root);

    while(oddLevelStack.empty() == false || evenLevelStack.empty() == false)
    {
        while(oddLevelStack.empty() == false)
        {
            BSTNode *curr = oddLevelStack.top();
            oddLevelStack.pop();
            zigzag.push_back(curr->data);

            if(curr->left != nullptr)
                evenLevelStack.push(curr->left);
            
            if(curr->right != nullptr)
                evenLevelStack.push(curr->right);
        }

        while(evenLevelStack.empty() == false)
        {
            BSTNode *curr = evenLevelStack.top();
            evenLevelStack.pop();
            zigzag.push_back(curr->data);

            if(curr->right != nullptr)
                oddLevelStack.push(curr->right);
            
            if(curr->left != nullptr)
                oddLevelStack.push(curr->left);
        }
    }
    return zigzag;
}

/* Spiral Traversal using deque (double ended queue)*/
vector<int> spiralDeque(BSTNode *root)
{
    deque<BSTNode*> nodeDeque;
    vector<int> spiral;
    bool oddLevel = true;

    if(root == nullptr)
        return spiral;
        
    nodeDeque.push_front(root);
    spiral.push_back(root->data);
    
    while(nodeDeque.empty() == false)
    {
        int dequeSize = nodeDeque.size();
        while(dequeSize > 0)
        {
            BSTNode *curr = nullptr;
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
    return spiral;
}

/* Sprial Traversal using two stacks */
vector<int> spiralTwoStacks(BSTNode *root)
{
    stack<BSTNode*> oddLevelStack;
    stack<BSTNode*> evenLevelStack;
    vector<int> spiral;

    if(root == nullptr)
        return spiral;
    
    oddLevelStack.push(root);

    while(oddLevelStack.empty() == false || evenLevelStack.empty() == false)
    {
        while(oddLevelStack.empty() == false)
        {
            BSTNode *curr = oddLevelStack.top();
            oddLevelStack.pop();
            spiral.push_back(curr->data);

            if(curr->right != nullptr)
                evenLevelStack.push(curr->right);
            
            if(curr->left != nullptr)
                evenLevelStack.push(curr->left);
        }

        while(evenLevelStack.empty() == false)
        {
            BSTNode *curr = evenLevelStack.top();
            evenLevelStack.pop();
            spiral.push_back(curr->data);

            if(curr->left != nullptr)
                oddLevelStack.push(curr->left);
            
            if(curr->right != nullptr)
                oddLevelStack.push(curr->right);
        }
    }
    return spiral;
}

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

    vector<int> pre, post, in;

    preorderRecurisve(root, pre);
    cout << "Preorder Recursive: " << pre;
    inorderRecursive(root, in);
    cout << "Inorder Recursive: " << in;
    postorderRecursive(root, post);
    cout << "Postorder Recursive: " << post;

    pre.clear(); post.clear(); in.clear();
    PostPreInOrderInOneFlowRecursive(root, pre, post, in);
    cout << "Preorder: " << pre << "Inorder: " << in << "Postorder: " << post;

    cout << "Preorder Iterative : " << preorderIterative(root);

    cout << "Inorder Iterative : " << inorderIterativeStack(root); 
    cout << "Inorder Iterative Morris: " << inorderIterativeMorris(root);

    cout << "Postorder Iterative two Stacks: " << postorderIterativeTwoStacks(root);
    cout << "Postorder Iterative Stack: " << postorderIterativeStack(root);
    
    cout << "Levelorder Queue: " << levelorderQueue(root);
    
    cout << "ZigZag Queue: " << zigzagQueue(root);
    cout << "ZigZag Deque: " << zigzagDeque(root);
    cout << "ZigZag Two Stacks: " << zigzagTwoStacks(root);
    
    cout << "Spiral Deque: " << spiralDeque(root);
    cout << "Spiral Two Stacks: " << spiralTwoStacks(root);
}


