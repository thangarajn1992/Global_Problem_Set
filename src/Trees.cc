#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<climits>

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
Binary Tree:
============================================================================

Binary Tree Operations:
    Insert New node into Binary Tree
    Delete Node with value in Binary Tree
    Create Binary Tree from Parent Array Representation

Binary Search Tree Operations:
    Insert New node into Binary Search Tree


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
    Diagonal using Queue
    Boundary Traversal

    Postorder from Preorder and Inorder

Tree Properties:
    Is Symmetric Tree (Mirror Image)
    Find Height, Size and Density of Binary Tree

Tree Transformations:
    Convert to its sumTree
    Convert to its Mirror Image - Recursive
    Convert to its Mirror Image - Iterative
    Right Flip 
*/

class BinarySearchTreeNode
{
public:
    int data;
    BinarySearchTreeNode * left;
    BinarySearchTreeNode * right;
    BinarySearchTreeNode * parent;

    BinarySearchTreeNode(int value) : data {value}, left(nullptr), right(nullptr), parent(nullptr) {}
};


class BinarySearchTree{
private:
    BinarySearchTreeNode *root;

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTreeNode* getRoot()
    {
        return root;
    }

    void Insert(int data)
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

    /* Basic Recursive Traversal: To print BSTs */
        /* Preorder Traversal - Recursive */
    void preorderRecurisve(BinarySearchTreeNode *node, vector<int> &preorder)
    {
        if(node == nullptr)
            return;

        preorder.push_back(node->data);
        preorderRecurisve(node->left, preorder);
        preorderRecurisve(node->right, preorder);
    }

    /* Inorder Traversal - Recursive */
    void inorderRecursive(BinarySearchTreeNode *node, vector<int> &inorder)
    {
        if(node == nullptr)
            return;

        inorderRecursive(node->left, inorder);
        inorder.push_back(node->data);
        inorderRecursive(node->right, inorder);
    }

    /* Postorder Traversal - Recursive */
    void postorderRecursive(BinarySearchTreeNode *node, vector<int> &postorder)
    {
        if(node == nullptr)
            return;

        postorderRecursive(node->left, postorder);
        postorderRecursive(node->right, postorder);
        postorder.push_back(node->data);
    }

    /* Binary Search Tree Construction */
    void constructBSTFromPreorderRecursive(vector<int> pre)
    {
        int preIndex = 0;
        root = BSTFromPreUtil(pre, preIndex, INT_MIN, INT_MAX);
    }

    BinarySearchTreeNode *BSTFromPreUtil(vector<int> &pre, int &preIndex,
                                         int start, int end)
    {
        if(preIndex >= pre.size())
            return nullptr;

        int key = pre[preIndex]; 
        if(key > start && key < end)
        {
            BinarySearchTreeNode *node = new BinarySearchTreeNode(key);
            preIndex++;
            
            node->left = BSTFromPreUtil(pre, preIndex, start, key);
            node->right = BSTFromPreUtil(pre, preIndex, key, end);

            return node;
        }
        return nullptr;
    }
    
    void constructBSTFromPreorderIterative(vector<int> pre)
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

    /* Number of Binary Search Trees Possible with N keys */
    int NumberOfBSTsForNkeys(int n)
    {
        return 0;
    }


};


class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int value) : data{value}, left(nullptr), right(nullptr) {}
};

class BinaryTreeArray {
private:
    vector<int> BinaryTree;

public:
    BinaryTreeArray(int size, int rootVal) {
        BinaryTree.resize(size, -1);
        BinaryTree[0] = rootVal;
    }

    vector<int> getArray()
    {
        return BinaryTree;
    }
    void addLeftNode(int parentIndex, int value)
    {
        if(BinaryTree[parentIndex] == -1)
        {
            cout << "Invalid Parent Node.." << endl;
        }
        else
        {
            BinaryTree[(parentIndex*2) + 1] = value;  
        }
    }

    void addRightNode(int parentIndex, int value)
    {
        if(BinaryTree[parentIndex] == -1)
        {
            cout << "Invalid Parent Node.." << endl;
        }
        else
        {
            BinaryTree[(parentIndex*2) + 2] = value;
        }
    }
};

class BinaryTree {
private:
    BinaryTreeNode *root;

public:
    BinaryTree() : root(nullptr) {}

    BinaryTreeNode *getRoot()
    {
        return root;
    }

    void setRoot(BinaryTreeNode* node)
    {
        root = node;
    }

    /* Tree Operations */
    /*  
    Insert in Binary Tree:
        Find the first free space available and insert new node 
    */
    void Insert(int value)
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
    void Delete(int value)
    {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            if(root->data == value)
            {
                delete(root);
                root == nullptr;
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

    /* Create Binary Tree from Parent Array Representation */
    void createBTFromParentArray(vector<int> &parentArray)
    {
        int totalNodes = parentArray.size();
        vector<BinaryTreeNode*> createdNodes(totalNodes, nullptr);

        for(int i = 0; i < totalNodes; i++)
        {
            createNode(i, createdNodes, parentArray);
        }
    }

    void createNode(int nodeNum, vector<BinaryTreeNode*> &createdNodes, vector<int> &parentArray)
    {
        if(createdNodes[nodeNum] != nullptr)
            return;
        
        createdNodes[nodeNum] = new BinaryTreeNode(nodeNum);

        if(parentArray[nodeNum] == -1)
        {
            root = createdNodes[nodeNum];
            return;
        }

        if(createdNodes[parentArray[nodeNum]] == nullptr)
        {
            createNode(parentArray[nodeNum], createdNodes, parentArray);
        }

        if(createdNodes[parentArray[nodeNum]]->left == nullptr)
            createdNodes[parentArray[nodeNum]]->left = createdNodes[nodeNum];
        else
            createdNodes[parentArray[nodeNum]]->right = createdNodes[nodeNum];
    }

    /* Tree Traversals - Recursive */

    /* Preorder Traversal - Recursive */
    void preorderRecurisve(BinaryTreeNode *node, vector<int> &preorder)
    {
        if(node == nullptr)
            return;

        preorder.push_back(node->data);
        preorderRecurisve(node->left, preorder);
        preorderRecurisve(node->right, preorder);
    }

    /* Inorder Traversal - Recursive */
    void inorderRecursive(BinaryTreeNode *node, vector<int> &inorder)
    {
        if(node == nullptr)
            return;

        inorderRecursive(node->left, inorder);
        inorder.push_back(node->data);
        inorderRecursive(node->right, inorder);
    }

    /* Postorder Traversal - Recursive */
    void postorderRecursive(BinaryTreeNode *node, vector<int> &postorder)
    {
        if(node == nullptr)
            return;

        postorderRecursive(node->left, postorder);
        postorderRecursive(node->right, postorder);
        postorder.push_back(node->data);
    }

    void PostPreInOrderInOneFlowRecursive(BinaryTreeNode* node,
                                          vector<int>& preorder,
                                          vector<int>& postorder,
                                          vector<int>& inorder)
    {
        // Return if root is NULL
        if (node == NULL)
            return;
    
        // Pushes the root data into the pre order vector
        preorder.push_back(node->data);
    
        // Recursively calls for the left node
        PostPreInOrderInOneFlowRecursive(
            node->left, preorder, postorder, inorder);
    
        // Pushes node data into the inorder vector
        inorder.push_back(node->data);
    
        // Recursively calls for the right node
        PostPreInOrderInOneFlowRecursive(
            node->right, preorder, postorder, inorder);
    
        // Pushes the node data into the Post Order vector
        postorder.push_back(node->data);
    }

    /* Tree Traversals - Iterative*/

    /* Pre-order Traversal - Iterative Using Stack */
    vector<int> preorderIterative()
    {
        stack<BinaryTreeNode*> nodeStack;
        BinaryTreeNode *curr = root;
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
    vector<int> inorderIterativeStack()
    {
        stack<BinaryTreeNode*> nodeStack;
        BinaryTreeNode *curr = root;
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
    vector<int> inorderIterativeMorris()
    {
        BinaryTreeNode* curr = root;
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
        return inorder;
    }

    /* PostOrder Traversal - Iterative using Two Stacks */
    vector<int> postorderIterativeTwoStacks()
    {
        stack<BinaryTreeNode*> nodeStack1;
        stack<BinaryTreeNode*> nodeStack2;
        vector<int> postorder;

        if(root == nullptr)
            return postorder;

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
        return postorder;
    }

    /* PostOrder Traversal - Iterative using Single Stack */
    vector<int> postorderIterativeStack()
    {
        stack<BinaryTreeNode*> nodeStack;
        BinaryTreeNode *curr = root;
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
    vector<int> levelorderQueue()
    {
        queue<BinaryTreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<int> levelorder;

        if(root == nullptr)
            return levelorder;

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
        return levelorder;
    }

    /* ZigZag Traversal using Queue */
    vector<int> zigzagQueue()
    {
        
        queue<BinaryTreeNode*> nodeQueue;
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
        return zigzag;
    }

    /* ZigZag Traversal using deque (double ended queue)*/
    vector<int> zigzagDeque()
    {
        deque<BinaryTreeNode*> nodeDeque;
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
        return zigzag;
    }

    /* ZigZag Traversal using Two Stacks */
    vector<int> zigzagTwoStacks()
    {
        
        stack<BinaryTreeNode*> oddLevelStack;
        stack<BinaryTreeNode*> evenLevelStack;
        vector<int> zigzag;

        if(root == nullptr)
            return zigzag;

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
        return zigzag;
    }

    /* Spiral Traversal using deque (double ended queue)*/
    vector<int> spiralDeque()
    {
        deque<BinaryTreeNode*> nodeDeque;
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
                BinaryTreeNode *curr = nullptr;
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
    vector<int> spiralTwoStacks()
    {
        stack<BinaryTreeNode*> oddLevelStack;
        stack<BinaryTreeNode*> evenLevelStack;
        vector<int> spiral;

        if(root == nullptr)
            return spiral;

        oddLevelStack.push(root);

        while(oddLevelStack.empty() == false || evenLevelStack.empty() == false)
        {
            while(oddLevelStack.empty() == false)
            {
                BinaryTreeNode *curr = oddLevelStack.top();
                oddLevelStack.pop();
                spiral.push_back(curr->data);

                if(curr->right != nullptr)
                    evenLevelStack.push(curr->right);

                if(curr->left != nullptr)
                    evenLevelStack.push(curr->left);
            }

            while(evenLevelStack.empty() == false)
            {
                BinaryTreeNode *curr = evenLevelStack.top();
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

    /* Diagonal Traversal using Queue 
       Time Complexity: O(N)
       Space Complexity : O(N)
    */
    vector<int> diagonalQueue()
    {
        queue<BinaryTreeNode*> BTNodeQueue;
        vector<int> diagonal;
        
        if(root == nullptr)
        {
            return diagonal;
        }

        BTNodeQueue.push(root);

        while(BTNodeQueue.empty() == false)
        {
            int queueSize = BTNodeQueue.size();

            while(queueSize > 0)
            {
                BinaryTreeNode *curr = BTNodeQueue.front();
                BTNodeQueue.pop();
                queueSize--;

                while(curr)
                {
                    diagonal.push_back(curr->data);
                    if(curr->left != nullptr)
                    {
                        BTNodeQueue.push(curr->left);
                    }
                    curr = curr->right;
                }
            }
        }
        return diagonal;
    }

    /* Boundary Traversal */
    /*  
        1. Print all the left side Boundary in top-down
        2. Print all leaves from left-subtree in left-right
        3. Print all leaves from right-subtree in left-right
        4. Print all the right side boundary in bottom-up
        Time Complexity: O(N)
        Space Complexity: O(N)
    */
    void boundaryTraversal(vector<int> &boundary)
    {
        if(root == nullptr)
            return;

        boundary.push_back(root->data);

        /* Left Boundary without leaves */
        leftBoundary(root->left, boundary);

        /* Leaves of left sub-tree */
        leaves(root->left, boundary);
        /* Leaves of right sub-tree */
        leaves(root->right, boundary);

        /* Right Boundary without leaves */
        rightBoundary(root->right, boundary);
    }

    void leftBoundary(BinaryTreeNode *node, vector<int> &boundary)
    {
        if(node == nullptr)
            return;
        
        if(node->left != nullptr)
        {
            boundary.push_back(node->data);
            leftBoundary(node->left, boundary);
        }
        else if(node->right != nullptr)
        {
            boundary.push_back(node->data);
            leftBoundary(node->right, boundary);
        }
        else{ 
            /* Skip leaf nodes */
        }
    }

    void rightBoundary(BinaryTreeNode *node, vector<int> &boundary)
    {
        if(node == nullptr)
            return;
        
        if(node->right != nullptr)
        {
            rightBoundary(node->right, boundary);
            boundary.push_back(node->data);
        }
        else if(node->left != nullptr)
        {
            rightBoundary(node->left, boundary);
            boundary.push_back(node->data);
        }
        else{
            /* skip the leaf nodes */
        }
    }

    void leaves(BinaryTreeNode *node, vector<int> &boundary)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            boundary.push_back(node->data);
            return;
        }

        if(node->left != nullptr)
        {
            leaves(node->left, boundary);
        }

        if(node->right != nullptr)
        {
            leaves(node->right, boundary);
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
    vector<int> getPostfromPreAndIn(vector<int> &pre, vector<int> &in)
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

    void getPostfromPreAndInUtil(vector<int> &pre, vector<int> &in,
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

    /* Tree Properties or Conditions */

    
    bool isSymmetric()
    {
        return isMirror(root, root);   
    }    
    
    bool isMirror(BinaryTreeNode *node1, BinaryTreeNode *node2)
    {
        if(node1 == nullptr && node2 == nullptr)                
            return true;
        
        if(node1->data == node2->data &&
           isMirror(node1->left, node2->right) &&
           isMirror(node1->right, node2->left))
                return true;
            
        return false;
    }

    /*  
        Find density of Binary Tree
        Density: Size/Height
    */
    float density()
    {
        if(root == nullptr)
            return 0;
        
        int size = 0;
        int height = findHeightAndSize(root, size);

        return (float)size/height;
    }

    int findHeightAndSize(BinaryTreeNode *node, int &size)
    {
        if(node == nullptr)
            return 0;
        
        size++;

        return max(findHeightAndSize(node->left, size), 
                   findHeightAndSize(node->right, size)) + 1;
    }


    /* Tree Transformations */
    
    /*  Convert to its SumTree 
        Each node will contain sum of its left and right sub-tree
    */
    int toSumTree(BinaryTreeNode *node)
    {
        if(node == nullptr)
            return 0;
        
        int old_value = node->data;

        node->data = toSumTree(node->left) + toSumTree(node->right);

        return node->data + old_value;
    }

    /* Convert to its Mirror Image - Recursive */
    void toMirrorRecursive(BinaryTreeNode *node)
    {
        if(node == nullptr)
        {
            return;
        }
        else
        {
            toMirrorRecursive(node->left);
            toMirrorRecursive(node->right);

            BinaryTreeNode *swapper = node->left;
            node->left = node->right;
            node->right = swapper;
        }
    }

    void toMirrorIterative()
    {
        if(root == nullptr)
            return;
        
        queue<BinaryTreeNode*> BTNodeQueue;
        BTNodeQueue.push(root);

        while(BTNodeQueue.empty() == false)
        {
            int queueSize = BTNodeQueue.size();
            while(queueSize > 0)
            {
                BinaryTreeNode *curr = BTNodeQueue.front();
                BTNodeQueue.pop();
                queueSize--;

                if(curr->left != nullptr)
                    BTNodeQueue.push(curr->left);
                if(curr->right != nullptr)
                    BTNodeQueue.push(curr->right);

                BinaryTreeNode *swapper = curr->left;
                curr->left = curr->right;
                curr->right = swapper;
            }
        }
    }

    /* 
        Right Flip Binary Tree
        1. Leftmost node becomes Root
        2. Its parent becomes its right child
        3. Its right sibling becomes its left child
        4. Same should be repeated for all left most nodes recursively
    */
    BinaryTreeNode* toRightFlip(BinaryTreeNode *node)
    {
        if(node == nullptr)
            return node;
        if(node->left == nullptr && node->right == nullptr)
            return node;
        
        BinaryTreeNode* flippedRoot = toRightFlip(node->left);

        node->left->left = node->right;
        node->left->right = node;
        node->left = nullptr;
        node->right = nullptr;
        
        return flippedRoot;
    }

    /* Tree Combinations */
    
    /* Number of Unlabelled Binary Trees with N Nodes */
    int NumberOfUnlabelledBinaryTreesWithNNodes(int n)
    {
        return 0;
    }

    /* Number of Full Binary Trees with N+1 leaves */
    int NumberOfFullBinaryTreeWithNPlus1Leaves(int n)
    {
        return 0;
    }
};

int main()
{
    /* Binary Tree Array Representation */

    cout << "Creating Binary Tree with Array Representation: " << endl;
    BinaryTreeArray BTArray(6,10);

    BTArray.addLeftNode(0, 4);
    BTArray.addLeftNode(1, 2);
    BTArray.addRightNode(0, 12);
    BTArray.addRightNode(1, 6);

    cout << BTArray.getArray() << endl;
    
    cout << "Creating Binary Tree with Linked List Representation: " << endl;
    BinaryTree BT;
    /* BT Operations */
    BT.Insert(100);
    BT.Insert(50);
    BT.Insert(150);
    BT.Insert(25);
    BT.Insert(175);
    BT.Insert(75);
    BT.Insert(125);
    BT.Insert(10);
    BT.Insert(87);

    cout << BT.preorderIterative() << endl;

    cout << "Deleting Node 150.." << endl;
    BT.Delete(150);
    cout << BT.preorderIterative() << endl;

    vector<int> parentArray = {-1, 0, 0, 1, 1, 3, 5};
    cout << "Creating BT from Parent Array: " << parentArray << endl;
    BinaryTree BTParentArray;
    BTParentArray.createBTFromParentArray(parentArray);
    cout << BTParentArray.preorderIterative() << endl;

    BinaryTree BTSymmetric;
    BTSymmetric.Insert(100);
    BTSymmetric.Insert(50);
    BTSymmetric.Insert(50);
    BTSymmetric.Insert(24);
    BTSymmetric.Insert(945);
    BTSymmetric.Insert(945);
    BTSymmetric.Insert(24);

    BinaryTree BTSumTree;
    BTSumTree.Insert(10);
    BTSumTree.Insert(-3);
    BTSumTree.Insert(5);
    BTSumTree.Insert(14);
    BTSumTree.Insert(-4);
    BTSumTree.Insert(8);
    BTSumTree.Insert(-9);  

    BinarySearchTree BST;
    BST.Insert(100);
    BST.Insert(50);
    BST.Insert(150);
    BST.Insert(25);
    BST.Insert(175);
    BST.Insert(75);
    BST.Insert(125);
    BST.Insert(10);
    BST.Insert(87);


    /* Tree Traversals */
    vector<int> pre, post, in;

    BT.preorderRecurisve(BT.getRoot(), pre);
    cout << "Preorder Recursive: " << pre;
    BT.inorderRecursive(BT.getRoot(), in);
    cout << "Inorder Recursive: " << in;
    BT.postorderRecursive(BT.getRoot(), post);
    cout << "Postorder Recursive: " << post;

    pre.clear(); post.clear(); in.clear();
    BT.PostPreInOrderInOneFlowRecursive(BT.getRoot(), pre, post, in);
    cout << "All Three Traversal in Single Recursive Function:" << endl;
    cout << "Preorder: " << pre << "Inorder: " << in << "Postorder: " << post;

    cout << "Preorder Iterative : " << BT.preorderIterative();

    cout << "Inorder Iterative : " << BT.inorderIterativeStack(); 
    cout << "Inorder Iterative Morris: " << BT.inorderIterativeMorris();

    cout << "Postorder Iterative two Stacks: " << BT.postorderIterativeTwoStacks();
    cout << "Postorder Iterative Stack: " << BT.postorderIterativeStack();
    
    cout << "Levelorder Queue: " << BT.levelorderQueue();
    
    cout << "ZigZag Queue: " << BT.zigzagQueue();
    cout << "ZigZag Deque: " << BT.zigzagDeque();
    cout << "ZigZag Two Stacks: " << BT.zigzagTwoStacks();
    
    cout << "Spiral Deque: " << BT.spiralDeque();
    cout << "Spiral Two Stacks: " << BT.spiralTwoStacks();

    cout << "Diagonal Queue: " << BT.diagonalQueue();

    vector<int> boundary;
    BT.boundaryTraversal(boundary);
    cout << "Boundary Traversal : " << boundary;

    cout << "Get Postorder from Pre and In order: " << endl;
    pre = BT.preorderIterative();
    in = BT.inorderIterativeStack();
    cout << "Preorder: " << pre << endl;
    cout << "Inorder: " << in << endl;
    cout << "Postorder: " << BT.getPostfromPreAndIn(pre, in) << endl;

    /* Tree Properties or Conditions */
    cout << " Symmetric Tree: " << BT.isSymmetric() << endl;
    cout << " Symmetric Tree: " << BTSymmetric.isSymmetric() << endl;

    cout << " Density of Binary Tree: " << BT.density() << endl;

    /* Tree Transformations */
    cout << " Original Tree: " << BTSumTree.preorderIterative();
    cout << " Total Sum of BT Nodes: "  << BTSumTree.toSumTree(BTSumTree.getRoot()) << endl;
    cout << " Sum Tree: " << BTSumTree.preorderIterative();

    BTSumTree.toMirrorRecursive(BTSumTree.getRoot());
    cout << " Mirror Tree - Recurisve: " << BTSumTree.preorderIterative();

    BTSumTree.toMirrorIterative();
    cout << " Mirror Tree - Iterative: " << BTSumTree.preorderIterative(); 

    BTSumTree.setRoot(BTSumTree.toRightFlip(BTSumTree.getRoot()));
    cout << " Right Flipped : " << BTSumTree.preorderIterative();



    /* Binary Search Tree Constructions */
    cout << "**********************************" << endl;
    cout << " Binary Search Tree Constructions " << endl;
    cout << "**********************************" << endl;
    cout << endl;
    
    pre.clear(); in.clear();
    BST.preorderRecurisve(BST.getRoot(), pre);
    cout << "Preorder Recursive: " << pre;

    BinarySearchTree BSTGeneratedRecursive;
    cout << "Generating BST from preorder (Recursive): " << endl;
    BSTGeneratedRecursive.constructBSTFromPreorderRecursive(pre);
    BSTGeneratedRecursive.inorderRecursive(BSTGeneratedRecursive.getRoot(), in);
    cout << "Inorder of generated BST: " << in << endl;
    cout << endl;

    BinarySearchTree BSTGeneratedIterative;
    cout << "Generating BST from preorder (Iterative): " << endl;
    BSTGeneratedIterative.constructBSTFromPreorderIterative(pre);
    in.clear();
    BSTGeneratedIterative.inorderRecursive(BSTGeneratedIterative.getRoot(), in);
    cout << "Inorder of generated BST: " << in << endl;
    cout << endl;

    return 0;
}


