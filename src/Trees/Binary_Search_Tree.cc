#include "Binary_Search_Tree.h"

using namespace std;


BinarySearchTreeNode* 
BinarySearchTree::getRoot()    
{
    return root;
}

void 
BinarySearchTree::Insert(int data)
{
    if(root == nullptr)
    {
        root = new BinarySearchTreeNode(data);
       return;
    }
    BinarySearchTreeNode *node = root;
    while(true)
    {
        if(node->data < data)
        {
            if(node->right == nullptr)
            {
                node->right = new BinarySearchTreeNode(data);
                return;
            }
            else
            {
                node = node->right;
            }
        }
        else if(node->data > data)
        {
            if(node->left == nullptr)
            {
                node->left = new BinarySearchTreeNode(data);
                return;
            }
            else
            {
                node = node->left;
            }
        }
        else /* Node already exists with this value */
        {
            std::cout << "Error: Node Already exists in Binary Search Tree" << std::endl;
            return;
        }
    }
}  

BinarySearchTreeNode*
BinarySearchTree::Search(int key)
{
    BinarySearchTreeNode *curr = root;

    while(curr != nullptr)
    {
        if(curr->data == key)
            return curr;
        if(curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

    /* Basic Recursive Traversal: To print BSTs */
        /* Preorder Traversal - Recursive */
void
BinarySearchTree::preorderRecurisve(BinarySearchTreeNode *node, vector<int> &preorder)
{
    if(node == nullptr)
        return;

    preorder.push_back(node->data);
    preorderRecurisve(node->left, preorder);
    preorderRecurisve(node->right, preorder);
}

/* Inorder Traversal - Recursive */
void 
BinarySearchTree::inorderRecursive(BinarySearchTreeNode *node, vector<int> &inorder)
{
    if(node == nullptr)
        return;

    inorderRecursive(node->left, inorder);
    inorder.push_back(node->data);
    inorderRecursive(node->right, inorder);
}

/* Postorder Traversal - Recursive */
void 
BinarySearchTree::postorderRecursive(BinarySearchTreeNode *node, vector<int> &postorder)
{
    if(node == nullptr)
        return;

    postorderRecursive(node->left, postorder);
    postorderRecursive(node->right, postorder);
    postorder.push_back(node->data);
}

/* Binary Search Tree Construction */
void 
BinarySearchTree::constructBSTFromPreorderRecursive(vector<int> &pre)
{
    int preIndex = 0;
    root = BSTFromPreUtil(pre, preIndex, INT_MIN, INT_MAX);
}

BinarySearchTreeNode*
BinarySearchTree::BSTFromPreUtil(vector<int> &pre, int &preIndex,
                                int start, int end)
{
    /*  If all index in preorder are processed or
        This value doesnt fit in the given range
    */
    if(preIndex == pre.size() ||
       pre[preIndex] <= start || pre[preIndex] >= end)
    {
        return nullptr;
    }

    int key = pre[preIndex]; 
    BinarySearchTreeNode *node = new BinarySearchTreeNode(key);
    preIndex++;
        
    node->left = BSTFromPreUtil(pre, preIndex, start, key);
    node->right = BSTFromPreUtil(pre, preIndex, key, end);

    return node;
}
    
void 
BinarySearchTree::constructBSTFromPreorderIterative(vector<int> &pre)
{
    stack<BinarySearchTreeNode*> BSTNodeStack;

    root = new BinarySearchTreeNode(pre[0]);
    BSTNodeStack.push(root);

    for(int num = 1; num < pre.size(); num++)
    {
        BinarySearchTreeNode *curr = nullptr;
        /* Pop all lesser elements from stack and put this node as right node */
        while(BSTNodeStack.empty() == false &&
              pre[num] > BSTNodeStack.top()->data)
        {
            curr = BSTNodeStack.top();
            BSTNodeStack.pop();
        }
        if(curr != nullptr)
        {
            curr->right = new BinarySearchTreeNode(pre[num]);
            BSTNodeStack.push(curr->right);
        }
        else /* If no element from the stack is lesser, then this is left node */
        {
            BSTNodeStack.top()->left = new BinarySearchTreeNode(pre[num]);
            BSTNodeStack.push(BSTNodeStack.top()->left);
        }
    }
}

vector<int> 
BinarySearchTree::BSTPostorderFromPreorder(vector<int> &pre)
{
    vector<int> postorder;
    int preIndex = 0;

    BSTPostorderFromPreorderUtil(pre, preIndex, INT_MIN, INT_MAX, postorder);
    return postorder;
}
    
void 
BinarySearchTree::BSTPostorderFromPreorderUtil(vector<int> &pre, int &preIndex,
                                               int rangeStart, int rangeEnd, vector<int> &post)
{
    if(preIndex == pre.size())
        return;
        
    if(pre[preIndex] < rangeStart || pre[preIndex] > rangeEnd)
        return;
        
    int key = pre[preIndex];
    preIndex++;

    BSTPostorderFromPreorderUtil(pre, preIndex, rangeStart, key, post);
    BSTPostorderFromPreorderUtil(pre, preIndex, key, rangeEnd, post);
    post.push_back(key);
}

/*  Find Inorder successor for a give Node 
    Algorithm:
    1. If node->right != null, then successor is min value of right sub-tree
    2. else, sucessor is in the ancestor. The nearby ancestor whose left sub-tree contains
        this node
*/
BinarySearchTreeNode*
BinarySearchTree::getInorderSucessor(BinarySearchTreeNode *node)
{
    if(node == nullptr) // invalid input
        return node;
    
    if(node->right != nullptr)
    {
        /* Find minimum value in the right sub-tree (i.e left most node) */
        BinarySearchTreeNode* curr = node->right;
        while(curr->left != nullptr)
            curr = curr->left;
        return curr;
    }
    else
    {
        /* Find the nearby ancestor whose left subtree has this node */
        BinarySearchTreeNode* successor = nullptr; /* To take care of scenario where there is no sucessor */
        BinarySearchTreeNode* curr = root;
        while(curr != nullptr)
        {
            if(curr->data > node->data)
            {
                successor = curr;
                curr = curr->left;
            }
            else if(curr->data < node->data)
            {
                curr = curr->right;
            }
            else
                break;
        }
        return successor;
    }
}

/* Number of Binary Search Trees Possible with N keys */
int 
BinarySearchTree::NumberOfBSTsForNkeys(int n)
{
    return 0;
}