#include "Binary_Tree.h"

using namespace std;

void 
BinaryTreeArray::addLeftNode(int parentIndex, int value)
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

void 
BinaryTreeArray::addRightNode(int parentIndex, int value)
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


/* Binary Tree Methods */
void 
BinaryTree::printAllBTsForInorder()
{
    cout << "Preorder for All possible BTs for given Inorder: " << endl;
    for(int i = 0; i < allBTsForInorder.size(); i++)
    {
        preorderIterative(allBTsForInorder[i]);
        cout << "Tree " << i+1 << ": "  << getPreOrder();
    }
}

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
void 
BinaryTree::createBTFromParentArray(vector<int> &parentArray)
{
    int totalNodes = parentArray.size();
    vector<BinaryTreeNode*> createdNodes(totalNodes, nullptr);

    for(int i = 0; i < totalNodes; i++)
    {
        createNode(i, createdNodes, parentArray);
    }
}

void 
BinaryTree::createNode(int nodeNum, vector<BinaryTreeNode*> &createdNodes, vector<int> &parentArray)
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
void 
BinaryTree::preorderRecurisve(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;

    preorder.push_back(node->data);
    preorderRecurisve(node->left);
    preorderRecurisve(node->right);
}

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

void 
BinaryTree::PostPreInOrderInOneFlowRecursive(BinaryTreeNode* node)
{
    // Return if root is NULL
    if (node == nullptr)
        return;

    // Pushes the root data into the pre order vector
    preorder.push_back(node->data);

    // Recursively calls for the left node
    PostPreInOrderInOneFlowRecursive(
        node->left);

    // Pushes node data into the inorder vector
    inorder.push_back(node->data);

    // Recursively calls for the right node
    PostPreInOrderInOneFlowRecursive(
        node->right);

    // Pushes the node data into the Post Order vector
    postorder.push_back(node->data);
}

/* Tree Traversals - Iterative*/

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

/* ZigZag Traversal using Queue */
void 
BinaryTree::zigzagQueue()
{
    clearZigzag();
    queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(root);
    bool oddLevel = true;

    if(root == nullptr)
        return;

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
}

/* ZigZag Traversal using deque (double ended queue)*/
void 
BinaryTree::zigzagDeque(BinaryTreeNode *root)
{
    clearZigzag();
    deque<BinaryTreeNode*> nodeDeque;
    bool oddLevel = true;

    if(root == nullptr)
        return;

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
}

/* ZigZag Traversal using Two Stacks */
void 
BinaryTree::zigzagTwoStacks()
{
    clearZigzag();
    stack<BinaryTreeNode*> oddLevelStack;
    stack<BinaryTreeNode*> evenLevelStack;

    if(root == nullptr)
        return; 

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
}

/* Spiral Traversal using deque (double ended queue)*/
void 
BinaryTree::spiralDeque(BinaryTreeNode *root)
{
    clearSpiral();
    deque<BinaryTreeNode*> nodeDeque;
    bool oddLevel = true;

    if(root == nullptr)
        return;

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
}

/* Sprial Traversal using two stacks */
void 
BinaryTree::spiralTwoStacks()
{
    clearSpiral();
    stack<BinaryTreeNode*> oddLevelStack;
    stack<BinaryTreeNode*> evenLevelStack;

    if(root == nullptr)
        return;

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
    return;
}

/* Diagonal Traversal using Queue 
    Time Complexity: O(N)
    Space Complexity : O(N)
*/
void 
BinaryTree::diagonalQueue(BinaryTreeNode* root)
{
    clearDiagonal();
    queue<BinaryTreeNode*> BTNodeQueue;
    
    if(root == nullptr)
        return;

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
void 
BinaryTree::boundaryTraversal()
{
    clearBoundary();
    if(root == nullptr)
        return;

    boundary.push_back(root->data);

    /* Left Boundary without leaves */
    leftBoundary(root->left);

    /* Leaves of left sub-tree */
    leaves(root->left);
    /* Leaves of right sub-tree */
    leaves(root->right);

    /* Right Boundary without leaves */
    rightBoundary(root->right);
}

void 
BinaryTree::leftBoundary(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->left != nullptr)
    {
        boundary.push_back(node->data);
        leftBoundary(node->left);
    }
    else if(node->right != nullptr)
    {
        boundary.push_back(node->data);
        leftBoundary(node->right);
    }
    else{ 
        /* Skip leaf nodes */
    }
}

void 
BinaryTree::rightBoundary(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->right != nullptr)
    {
        rightBoundary(node->right);
        boundary.push_back(node->data);
    }
    else if(node->left != nullptr)
    {
        rightBoundary(node->left);
        boundary.push_back(node->data);
    }
    else{
        /* skip the leaf nodes */
    }
}

void 
BinaryTree::leaves(BinaryTreeNode *node)
{
    if(node->left == nullptr && node->right == nullptr)
    {
        boundary.push_back(node->data);
        return;
    }

    if(node->left != nullptr)
    {
        leaves(node->left);
    }

    if(node->right != nullptr)
    {
        leaves(node->right);
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

/* Tree Properties or Conditions */

bool 
BinaryTree::isSymmetric()
{
    return isMirror(root, root);   
}    

bool 
BinaryTree::isMirror(BinaryTreeNode *node1, BinaryTreeNode *node2)
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
float 
BinaryTree::density()
{
    if(root == nullptr)
        return 0;
    
    int size = 0;
    int height = findHeightAndSize(root, size);

    return (float)size/height;
}

int 
BinaryTree::findHeightAndSize(BinaryTreeNode *node, int &size)
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
int 
BinaryTree::toSumTree(BinaryTreeNode *node)
{
    if(node == nullptr)
        return 0;
    
    int old_value = node->data;

    node->data = toSumTree(node->left) + toSumTree(node->right);

    return node->data + old_value;
}

/* Convert to its Mirror Image - Recursive */
void 
BinaryTree::toMirrorRecursive(BinaryTreeNode *node)
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

void 
BinaryTree::toMirrorIterative()
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
BinaryTreeNode* 
BinaryTree::toRightFlip(BinaryTreeNode *node)
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

/*  Replace all Node with the sum of its inorder predecessor and
    successor */
void 
BinaryTree::toInorderPredecessorSuccessor(BinaryTreeNode *node)
{
    int previousVal = -1;
    BinaryTreeNode *previous = nullptr;
    toInorderPredecessorSuccessorUtil(node, previous, previousVal);
    previous->data = previousVal;
}

void 
BinaryTree::toInorderPredecessorSuccessorUtil(BinaryTreeNode *node,
                                              BinaryTreeNode* &previous,
                                              int &prevVal)
{
    if(node == nullptr)
        return;

    toInorderPredecessorSuccessorUtil(node->left, previous, prevVal);

    if(previous == nullptr)
    {
        previous = node;
        prevVal = 0;
    }
    else
    {
        int temp = previous->data;
        previous->data = node->data + prevVal;
        previous = node;
        prevVal = temp;
    }

    toInorderPredecessorSuccessorUtil(node->right, previous, prevVal);
}

/* Tree Combinations */

/* Number of Unlabelled Binary Trees with N Nodes */
int 
BinaryTree::NumberOfUnlabelledBinaryTreesWithNNodes(int n)
{
    return 0;
}

/* Number of Full Binary Trees with N+1 leaves */
int 
BinaryTree::NumberOfFullBinaryTreeWithNPlus1Leaves(int n)
{
    return 0;
}

void 
BinaryTree::AllPossibleBinaryTreeForInorder(vector<int> &in)
{
    allBTsForInorder = GenerateBTForInorderUtil(in, 0, in.size()-1);
}

vector<BinaryTreeNode*>
BinaryTree::GenerateBTForInorderUtil(vector<int> &in, int start, int end)
{
    vector<BinaryTreeNode *> btrees;
    if(start > end)
    {
        btrees.push_back(nullptr);
        return btrees;
    }

    for(int i = start; i <= end; i++)
    {
        vector<BinaryTreeNode*> leftSubTrees = GenerateBTForInorderUtil(in, start, i-1);
        vector<BinaryTreeNode*> rightSubTrees = GenerateBTForInorderUtil(in, i+1, end);

        for(BinaryTreeNode* left : leftSubTrees)
        {
            for(BinaryTreeNode *right : rightSubTrees)
            {
                BinaryTreeNode *node = new BinaryTreeNode(in[i]);
                node->left = left;
                node->right = right;
                btrees.push_back(node);
            }
        }
    }
    return btrees;
}