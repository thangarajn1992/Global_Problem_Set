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

/*  Creating Binary Tree from given Inorder and Preorder
    Similar Logic can be used to get Postorder from In and Preorder */
void 
BinaryTree::createBTFromInandPreorder()
{
    int preIndex = 0;
    unordered_map<int,int> inorderIndexMap;
    for(int i = 0; i < inorder.size(); i++)
        inorderIndexMap[inorder[i]] = i;

    root = createBTFromInandPreorderUtil(inorderIndexMap, 0, preorder.size() - 1, preIndex);
}

BinaryTreeNode* 
BinaryTree::createBTFromInandPreorderUtil(unordered_map<int,int> &inorderIndexMap,
                                          int inStart,
                                          int inEnd,
                                          int &preIndex)
{
    if(inStart > inEnd)
        return nullptr;

    int rootIndex = inorderIndexMap[preorder[preIndex++]];

    BinaryTreeNode *node = new BinaryTreeNode(inorder[rootIndex]);

    node->left = createBTFromInandPreorderUtil(inorderIndexMap, inStart, rootIndex-1, preIndex);
    node->right = createBTFromInandPreorderUtil(inorderIndexMap, rootIndex+1, inEnd, preIndex);

    return node;
}

void 
BinaryTree::createBTFromInandPostorderRecursive()
{
    int totalNodes = postorder.size();
    if(totalNodes == 0)
        return;

    unordered_map<int,int> inorderIndexMap;
    int postIndex = totalNodes - 1;
    for(int inIndex = 0; inIndex < totalNodes; inIndex++)
    {
        inorderIndexMap[inorder[inIndex]] = inIndex;
    }

    root = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, 0, totalNodes-1, postIndex);
}

BinaryTreeNode* 
BinaryTree::createBTFromInandPostorderRecursiveUtil(unordered_map<int,int> &inorderIndexMap,
                                                    int inStart,
                                                    int inEnd,
                                                    int &postIndex)
{
    if(inStart > inEnd)
        return nullptr;
    
    int inIndex = inorderIndexMap[postorder[postIndex]];
    postIndex--;

    BinaryTreeNode* node = new BinaryTreeNode(inorder[inIndex]);

    node->right = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, inIndex+1, inEnd, postIndex);
    node->left = createBTFromInandPostorderRecursiveUtil(inorderIndexMap, inStart, inIndex-1, postIndex);

    return node;
}

void 
BinaryTree::createBTFromInandPostorderIterative()
{
    int inIndex = inorder.size()-1, postIndex = postorder.size()-1;
    BinaryTreeNode *prev = nullptr;
    stack<BinaryTreeNode*> nodeStack;
    bool left = false;

    if(postorder.size() == 0)
        return;
    
    prev = root = new BinaryTreeNode(postorder[postIndex]);
    postIndex--;
    nodeStack.push(root);

    while(postIndex >= 0)
    {
        if(nodeStack.empty() == false && inorder[inIndex] == nodeStack.top()->data)
        {
            prev = nodeStack.top();
            nodeStack.pop();
            inIndex--;
            left = true;
        }
        else
        {
            BinaryTreeNode* node = new BinaryTreeNode(postorder[postIndex]);
            postIndex--;
            nodeStack.push(node);
            if(left == true)
            {
                prev->left = node;
                prev = prev->left;
                left = false;
            }
            else
            {
                prev->right = node;
                prev = prev->right;
            }
        }
    }
}



void
BinaryTree::createBTFromInandLevelorder()
{
    unordered_map<int,int> levelIndexMap;
    for(int i = 0; i < levelorder.size(); i++)
        levelIndexMap[levelorder[i]] = i;
    
    root = createBTFromInandLevelorderUtil(levelIndexMap, 0, levelorder.size()-1);
}

BinaryTreeNode*
BinaryTree::createBTFromInandLevelorderUtil(unordered_map<int,int> &levelIndexMap, 
                                            int inStart,
                                            int inEnd)
{
    if(inStart > inEnd)
        return nullptr;
    
    /*  Find the element in the given inorder range, which has
        least index in levelorder */
    int leastLevelIndex = INT_MAX;
    int inIndexWithLeastLevelIndex = inStart;
    for(int i = inStart; i <= inEnd; i++)
    {
        int currLevelIndex = levelIndexMap[inorder[i]];
        if(currLevelIndex < leastLevelIndex)
        {
            leastLevelIndex = currLevelIndex;
            inIndexWithLeastLevelIndex = i;
        }
    }
    
    BinaryTreeNode *node = new BinaryTreeNode(inorder[inIndexWithLeastLevelIndex]);

    node->left = createBTFromInandLevelorderUtil(levelIndexMap, inStart, inIndexWithLeastLevelIndex-1);
    node->right = createBTFromInandLevelorderUtil(levelIndexMap, inIndexWithLeastLevelIndex+1, inEnd);
    
    return node;
}

void 
BinaryTree::createCompleteBTFromLevelOrderArray(vector<int> &levelorderArray)
{
    root = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 0);
}

BinaryTreeNode*
BinaryTree::createCompleteBTFromLevelOrderArrayUtil(vector<int> &levelorderArray, int index)
{
    if(index >= levelorderArray.size())
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(levelorderArray[index]);
    node->left = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 2*index + 1);
    node->right = createCompleteBTFromLevelOrderArrayUtil(levelorderArray, 2*index + 2);

    return node;
}

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

void 
BinaryTree::createFullBTfromPreAndPostorder(vector<int> &pre, 
                                            vector<int> &post)
{
    int preIndex = 0;
    unordered_map<int,int> postIndexMap;
    for(int postIndex = 0; postIndex < post.size(); postIndex++)
    {
        postIndexMap[post[postIndex]] = postIndex;
    }
    root = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, 0, post.size()-1);
}

BinaryTreeNode* 
BinaryTree::createFullBTfromPreAndPostorderUtil(vector<int> &pre,
                                                unordered_map<int,int> &postIndexMap,
                                                int &preIndex,
                                                int postStartIndex,
                                                int postEndIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    if(postStartIndex > postEndIndex)
        return nullptr;
    
    BinaryTreeNode* node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(postStartIndex == postEndIndex) // Only one node in sub-tree, return this node
        return node;
    
    int postIndex = postIndexMap[pre[preIndex]];

    if(postIndex >= postStartIndex && postIndex <= postEndIndex)
    {
        node->left = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, postStartIndex, postIndex);
        /* postEndIndex - 1 is used, because postEndIndex will be the root at this iteration */
        node->right = createFullBTfromPreAndPostorderUtil(pre, postIndexMap, preIndex, postIndex+1, postEndIndex-1);
    }
    return node;
}


void 
BinaryTree::createFullBTFromPreandMirrorPreorder(vector<int> &pre, vector<int> &preMirror)
{
    int preIndex = 0;
    unordered_map<int,int> preMirrorIndexMap;

    for(int preMirrorIndex = 0; preMirrorIndex < preMirror.size(); preMirrorIndex++)
    {
        preMirrorIndexMap[preMirror[preMirrorIndex]] = preMirrorIndex;
    }

    root = createFullBTFromPreandMirrorPreorderUtil(pre, 
                                                    preMirrorIndexMap,
                                                    preIndex,
                                                    0,
                                                    preMirror.size()-1);
}

BinaryTreeNode* 
BinaryTree::createFullBTFromPreandMirrorPreorderUtil(vector<int> &pre,
                                                             unordered_map<int,int> &preMirrorIndexMap,
                                                             int &preIndex,
                                                             int preMirrorStartIndex,
                                                             int preMirrorEndIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    if(preMirrorStartIndex > preMirrorEndIndex)
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(preMirrorStartIndex == preMirrorEndIndex)
        return node;
    
    int preMirrorIndex = preMirrorIndexMap[pre[preIndex]];

    if(preMirrorIndex >= preMirrorStartIndex && preMirrorIndex <= preMirrorEndIndex)
    {
        node->left = createFullBTFromPreandMirrorPreorderUtil(pre, preMirrorIndexMap, preIndex,
                                                              preMirrorIndex, preMirrorEndIndex);

        node->right = createFullBTFromPreandMirrorPreorderUtil(pre, preMirrorIndexMap, preIndex,
                                                               preMirrorStartIndex+1, preMirrorIndex - 1);
    }
    return node;
}

void 
BinaryTree::createFullBTFromPreandPreLNArrayRecursive(vector<int> &pre, vector<char> &preLN)
{
    int preIndex = 0;
    root = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
}

BinaryTreeNode* 
BinaryTree::createFullBTFromPreandPreLNArrayRecursiveUtil(vector<int> &pre,
                                                          vector<char> &preLN,
                                                          int &preIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(preLN[preIndex-1] == 'N')
    {
        node->left = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
        node->right = createFullBTFromPreandPreLNArrayRecursiveUtil(pre, preLN, preIndex);
    }
    return node;
}
    
void 
BinaryTree::createFullBTFromPreandPreLNArrayIterative(vector<int> &pre, vector<char> &preLN)
{
    if(pre.size() == 0)
        return;
    
    stack<BinaryTreeNode*> nodeStack;

    root = new BinaryTreeNode(pre[0]);
    if(preLN[0] == 'N')
        nodeStack.push(root);
    
    for(int preIndex = 1; preIndex < pre.size(); preIndex++)
    {
        BinaryTreeNode* curr = new BinaryTreeNode(pre[preIndex]);
        // If top->left is free, insert there
        if(nodeStack.top()->left == nullptr)
        {
            nodeStack.top()->left = curr;
        }
        else if(nodeStack.top()->right == nullptr) // if top->right is free, insert there
        {
            nodeStack.top()->right = curr;
        }
        else // if both are filled, then keep poping until we find free place
        {
            while(nodeStack.top()->left != nullptr && nodeStack.top()->right != nullptr)
                nodeStack.pop();
            
            nodeStack.top()->right = curr;
        }
        if(preLN[preIndex] == 'N')
            nodeStack.push(curr);
    }
}

void 
BinaryTree::createBTFromAncestorMatrix(vector<vector<int>> &ancestor)
{
    vector<vector<int>> totalDescendents(ancestor.size());
    vector<bool> parentSet(ancestor.size(), false);
    vector<BinaryTreeNode*> nodes(ancestor.size(), nullptr);

    for(int row = 0; row < ancestor.size(); row++)
    {
        int sum = 0;
        for(int col = 0; col < ancestor[row].size(); col++)
        {
            sum += ancestor[row][col];
        }
        totalDescendents[sum].push_back(row);
    }

    for(int i = 0; i < totalDescendents.size(); i++)
    {
        for(int nodeNum = 0; nodeNum < totalDescendents[i].size(); nodeNum++)
        {
            int nodeVal = totalDescendents[i][nodeNum];
            nodes[nodeVal] = new BinaryTreeNode(nodeVal);
            root = nodes[nodeVal];
            if(i != 0) // non-leaf Nodes
            {
                for(int col = 0; col < ancestor[nodeVal].size(); col++)
                {
                    if(ancestor[nodeVal][col] == 1 && parentSet[col] == false)
                    {
                        if(nodes[nodeVal]->left == nullptr)
                            nodes[nodeVal]->left = nodes[col];
                        else if(nodes[nodeVal]->right == nullptr)
                            nodes[nodeVal]->right = nodes[col];
                        parentSet[col] = true;
                    }
                }
            }
        }   
    }
}

void
BinaryTree::createSplBTGreaterParent(vector<int> &in)
{
    root = createSplBTGreaterParentUtil(in, 0, in.size() - 1);
}

BinaryTreeNode*
BinaryTree::createSplBTGreaterParentUtil(vector<int>&in,
                                         int inStartIndex,
                                         int inEndIndex)
{   
    if(inStartIndex > inEndIndex)
        return nullptr;
    
    int maxIndex = max_element(in.begin() + inStartIndex, in.begin() + inEndIndex + 1) -
                    in.begin();
    
    BinaryTreeNode *node = new BinaryTreeNode(in[maxIndex]);

    if(inStartIndex == inEndIndex)
        return node;
    
    node->left = createSplBTGreaterParentUtil(in, inStartIndex, maxIndex-1);
    node->right = createSplBTGreaterParentUtil(in, maxIndex+1, inEndIndex);
    
    return node;
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

/* Reverse LevelOrder Traversal using Queue */
void
BinaryTree::levelorderReverseQueue(BinaryTreeNode *root)
{
    clearLevelorderReverse();
    queue<BinaryTreeNode*> nodeQueue;
    stack<BinaryTreeNode*> nodeStack;

    if(root == nullptr)
        return;
    
    nodeQueue.push(root);
    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *curr = nodeQueue.front();
        nodeQueue.pop();

        nodeStack.push(curr);

        /* Push right child first */
        if(curr->right != nullptr)
            nodeQueue.push(curr->right);
        
        if(curr->left != nullptr)
            nodeQueue.push(curr->left);
    }

    while(nodeStack.empty() == false)
    {
        levelorderReverse.push_back(nodeStack.top()->data);
        nodeStack.pop();
    }
}

/*  Levelorder Left/Right alternate in same Level for Perfect Binary Tree (top to Bottom level) */
/*  Algorithm:
    Instead of processing ONE node at a time, we will process TWO nodes at a time.
    And while pushing children into queue, the enqueue order will be: 
        1st node’s left child, 
        2nd node’s right child, 
        1st node’s right child and 
        2nd node’s left child.
*/
void 
BinaryTree::levelorderSameLevelAlternateToptoBottomLevelQueue(BinaryTreeNode *root)
{   
    clearLevelorderSameLevelAlternateToptoBottom();
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> nodeQueue;

    levelorderSameLevelAlternateToptoBottom.push_back(root->data);
    
    if(root->left != nullptr) /* Dont need to check for right, since it is perfect binary tree */
    {
        levelorderSameLevelAlternateToptoBottom.push_back(root->left->data);
        levelorderSameLevelAlternateToptoBottom.push_back(root->right->data);
        nodeQueue.push(root->left);
        nodeQueue.push(root->right);
    }

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode* first = nodeQueue.front(); nodeQueue.pop();
        BinaryTreeNode* second = nodeQueue.front(); nodeQueue.pop();

        levelorderSameLevelAlternateToptoBottom.push_back(first->left->data);
        levelorderSameLevelAlternateToptoBottom.push_back(second->right->data);
        levelorderSameLevelAlternateToptoBottom.push_back(first->right->data);
        levelorderSameLevelAlternateToptoBottom.push_back(second->left->data);

        if(first->left->left != nullptr)
        {
            nodeQueue.push(first->left);
            nodeQueue.push(second->right);
            nodeQueue.push(first->right);
            nodeQueue.push(second->left);
        }
    }  
}

/* Levelorder Left/Right alternate in same level for Perfect Binary Tree (Bottom to Top level) */
void 
BinaryTree::levelorderSameLevelAlternateBottomtoTopLevelQueue(BinaryTreeNode *root)
{
    clearLevelorderSameLevelAlternateBottomtoTop();
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> nodeQueue;
    stack<BinaryTreeNode*> nodeStack;

    nodeStack.push(root);

    if(root->left != nullptr) /* No need to check for right since it is perfect BinaryTree */
    {
        nodeQueue.push(root->left);
        nodeQueue.push(root->right);

        /* Push right first in the stack */
        nodeStack.push(root->right);
        nodeStack.push(root->left);
    }

    while(nodeQueue.empty() == false)
    {
        BinaryTreeNode *first = nodeQueue.front(); nodeQueue.pop();
        BinaryTreeNode *second = nodeQueue.front(); nodeQueue.pop();

        nodeStack.push(second->left);
        nodeStack.push(first->right);
        nodeStack.push(second->right);
        nodeStack.push(first->left);

        if(first->left->left != nullptr)
        {
            nodeQueue.push(first->right);
            nodeQueue.push(second->left);
            nodeQueue.push(first->left);
            nodeQueue.push(second->right);
        }
    }

    while(nodeStack.empty() == false)
    {
        levelorderSameLevelAlternateBottomtoTop.push_back(nodeStack.top()->data);
        nodeStack.pop();
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
int 
BinaryTree::getTotalNodes(BinaryTreeNode *node)
{
    if(node == nullptr)
        return 0;
    
    return 1 + getTotalNodes(node->left) + getTotalNodes(node->right);
}

bool 
BinaryTree::isSymmetric()
{
    return isSymmetricUtil(root, root);   
}    

bool 
BinaryTree::isSymmetricUtil(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if(node1 == nullptr && node2 == nullptr)                
        return true;
    
    if(node1 != nullptr && node2 != nullptr && 
       node1->data == node2->data &&
       isSymmetricUtil(node1->left, node2->right) &&
       isSymmetricUtil(node1->right, node2->left))
    {
        return true;
    }

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

/* Check whether any path has sum of all nodes in that path equal to given target */
bool
BinaryTree::hasPathSum(BinaryTreeNode* node, int target)
{
    if(node == nullptr)
        return false;
    
    if(node->left == nullptr && node->right == nullptr)
    {
       return node->data == target;
    }

    return  hasPathSum(node->left, target - node->data) ||
            hasPathSum(node->right, target - node->data);
}

/* 
    Check whether Tree has Children Sum Property:
    For every node, data value must be equal to sum of data values in left and right children. 
    Consider data value as 0 for NULL children.
*/
bool
BinaryTree::hasChildrenSumProperty(BinaryTreeNode *node)
{
    /* To take care of root itself is nullptr */
    if(node == nullptr) 
        return true;
    
    /* Leaf Node is always has this property */
    if(node->left == nullptr && node->right == nullptr)
        return true;

    int sum = 0;
    if(node->left != nullptr)
        sum += node->left->data;
    if(node->right != nullptr)
        sum += node->right->data;
    
    return (sum == node->data &&
            hasChildrenSumProperty(node->left) &&
            hasChildrenSumProperty(node->right));
}


vector<vector<int>>
BinaryTree::getAncestorMatrixBacktracking()
{
    ancestorMatrix.clear();
    totalNodes = getTotalNodes(root);
    ancestorMatrix.resize(totalNodes, vector<int>(totalNodes, 0));
    vector<int> ancestors;
    
    getAncestorMatrixBacktrackingUtil(root, ancestors);

    return ancestorMatrix;
}

void
BinaryTree::getAncestorMatrixBacktrackingUtil(BinaryTreeNode* node,
                                              vector<int> &ancestors)
{
    if(node == nullptr)
        return;

    for(int ancestor : ancestors)
    {   
        ancestorMatrix[ancestor][node->data] = 1;
    }
    ancestors.push_back(node->data);
    getAncestorMatrixBacktrackingUtil(node->left, ancestors);
    getAncestorMatrixBacktrackingUtil(node->right, ancestors);
    ancestors.pop_back();
}

vector<vector<int>>
BinaryTree::getAncestorMatrixTransitiveClosure()
{
    ancestorMatrix.clear();
    totalNodes = getTotalNodes(root);
    ancestorMatrix.resize(totalNodes, vector<int>(totalNodes, 0));

    /*  Find adjacency Matrix for tree similar to graph 
        Where parent->child is considered as path */
    getAncestorMatrixTransitiveClosureAdjFill(root, -1);

    /* From adjacency matrix, convert it into reachability matrix
       by finding the transitive closure of this matrix */
    for(int i = 0; i < totalNodes; i++)
    {
        for(int j = 0; j < totalNodes; j++)
        {
            for(int k = 0; k < totalNodes; k++)
            {
                ancestorMatrix[j][k] = ancestorMatrix[j][k] ||
                                       (ancestorMatrix[j][i] && ancestorMatrix[i][k]);
            }
        }
    }

    return ancestorMatrix;
}

void 
BinaryTree::getAncestorMatrixTransitiveClosureAdjFill(BinaryTreeNode *node,
                                                      int parentValue)
{
    if(node == nullptr)
        return;
    
    if(parentValue != -1)
        ancestorMatrix[parentValue][node->data] = 1;
    
    getAncestorMatrixTransitiveClosureAdjFill(node->left, node->data);
    getAncestorMatrixTransitiveClosureAdjFill(node->right, node->data);
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

/*  Convert BT to a tree which holds Children Sum Property  */
void
BinaryTree::convertBTToChildSumBT(BinaryTreeNode *node)
{
    if(node == nullptr)
        return;
    
    if(node->left == nullptr && node->right == nullptr)
        return;
    
    convertBTToChildSumBT(node->left);
    convertBTToChildSumBT(node->right);

    int childSum = 0;
    if(node->left != nullptr)
        childSum += node->left->data;
    if(node->right != nullptr)
        childSum += node->right->data;
    
    int diff = childSum - node->data;

    if(diff >= 0)
        node->data += diff;
    else
        convertBTToChildSumBTIncrement(node, -diff);
}

void 
BinaryTree::convertBTToChildSumBTIncrement(BinaryTreeNode *node, int increment_value)
{
    if(node->left != nullptr)
    {
        node->left->data += increment_value;
        convertBTToChildSumBTIncrement(node->left, increment_value);
    }
    else if(node->right != nullptr)
    {
        node->right->data += increment_value;
        convertBTToChildSumBTIncrement(node->right, increment_value);
    }
}



/* Populate inorder successor for each node in Binary Tree */
void 
BinaryTree::populateInorderSuccessor(BinaryTreeNode *node)
{
    static BinaryTreeNode* inorderSucessor = nullptr;

    if(node != nullptr)
    {
        populateInorderSuccessor(node->right);

        node->inorderSucessor = inorderSucessor;

        inorderSucessor = node;

        populateInorderSuccessor(node->left);
    }
}

/* Get Inorder Successor for given node in Binary Tree */
BinaryTreeNode*
BinaryTree::getInorderSuccessor(BinaryTreeNode *node)
{
    BinaryTreeNode *successor = nullptr;
    getInorderSuccessorUtil(root, node, successor);
    return successor;
}

void 
BinaryTree::getInorderSuccessorUtil(BinaryTreeNode *root,
                                   BinaryTreeNode* node,
                                   BinaryTreeNode* &successor)
{
    static BinaryTreeNode *next = nullptr;

    if(root == nullptr)
        return;

    if(successor == nullptr) // If not found
    {
        getInorderSuccessorUtil(root->right, node, successor);

        if(root->data == node->data)
            successor = next;

        next = root;

        getInorderSuccessorUtil(root->left, node, successor);
    }
}

void 
BinaryTree::reversePathToNode(int data)
{
    map<int,int> levelMap;
    int nextpos = 0;
    reversePathToNodeUtil(root, data, levelMap, 0, nextpos);
}

bool 
BinaryTree::reversePathToNodeUtil(BinaryTreeNode* node, int data, map<int,int>& levelMap, int level, int &nextpos)
{
    if(node == nullptr)
        return false;
    
    levelMap[level] = node->data;

    if(node->data == data)
    {
        node->data = levelMap[nextpos++];
        return true;
    }

    bool leftFound = false, rightFound = false;
    leftFound = reversePathToNodeUtil(node->left, data, levelMap, level+1, nextpos);
    if(leftFound == false)
        rightFound = reversePathToNodeUtil(node->right, data, levelMap, level+1, nextpos);
    
    if(leftFound || rightFound) // This node is in the interested path
    {
        node->data = levelMap[nextpos++];
        return true;
    }
    return false;
        
}

/*  
    Reverse nodes in alternate level in a Perfect Binary Tree - Two Inorder Traversal   
        We do inorder traversal and store the values in odd level in the stack
        When we run inorder traversal again, replace the values in odd level by popping from stack
*/
void 
BinaryTree::reverseNodesInAlternateLevelPerfectBinaryTreeTwoTraversal()
{
    if(root == nullptr)
        return;
    
    stack<int> inorder;
    inorderOddLevelFillStack(root, inorder, 0);
    inorderSwapOddLevelFromStack(root, inorder, 0);
}

void 
BinaryTree::inorderOddLevelFillStack(BinaryTreeNode *node, stack<int> &inorder, int level)
{
    if(node == nullptr)
        return;
    
    inorderOddLevelFillStack(node->left, inorder, level+1);

    if(level % 2 == 1) // Only push into stack for odd level
        inorder.push(node->data);
    
    inorderOddLevelFillStack(node->right, inorder, level+1);
}

void 
BinaryTree::inorderSwapOddLevelFromStack(BinaryTreeNode *node, stack<int> &inorder, int level)
{
    if(node == nullptr)
        return;
    
    inorderSwapOddLevelFromStack(node->left, inorder, level+1);

    if(level % 2 == 1) // Only swap for odd Level
    {
        node->data = inorder.top();
        inorder.pop();
    }

    inorderSwapOddLevelFromStack(node->right, inorder, level+1);
}

/*  
    Reverse nodes in alternate level in a Perfect Binary Tree - Single Swap Traversal
        At even level, we swap the right and left node data. i.e indirectly it changes the
        node values in odd level.
*/  
void 
BinaryTree::reverseNodesInAlternateLevelPerfectBinaryTreeSingleSwapTraversal()
{
    if(root == nullptr)
        return;
    
    reverseAlternateLevelSwapperTraversal(root->left, root->right, 0);
}

void 
BinaryTree::reverseAlternateLevelSwapperTraversal(BinaryTreeNode *left, BinaryTreeNode *right, int level)
{
    if(left == nullptr || right == nullptr)
        return;
    
    if(level % 2 == 0)
    {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
    }

    reverseAlternateLevelSwapperTraversal(left->left, right->right, level+1);
    reverseAlternateLevelSwapperTraversal(left->right, right->left, level+1);
}

/*  Modify Binary Tree such that preorder traversal can be formed using right pointers alone:
    Algorithm: 
        Normal iterative preorder traversal, we keep track of predecessor and update 
        predecessor->right to current node.    
*/
void 
BinaryTree::convertTreePreorderThroughRightPointers()
{
    if(root == nullptr)
        return;
    
    BinaryTreeNode* pre = nullptr;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);

    while(nodeStack.empty() == false)
    {
        BinaryTreeNode *curr = nodeStack.top();
        nodeStack.pop();

        if(curr->right != nullptr)
            nodeStack.push(curr->right);
        if(curr->left != nullptr)
            nodeStack.push(curr->left);
        
        if(pre != nullptr)
            pre->right = curr;
        
        pre = curr;
    }
}


/* Number of Full Binary Trees with N+1 leaves */
int 
BinaryTree::NumberOfFullBinaryTreeWithNPlus1Leaves(int n)
{
    return 0;
}


/* Tree Construction or Generation */




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