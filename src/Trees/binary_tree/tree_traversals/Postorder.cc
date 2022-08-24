#include "Binary_Tree.h"

using namespace std;

/* Postorder Traversal - Recursive */
void 
BinaryTree::postorderRecursive(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;

    postorderRecursive(node->left);
    postorderRecursive(node->right);
    postorder.push_back(node->data);
}

/* PostOrder Traversal - Iterative using Two Stacks */
void 
BinaryTree::postorderIterativeTwoStacks()
{
    stack<BinaryTreeNode*> nodeStack1;
    stack<BinaryTreeNode*> nodeStack2;
    postorder.clear();

    if(root == nullptr)
        return;

    nodeStack1.push(root);

    while(nodeStack1.empty() == false)
    {
        BinaryTreeNode* node = nodeStack1.top();
        nodeStack1.pop();
        nodeStack2.push(node);

        if(node->left != nullptr)
            nodeStack1.push(node->left);
        if(node->right != nullptr)
            nodeStack1.push(node->right);
    }

    while(nodeStack2.empty() == false)
    {
        BinaryTreeNode* node = nodeStack2.top();
        nodeStack2.pop();
        postorder.push_back(node->data);
    }
}

/* PostOrder Traversal - Iterative using Single Stack */
void 
BinaryTree::postorderIterativeStack(BinaryTreeNode *root)
{
    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode *curr = root;
    postorder.clear();

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
}

/* Postorder Traversal - Iterative using Hash Map */
void
BinaryTree::postorderIterativeHashMap()
{
    clearPostorder();
    
    if(root == nullptr)
        return;
    
    unordered_map<BinaryTreeNode*, BinaryTreeNode*> parentMap;
    parentMap[root] = nullptr;

    BinaryTreeNode *curr = root;

    while(curr != nullptr)
    {
        /* If left is not procesed, process it */
        if(curr->left != nullptr && parentMap.find(curr->left) == parentMap.end())
        {
            parentMap[curr->left] = curr;
            curr = curr->left;
        }
        else if(curr->right != nullptr && parentMap.find(curr->right) == parentMap.end())
        {
            parentMap[curr->right] = curr;
            curr = curr->right;
        }
        else /* Processed left and right, process root */
        {
            postorder.push_back(curr->data);
            curr = parentMap[curr];
        }
    }
}

/*  Postorder Traversal from given Preorder and Inorder Traversal
    Algorithm:
    Root is always first element in preorder
    Search for root in inorder and all indexes before them are left-subtree
    and all indexes after them are right-subtree
    Reduce the inorder index range accordingly and print left and right 
    and then root to get the postorder
*/
vector<int> 
BinaryTree::getPostfromPreAndIn(vector<int> &pre, vector<int> &in)
{
    unordered_map<int,int> nodeIndexInorder;
    vector<int> postorder;
    unsigned int preIndex = 0;

    for(int inNum = 0; inNum < in.size(); inNum++)
        nodeIndexInorder[in[inNum]] = inNum;

    getPostfromPreAndInUtil(pre, in, preIndex, 0, in.size()-1, nodeIndexInorder, 
                            postorder);

    return postorder;
}

void 
BinaryTree::getPostfromPreAndInUtil(vector<int> &pre, vector<int> &in,
                                unsigned int &preIndex,
                                int InStart, int InEnd,
                                unordered_map<int,int> &indexMap,
                                vector<int> &post)
{
    if(InStart > InEnd)
        return;
    
    int rootIndex = indexMap[pre[preIndex++]];

    // Complete the left sub-tree
    getPostfromPreAndInUtil(pre, in, preIndex, InStart, rootIndex-1, indexMap, post);

    // Complete the right sub-tree
    getPostfromPreAndInUtil(pre, in, preIndex, rootIndex+1, InEnd, indexMap, post);
    
    post.push_back(in[rootIndex]);
}

void
BinaryTree::getNthPostorderNode(BinaryTreeNode* node, int N, int &value, int &count)
{
    if(node == nullptr)
        return;

    if(count <= N)
    {
        getNthPostorderNode(node->left, N, value, count);
        getNthPostorderNode(node->right, N, value, count);
        count++;
        if(count == N)
            value = node->data;
    }
}