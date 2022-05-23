#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Trees.h"


using namespace std;
 
/*
============================================================================
Binary Tree:
============================================================================

Binary Tree Operations:
    Insert New node into Binary Tree
    Delete Node with value in Binary Tree
    Search a Node with given value in Binary Tree
    Construct Binary Tree from Parent Array Representation
    Construct Binary Tree from Linked List Representation
    Construct Binary Tree from given inorder and preorder
    Construct Binary Tree from given inorder and Levelorder
    Construct Complete Binary Tree from Level order Array
    Construct Full Binary Tree from preorder and postorder
    Construct Full Binary Tree from preorder and preorder of Mirror Tree 
    Construct Full Binary Tree from preorder and preLN array (Recursive)
    Construct Full Binary Tree from preorder and preLN array (Iterative)
    Construct One of Possible Binary Tree from Ancestor Matrix


Tree Traversals:
    Preorder Recursive
    Inorder Recursive
    Postorder Recursive
    All three Traversal in single Recursive
    Nth Inorder Node
    Nth Postorder Node

    Preorder Iterative
    Preorder Iterative using Morris Traversal
    Inorder Iterative Stack
    Inorder Iterative using Morris Traversal
    Postorder Iterative Two Stacks
    Postorder Iterative One Stack
    Postorder Iterative HashMap
    Levelorder Queue/Bread-First Traversal
    Reverse Levelorder Traversal Using Queue
    Levelorder Left/Right alternate in same Level for Perfect Binary Tree (top to Bottom level)
    Levelorder Left/Right alternate in same level for Perfect Binary Tree (Bottom to Top level)

    ZigZag using Queue
    Zigzag using Deque (double ended Queue)
    ZigZag using Two Stacks
    Spiral using Deque (double ended Queue)
    Spiral using Two Stacks
    Diagonal using Queue
    Boundary Traversal

    Postorder from Preorder and Inorder

Tree Properties:
    Get Total Nodes in the Binary Tree
    Is Symmetric Tree (Mirror Image)
    Find Height, Size and Density of Binary Tree
    Has Path with given target Sum
    Get Ancestor Matrix for Binary Tree (BackTracking)
    Get Ancestor Matrix for Binary Tree (Transitive Closure)

Tree Transformations:
    Convert to its sumTree
    Convert to its Mirror Image - Recursive
    Convert to its Mirror Image - Iterative
    Right Flip 
    Convert All nodes with value of sum of its inorder predecessor and successor
    Populate all nodes with their inorder successor
    Get Inorder Successor for a particular node
    Reverse the Path till the node specified in Binary Tree
    Reverse nodes in alternate level in a Perfect Binary Tree - Two Inorder Traversal
    Reverse nodes in alternate level in a Perfect Binary Tree - Single  Swap Traversal
    Modify Binary Tree such that preorder traversal can be formed using right pointers alone

Tree Generation/Combination:
    Generate all possible Binary Trees for given Inorder
*/

class BinaryTreeNode{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *inorderSucessor;

    BinaryTreeNode(int value) : data{value}, left(nullptr), right(nullptr), inorderSucessor(nullptr) {}
};

class BinaryTreeArray {
private:
    vector<int> BinaryTree;

public:
    BinaryTreeArray() {}

    BinaryTreeArray(int size, int rootVal) {
        BinaryTree.resize(size, -1);
        BinaryTree[0] = rootVal;
    }

    vector<int> getArray() { return BinaryTree; }
    void addLeftNode(int parentIndex, int value);
    void addRightNode(int parentIndex, int value);
};

class BinaryTree {
private:
    BinaryTreeNode *root;
    /* Will be used whenever needed */
    int totalNodes;
    vector<int> preorder; 
    vector<int> inorder;
    vector<int> postorder;
    vector<int> levelorder;
    vector<int> levelorderReverse;
    vector<int> levelorderSameLevelAlternateToptoBottom;
    vector<int> levelorderSameLevelAlternateBottomtoTop;
    vector<int> zigzag;
    vector<int> spiral;
    vector<int> diagonal;
    vector<int> boundary;
    vector<vector<int>> ancestorMatrix;

    /* Used for generating all possible BTs from inorder */
    vector<BinaryTreeNode*> allBTsForInorder;

public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(SinglyLinkedList linkedListRep);

    BinaryTreeNode *getRoot() { return root; }
    void setRoot(BinaryTreeNode* node) { root = node; }
    void setPreorder(vector<int> pre) { preorder = pre; }
    void setInorder(vector<int> in) { inorder = in; }
    void setPostorder(vector<int> post) { postorder = post; }
    void setLevelorder(vector<int> level) { levelorder = level; }

    void clearPreorder() { preorder.clear(); }
    void clearInorder() { inorder.clear(); }
    void clearPostorder() { postorder.clear(); }
    void clearLevelorder() { levelorder.clear(); }
    void clearLevelorderReverse() { levelorderReverse.clear(); }
    void clearLevelorderSameLevelAlternateToptoBottom() { levelorderSameLevelAlternateToptoBottom.clear(); }
    void clearLevelorderSameLevelAlternateBottomtoTop() { levelorderSameLevelAlternateBottomtoTop.clear(); }
    void clearZigzag() { zigzag.clear(); }
    void clearSpiral() { spiral.clear(); }
    void clearDiagonal() { diagonal.clear(); }
    void clearBoundary() { boundary.clear(); }

    void clearAllTraversals() {
        clearPreorder();
        clearInorder();
        clearPostorder();
        clearLevelorder();
        clearLevelorderReverse();
        clearLevelorderSameLevelAlternateToptoBottom();
        clearLevelorderSameLevelAlternateBottomtoTop();
        clearZigzag();
        clearSpiral();
        clearDiagonal();
        clearBoundary();
    }
    
    void printRightPointers()
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

    vector<int> getPreOrder(bool generate = false)
    {
        if(generate == true || (root != nullptr && preorder.size() == 0))
        {
            clearPreorder();
            preorderIterative(root);
        }
        return preorder;
    }

    vector<int> getInorder(bool generate = false)
    {
        if(generate == true || (root != nullptr && inorder.size() == 0))
        {
            clearInorder();
            inorderIterativeStack(root);
        }
        return inorder;
    }

    vector<int> getPostOrder(bool generate = false)
    {
        if(generate == true || (root != nullptr && postorder.size() == 0))
        {
            clearPostorder();
            postorderIterativeStack(root);
        }
        return postorder;
    }

    vector<int> getLevelOrder(bool generate = false)
    {
        if(generate == true || (root != nullptr && levelorder.size() == 0))
        {
            clearLevelorder();
            levelorderQueue(root);
        }
        return levelorder;
    }

    vector<int> getLevelOrderReverse(bool generate = false)
    {
        if(generate == true || (root != nullptr && levelorderReverse.size() == 0))
        {
            clearLevelorderReverse();
            levelorderReverseQueue(root);
        }
        return levelorderReverse;
    }

    vector<int> getLevelOrderSameLevelAlternateToptoBottom(bool generate = false)
    {
        if(generate == true || (root != nullptr && levelorderSameLevelAlternateToptoBottom.size() == 0))
        {
            levelorderSameLevelAlternateToptoBottomLevelQueue(root);
        }
        return levelorderSameLevelAlternateToptoBottom;
    }

    vector<int> getLevelOrderSameLevelAlternateBottomtoTop(bool generate = false)
    {
        if(generate == true || (root != nullptr && levelorderSameLevelAlternateBottomtoTop.size() == 0))
        {
            levelorderSameLevelAlternateBottomtoTopLevelQueue(root);
        }
        return levelorderSameLevelAlternateBottomtoTop;
    }

    vector<int> getZigzag(bool generate = false)
    {
        if(generate == true || (root != nullptr && zigzag.size() == 0))
        {
            zigzagDeque(root);
        }
        return zigzag;
    }

    vector<int> getSpiral(bool generate = false)
    {
        if(generate == true || (root != nullptr && spiral.size() == 0))
        {
            spiralDeque(root);
        }
        return spiral;
    }

    vector<int> getDiagonal(bool generate = false)
    {
        if(generate == true || (root != nullptr && diagonal.size() == 0))
        {
            diagonalQueue(root);
        }
        return diagonal;
    }

    vector<int> getBounary(bool generate = false)
    {
        if(generate == true || (root != nullptr && boundary.size() == 0))
        {
            boundaryTraversal();
        }
        return boundary;
    }

    void printAllBTsForInorder();
    void printInorderUsingInorderSuccessorPtr();

    /* Tree Operations */
    void Insert(int value);
    void Delete(int value);
    BinaryTreeNode* Search(int value);
    
    void createBTFromInandPreorder();
    BinaryTreeNode* createBTFromInandPreorderUtil(unordered_map<int,int> &inorderIndexMap,
                                                  int inStart,
                                                  int inEnd,
                                                  int &preIndex);

    void createBTFromInandLevelorder();
    BinaryTreeNode* createBTFromInandLevelorderUtil(unordered_map<int,int> &levelIndex, 
                                                    int inStart,
                                                    int inEnd);

    void createBTFromParentArray(vector<int> &parentArray);
    void createNode(int nodeNum, 
                    vector<BinaryTreeNode*> &createdNodes, 
                    vector<int> &parentArray);

    void createCompleteBTFromLevelOrderArray(vector<int> &levelorderArray);
    BinaryTreeNode* createCompleteBTFromLevelOrderArrayUtil(vector<int> &levelorderArray, 
                                                            int index);


    void createFullBTfromPreAndPostorder(vector<int> &pre, vector<int> &post);
    BinaryTreeNode* createFullBTfromPreAndPostorderUtil(vector<int> &pre,
                                                        unordered_map<int,int> &postIndexMap,
                                                        int &preIndex,
                                                        int postStartIndex,
                                                        int postEndInd);

    
    void createFullBTFromPreandMirrorPreorder(vector<int> &pre, vector<int> &preMirror);
    BinaryTreeNode* createFullBTFromPreandMirrorPreorderUtil(vector<int> &pre,
                                                             unordered_map<int,int> &preMirrorIndexMap,
                                                             int &preIndex,
                                                             int preMirrorStartIndex,
                                                             int preMirrorEndIndex);


    void createFullBTFromPreandPreLNArrayRecursive(vector<int> &pre, vector<char> &preLN);
    BinaryTreeNode* createFullBTFromPreandPreLNArrayRecursiveUtil(vector<int> &pre,
                                                                  vector<char> &preLN,
                                                                  int &preIndex);
    
    void createFullBTFromPreandPreLNArrayIterative(vector<int> &pre, vector<char> &preLN);

    void createBTFromAncestorMatrix(vector<vector<int>> &ancestor);

    /* Tree Traversals - Recursive */
    void preorderRecurisve(BinaryTreeNode *node);
    void inorderRecursive(BinaryTreeNode *node);
    void postorderRecursive(BinaryTreeNode *node);
    void PostPreInOrderInOneFlowRecursive(BinaryTreeNode* node);
    void getNthInorderNode(BinaryTreeNode* node, int N, int &value, int &count);
    void getNthPostorderNode(BinaryTreeNode* node, int N, int &value, int &count);
    
    /* Tree Traversals - Iterative*/
    void preorderIterative(BinaryTreeNode *root);
    void preorderIterativeMorris();
    void inorderIterativeStack(BinaryTreeNode *root);
    void inorderIterativeMorris();
    void postorderIterativeTwoStacks();
    void postorderIterativeStack(BinaryTreeNode *root);
    void postorderIterativeHashMap();

    void levelorderQueue(BinaryTreeNode *root);
    void levelorderReverseQueue(BinaryTreeNode *root);
    void levelorderSameLevelAlternateToptoBottomLevelQueue(BinaryTreeNode *root);
    void levelorderSameLevelAlternateBottomtoTopLevelQueue(BinaryTreeNode *root);

    void zigzagQueue();
    void zigzagDeque(BinaryTreeNode *root);
    void zigzagTwoStacks();
    void spiralDeque(BinaryTreeNode *root);
    void spiralTwoStacks();
    void diagonalQueue(BinaryTreeNode* root);
    void boundaryTraversal();
    void leftBoundary(BinaryTreeNode *node);
    void rightBoundary(BinaryTreeNode *node);
    void leaves(BinaryTreeNode *node);

    vector<int> getPostfromPreAndIn(vector<int> &pre, 
                                    vector<int> &in);
    void getPostfromPreAndInUtil(vector<int> &pre, 
                                 vector<int> &in,
                                 unsigned int &preIndex,
                                 int InStart, int InEnd,
                                 unordered_map<int,int> &indexMap,
                                 vector<int> &post);
    
    /* Tree Properties or Conditions */
    int getTotalNodes(BinaryTreeNode *node);

    bool isSymmetric();
    bool isSymmetricUtil(BinaryTreeNode *node1, 
                         BinaryTreeNode *node2);
    
    float density();
    int findHeightAndSize(BinaryTreeNode *node, int &size);

    bool hasPathSum(BinaryTreeNode* node, int target);

    vector<vector<int>> getAncestorMatrixBacktracking();
    void getAncestorMatrixBacktrackingUtil(BinaryTreeNode* node,
                                           vector<int> &ancestors);

    vector<vector<int>> getAncestorMatrixTransitiveClosure();
    void getAncestorMatrixTransitiveClosureAdjFill(BinaryTreeNode *node,
                                               int parentValue);


    /* Tree Transformations */
    int toSumTree(BinaryTreeNode *node);
    void toMirrorRecursive(BinaryTreeNode *node);
    void toMirrorIterative();
    BinaryTreeNode* toRightFlip(BinaryTreeNode *node);

    void toInorderPredecessorSuccessor(BinaryTreeNode *node);
    void toInorderPredecessorSuccessorUtil(BinaryTreeNode *node,
                                            BinaryTreeNode* &previous,
                                            int &prevVal);
    void populateInorderSuccessor(BinaryTreeNode *node);

    BinaryTreeNode* getInorderSuccessor(BinaryTreeNode *node);
    void getInorderSuccessorUtil(BinaryTreeNode *root,
                                BinaryTreeNode* node,
                                BinaryTreeNode* &successor);

    void reversePathToNode(int data);
    bool reversePathToNodeUtil(BinaryTreeNode* node,
                               int data, 
                               map<int,int>& levelMap, 
                               int level, 
                               int &nextpos);

    void reverseNodesInAlternateLevelPerfectBinaryTreeTwoTraversal();
    void inorderOddLevelFillStack(BinaryTreeNode *node, 
                                  stack<int> &inorder, 
                                  int level);
    void inorderSwapOddLevelFromStack(BinaryTreeNode *node, 
                                      stack<int> &inorder, 
                                      int level);


    void reverseNodesInAlternateLevelPerfectBinaryTreeSingleSwapTraversal();
    void reverseAlternateLevelSwapperTraversal(BinaryTreeNode *left, 
                                               BinaryTreeNode *right, 
                                               int level);

    void convertTreePreorderThroughRightPointers();


    /* Tree Combinations */
    int NumberOfUnlabelledBinaryTreesWithNNodes(int n);
    int NumberOfFullBinaryTreeWithNPlus1Leaves(int n);
    void AllPossibleBinaryTreeForInorder(vector<int> &in);
    vector<BinaryTreeNode*> GenerateBTForInorderUtil(vector<int> &in, int start, int end);
};

#endif