#include "All_Tree.h"

using namespace std;

typedef enum treeType{
    BINARY_TREE = 1,
    BINARY_SEARCH_TREE = 2
}treeType_t;

void treesMain()
{
    unsigned int type;
    vector<int> pre, post, in;
    cout << "Enter Type of Tree: \n" << endl;
    cout << "1. Binary Tree\n" << endl;
    cout << "2. Binary Search Tree\n" << endl;
    cin >> type;
    
    switch(static_cast<treeType_t>(type))
    {
        case BINARY_TREE:
        {
            /* Binary Tree Array Representation */
            cout << "Creating Binary Tree with Array Representation: " << endl;
            BinaryTreeArray BTArray(6,10);

            BTArray.addLeftNode(0, 4);
            BTArray.addLeftNode(1, 2);
            BTArray.addRightNode(0, 12);
            BTArray.addRightNode(1, 6);

            cout << BTArray.getArray() << endl;
            
            {
            cout << "Creating Binary Tree with Linked List Representation: " << endl;
            SinglyLinkedList SLL;
            SLL.Insert(10); SLL.Insert(20); SLL.Insert(30); SLL.Insert(40); SLL.Insert(50);
            SLL.Insert(60); SLL.Insert(70); SLL.Insert(80); SLL.Insert(90);  
            BinaryTree BTList(SLL);
            cout << "Preorder : " << BTList.getPreOrder(true);
            cout << endl;
            }

            {
            cout << "Creating Binary Tree with Left-Child Right-Sibling Representation: " << endl;
            BinaryTreeLChildRSibling BTLChildRSibling;
            BinaryTreeNode *root = BTLChildRSibling.addNewNode(10);
            BinaryTreeNode *n1  = BTLChildRSibling.addChild(root, 2);
            BinaryTreeNode *n2  = BTLChildRSibling.addChild(root, 3);
            BinaryTreeNode *n3  = BTLChildRSibling.addChild(root, 4);
            BinaryTreeNode *n4  = BTLChildRSibling.addChild(n3, 6);
            BinaryTreeNode *n5  = BTLChildRSibling.addChild(root, 5);
            BinaryTreeNode *n6  = BTLChildRSibling.addChild(n5, 7);
            BinaryTreeNode *n7  = BTLChildRSibling.addChild(n5, 8);
            BinaryTreeNode *n8  = BTLChildRSibling.addChild(n5, 9);

            BTLChildRSibling.depthFirstSearch(BTLChildRSibling.getRoot());
            cout << "Depth First Traversal: " << BTLChildRSibling.getDFS();
            BTLChildRSibling.breadthFirstSearch();
            cout << "Breadth First Traversal: " << BTLChildRSibling.getBFS();
            cout << endl;
            }

            {
            BinaryTree BTFull;
            cout << "Creating Full Binary Tree with Pre and Postorder: " << endl;
            vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
            vector<int> post = {4, 5, 2, 6, 7, 3, 1};
            cout << "Given Preorder: " << pre;
            cout << "Given Postorder: " << post;
            BTFull.createFullBTfromPreAndPostorder(pre, post);
            cout << "New Preorder: " << BTFull.getPreOrder(true);
            cout << endl; 
            }

            {
            BinaryTree BTFull;
            cout << "Creating Full Binary Tree with Preorder and Preorder Mirror: " << endl;
            vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
            vector<int> preMirror = {1, 3, 7, 6, 2, 5, 4};
            cout << "Given Preorder: " << pre;
            cout << "Given Preorder Mirror: " << preMirror;
            BTFull.createFullBTFromPreandMirrorPreorder(pre, preMirror);
            cout << "New Preorder: " << BTFull.getPreOrder(true);
            cout << endl; 
            }

            {
            BinaryTree BTFull;
            cout << "Creating Full Binary Tree with Preorder and PreLN Array(Recursive): " << endl;
            vector<int> pre = {1, 2, 4, 8, 9, 5, 3, 6, 7, 10, 11};
            vector<char> preLN = {'N', 'N', 'N', 'L', 'L', 'L', 'N', 'L', 'N', 'L', 'L'};
            cout << "Given preorder: " << pre;
            cout << "Given preLN Array: " << preLN;
            BTFull.createFullBTFromPreandPreLNArrayRecursive(pre, preLN);
            cout << "New Preorder: " << BTFull.getPreOrder(true);
            cout << endl;
            }

            {
            BinaryTree BTFull;
            cout << "Creating Full Binary Tree with Preorder and PreLN Array(Iterative): " << endl;
            vector<int> pre = {1, 2, 4, 8, 9, 5, 3, 6, 7, 10, 11};
            vector<char> preLN = {'N', 'N', 'N', 'L', 'L', 'L', 'N', 'L', 'N', 'L', 'L'};
            cout << "Given preorder: " << pre;
            cout << "Given preLN Array: " << preLN;
            BTFull.createFullBTFromPreandPreLNArrayIterative(pre, preLN);
            cout << "New Preorder: " << BTFull.getPreOrder(true);
            cout << endl;
            }

            {
            /*
            https://www.geeksforgeeks.org/construct-tree-from-ancestor-matrix/
            */
            BinaryTree BTAncestor;
            cout << "Creating One of Possible Binary Tree from Ancestor Matrix: " << endl;
            vector<vector<int>> ancestor = {
                {0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0},
                {0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {1, 1, 1, 1, 1, 0}
            };
            cout << "Given Ancestor Matrix: " << endl;
            cout << ancestor;
            
            BTAncestor.createBTFromAncestorMatrix(ancestor);
            cout << "New Preorder: " << BTAncestor.getPreOrder(true);
            cout << endl;

            /* Get Ancestor Matrix */
            cout << "Preorder: " << BTAncestor.getPreOrder(true);
            cout << "Ancestor Matrix(Backtracking): " << endl;
            cout << BTAncestor.getAncestorMatrixBacktracking();
            cout << "Ancestor Matrix(Transitive Closure): " << endl;
            cout << BTAncestor.getAncestorMatrixTransitiveClosure();
            cout << endl;

            }

            {
            vector<int> parentArray = {-1, 0, 0, 1, 1, 3, 5};
            cout << "Creating BT from Parent Array: " << parentArray;
            BinaryTree BTParentArray;
            BTParentArray.createBTFromParentArray(parentArray);
            cout << "Preorder: " << BTParentArray.getPreOrder(true);
            cout << endl;
            }

            {
            vector<int> levelorderArray = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
            cout << "Creating Complete BT from Level order Array: " << levelorderArray;
            BinaryTree BTComplete;
            BTComplete.createCompleteBTFromLevelOrderArray(levelorderArray);
            cout << BTComplete.getPreOrder(true); 
            cout << endl;
            }

            {
            vector<int> in = {1, 5, 10, 40, 30, 15, 28, 20};
            cout << "Creating Special BT(Parent > its children) from Inorder: " << endl;
            cout << "Given Inorder: " << in;
            BinaryTree BTSplGreaterParent;
            BTSplGreaterParent.createSplBTGreaterParent(in);
            cout << "New Preorder: " << BTSplGreaterParent.getPreOrder(true);
            cout << endl;
            }
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

            cout << "Preorder: " << BT.getPreOrder(true);
            cout << "Deleting Node 150.." << endl;
            BT.Delete(150);
            cout << "Preorder: " << BT.getPreOrder(true);
            cout << endl;

            cout << "Searching Node 125..";
            BinaryTreeNode* node125 = BT.Search(125);
            if(node125 != nullptr)
                cout << "Found Node with 125: " << node125;
            else   
                cout << "Node not Found..";
            cout << endl;
        
            cout << "Searching Node 560.." << endl;
            BinaryTreeNode* node560 = BT.Search(560);
            if(node560 != nullptr)
                cout << "Found Node with 560: " << node560;
            else   
                cout << "Node not Found..";
            cout << endl;

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

            BinaryTree PerfectBinaryTree;
            PerfectBinaryTree.Insert(1); 
            PerfectBinaryTree.Insert(2);
            PerfectBinaryTree.Insert(3);
            PerfectBinaryTree.Insert(4);
            PerfectBinaryTree.Insert(5);
            PerfectBinaryTree.Insert(6);
            PerfectBinaryTree.Insert(7);
            PerfectBinaryTree.Insert(8);
            PerfectBinaryTree.Insert(9);
            PerfectBinaryTree.Insert(10);
            PerfectBinaryTree.Insert(11);
            PerfectBinaryTree.Insert(12);
            PerfectBinaryTree.Insert(13);
            PerfectBinaryTree.Insert(14);
            PerfectBinaryTree.Insert(15);
            PerfectBinaryTree.Insert(16);
            PerfectBinaryTree.Insert(17);
            PerfectBinaryTree.Insert(18);
            PerfectBinaryTree.Insert(19);
            PerfectBinaryTree.Insert(20);
            PerfectBinaryTree.Insert(21);
            PerfectBinaryTree.Insert(22);
            PerfectBinaryTree.Insert(23);
            PerfectBinaryTree.Insert(24);
            PerfectBinaryTree.Insert(25);
            PerfectBinaryTree.Insert(26);
            PerfectBinaryTree.Insert(27);
            PerfectBinaryTree.Insert(28);
            PerfectBinaryTree.Insert(29);
            PerfectBinaryTree.Insert(30);
            PerfectBinaryTree.Insert(31);

            /* Tree Traversals */
            BT.clearPreorder();
            BT.preorderRecurisve(BT.getRoot());
            cout << "Preorder Recursive: " << BT.getPreOrder();
            cout << endl;

            BT.clearInorder();
            BT.inorderRecursive(BT.getRoot());
            cout << "Inorder Recursive: " << BT.getInorder();
            cout << endl;

            BT.clearPostorder();
            BT.postorderRecursive(BT.getRoot());
            cout << "Postorder Recursive: " << BT.getPostOrder();
            cout << endl;

            BT.clearAllTraversals();
            BT.PostPreInOrderInOneFlowRecursive(BT.getRoot());
            cout << "All Three Traversal in Single Recursive Function:" << endl;
            cout << "Preorder: " << BT.getPreOrder();
            cout << "Inorder: " << BT.getInorder();
            cout << "Postorder: " << BT.getPostOrder();
            cout << endl;

            BT.clearInorder();
            int InorderValue4th = -1, inorderCount = 0;
            BT.getNthInorderNode(BT.getRoot(), 4, InorderValue4th, inorderCount);
            cout << "4th Node in Inorder is: " << InorderValue4th << endl;
            cout << endl;

            BT.clearPostorder();
            int PostorderValue5th = -1, postorderCount = 0;
            BT.getNthPostorderNode(BT.getRoot(), 5, PostorderValue5th, postorderCount);
            cout << "5th Node in Postorder is: " << PostorderValue5th << endl;
            cout << endl;

            BT.preorderIterative(BT.getRoot());
            cout << "Preorder Iterative : " << BT.getPreOrder();
            cout << endl;

            BT.preorderIterativeMorris();
            cout << "Preorder Iterative Morris: " << BT.getPreOrder();
            cout << endl;

            BT.inorderIterativeStack(BT.getRoot());
            cout << "Inorder Iterative : " << BT.getInorder();
            BT.inorderIterativeMorris(); 
            cout << "Inorder Iterative Morris: " << BT.getInorder();
            cout << endl;

            BT.postorderIterativeTwoStacks();
            cout << "Postorder Iterative two Stacks: " << BT.getPostOrder();
            BT.postorderIterativeStack(BT.getRoot());
            cout << "Postorder Iterative Stack: " << BT.getPostOrder();
            BT.postorderIterativeHashMap();
            cout << "Postorder Iterative Hash Map: " << BT.getPostOrder();
            cout << endl;

            BT.levelorderQueue(BT.getRoot());
            cout << "Levelorder Queue: " << BT.getLevelOrder();
            BT.levelorderReverseQueue(BT.getRoot());
            cout << "Levelorder(Reverse) Queue: " << BT.getLevelOrderReverse();
            cout << endl;

            PerfectBinaryTree.levelorderSameLevelAlternateToptoBottomLevelQueue(PerfectBinaryTree.getRoot());
            cout << "Perfect Binary Tree Levelorder Same Level Alternate, Top to Bottom Order: " << endl;
            cout << PerfectBinaryTree.getLevelOrderSameLevelAlternateToptoBottom();
            cout << endl;
            
            PerfectBinaryTree.levelorderSameLevelAlternateBottomtoTopLevelQueue(PerfectBinaryTree.getRoot());
            cout << "Perfect Binary Tree Levelorder Same Level Alternate, Bottom to Top Order: " << endl;
            cout << PerfectBinaryTree.getLevelOrderSameLevelAlternateBottomtoTop();
            cout << endl;
            
            BT.zigzagQueue(); 
            cout << "ZigZag Queue: " << BT.getZigzag();
            BT.zigzagDeque(BT.getRoot());
            cout << "ZigZag Deque: " << BT.getZigzag();
            BT.zigzagTwoStacks();
            cout << "ZigZag Two Stacks: " << BT.getZigzag();
            cout << endl;

            BT.spiralDeque(BT.getRoot()); 
            cout << "Spiral Deque: " << BT.getSpiral();
            BT.spiralTwoStacks();
            cout << "Spiral Two Stacks: " << BT.getSpiral();
            cout << endl;

            BT.diagonalQueue(BT.getRoot());
            cout << "Diagonal Queue: " << BT.getDiagonal();
            cout << endl;

            BT.boundaryTraversal();
            cout << "Boundary Traversal : " << BT.getBoundary();
            cout << endl;

            cout << "Get Postorder from Pre and In order: " << endl;
            BT.preorderIterative(BT.getRoot());
            BT.inorderIterativeStack(BT.getRoot());
            pre = BT.getPreOrder();
            in = BT.getInorder();
            cout << "Preorder: " << pre;
            cout << "Inorder: " << in;
            cout << "Postorder: " << BT.getPostfromPreAndIn(pre, in) << endl;




            /* Tree Properties or Conditions */

            /* Is Symmetric Tree ? */
            cout << "Tree: " << BT.getPreOrder(true) << "Symmetric : " << BT.isSymmetric() << endl;
            cout << "Tree: " << BTSymmetric.getPreOrder(true) << "Symmetric: " << BTSymmetric.isSymmetric() << endl;
            cout << endl;

            /* Density of Binary Tree */
            cout << "Density of Binary Tree: " << BT.density() << endl;
            cout << endl;

            /* Has Path Sum */
            cout << "Preorder: " << BT.getPreOrder(true);
            int target1 = 325, target2 = 45;
            cout << "Does any path has given sum (325): " << BT.hasPathSum(BT.getRoot(), target1) << endl;
            cout << "Does any path has given sum (45): " << BT.hasPathSum(BT.getRoot(), target2) << endl;
            cout << endl;

            {
            /* is Children Sum Tree */
            cout << "Preorder: " << BT.getPreOrder(true);
            cout << "Is Children Sum Tree: " << BT.hasChildrenSumProperty(BT.getRoot()) << endl;
            vector<int> pre = {13, 8, 6, 2, 5, 4, 1};
            vector<int> in = {6, 8, 2, 13, 4, 5, 1};
            BinaryTree BTChildSum;
            BTChildSum.setPreorder(pre);
            BTChildSum.setInorder(in);
            BTChildSum.createBTFromInandPreorder();
            cout << "Preorder: " << pre;
            cout << "Is Children Sum Tree: " << BTChildSum.hasChildrenSumProperty(BTChildSum.getRoot()) << endl;
            cout << endl;
            }

            /* Tree Transformations */

            /* Convert to Sum Tree */
            cout << "Original Tree: " << BTSumTree.getPreOrder();
            cout << "Total Sum of BT Nodes: "  << BTSumTree.toSumTree(BTSumTree.getRoot()) << endl;
            cout << "Sum Tree: " << BTSumTree.getPreOrder(true);
            cout << endl;

            /*Convert to Left Subtree Sum Tree */
            {
                BinaryTree BTLeftSumTree;
                vector<int> pre = {1, 2, 4, 5, 3, 6};
                vector<int> in = {4, 2, 5, 1, 3, 6};
                BTLeftSumTree.setPreorder(pre);
                BTLeftSumTree.setInorder(in);
                BTLeftSumTree.createBTFromInandPreorder();
                cout << "Given Preorder: " << BTLeftSumTree.getPreOrder(true);
                BTLeftSumTree.toLeftSumTree(BTLeftSumTree.getRoot());
                cout << "Left Subtree Sum Tree: " << BTLeftSumTree.getPreOrder(true);
                cout << endl;
            }
            
            /* Convert to Mirror Tree */
            BTSumTree.toMirrorRecursive(BTSumTree.getRoot());
            cout << "Mirror Tree - Recurisve: " << BTSumTree.getPreOrder(true);
            BTSumTree.toMirrorIterative();
            cout << "Mirror Tree - Iterative: " << BTSumTree.getPreOrder(true); 
            cout << endl;

            /* Right Flip the Binary Tree */
            BTSumTree.setRoot(BTSumTree.toRightFlip(BTSumTree.getRoot()));
            cout << "Right Flipped : " << BTSumTree.getPreOrder(true);
            cout << endl;

            /* Update Node's value with Inorder Predecessor and Successor */
            cout << "Tree: " << BTSymmetric.getPreOrder(true);
            BTSymmetric.toInorderPredecessorSuccessor(BTSymmetric.getRoot());
            cout << "Sum of Inorder Predecessor & Sucessor: " << BTSymmetric.getPreOrder(true);
            cout << endl;

            {
                /* Convert BT to Tree with Children Sum Property */
                cout << "Converting BT To Tree with Children Sum Property: " << endl;
                vector<int> pre = {50, 7, 3, 5, 2, 1, 30};
                vector<int> in = {3, 7, 5, 50, 1, 2, 30};
                BinaryTree BTConvertToChildSum;
                BTConvertToChildSum.setPreorder(pre);
                BTConvertToChildSum.setInorder(in);
                BTConvertToChildSum.createBTFromInandPreorder();
                cout << "Given Preorder: " << BTConvertToChildSum.getPreOrder(true);
                BTConvertToChildSum.convertBTToChildSumBT(BTConvertToChildSum.getRoot());
                cout << "Converted Preorder: " << BTConvertToChildSum.getPreOrder(true);
                cout << endl;
            }

            /* Popualte Inorder Successor for all nodes in Binary Tree */
            BT.populateInorderSuccessor(BT.getRoot());
            cout << "Inorder Traversal: " << BT.getInorder(true);
            cout << "Inorder Using Sucessor Pointer: ";
            BT.printInorderUsingInorderSuccessorPtr();
            cout << endl;

            /* Find Inorder Successor for given node in Binary Tree */
            BinaryTreeNode* node50 = BT.Search(50);
            if(node50 != nullptr)
            {
                BinaryTreeNode* InorderSuccessor50 = BT.getInorderSuccessor(node50);
                if(InorderSuccessor50 != nullptr)
                    cout << "Inorder Sucessor for 50 is " << InorderSuccessor50 << " " << InorderSuccessor50->data << endl;
                else
                    cout << "Inorder Sucessor for 50 is nullptr" << endl;
                cout << endl;
            }

            /* Reverse Path from Root to given Node in a Binary Tree */
            cout << "Current Preorder: " << BT.getPreOrder(true);
            cout << "Reversing Path to Node(10): ";
            BT.reversePathToNode(10);
            cout << "Reversed. New Preorder: " << BT.getPreOrder(true);
            cout << endl;

            /*  Reverse nodes in alternate level in a Perfect Binary Tree - Two Inorder Traversal   */
            cout << "Current Preorder: " << PerfectBinaryTree.getPreOrder(true);
            cout << "Reversing Nodes in Alternate Levels (Two Inorder Traversal): " << endl;
            PerfectBinaryTree.reverseNodesInAlternateLevelPerfectBinaryTreeTwoTraversal();
            cout << "New Preorder: " << PerfectBinaryTree.getPreOrder(true);
            cout << endl;

            /*  Reverse nodes in alternate level in a Perfect Binary Tree - Single Swap Traversal   */
            cout << "Current Preorder: " << PerfectBinaryTree.getPreOrder(true);
            cout << "Reversing Nodes in Alternate Levels (Single Swap Traversal): " << endl;
            PerfectBinaryTree.reverseNodesInAlternateLevelPerfectBinaryTreeSingleSwapTraversal();
            cout << "New Preorder: " << PerfectBinaryTree.getPreOrder(true);
            cout << endl;

            /* Modify tree such that preorder traversal is achieved through its right pointers */
            cout << "Modifying Tree to get preorder from right pointers alone: " << endl;
            cout << "Current Preorder: " << BT.getPreOrder(true);
            BT.convertTreePreorderThroughRightPointers();
            cout << "Preorder by printing Right Pointers alone: " << endl;
            BT.printRightPointers();
            cout << endl;


            /* Tree Combinations */

            /*  Generating Binary Tree from Inorder and Preorder */
            cout << "Generating Binary Tree from Inorder and Preorder: " << endl;
            cout << "Inorder: " << PerfectBinaryTree.getInorder(true);
            cout << "Preorder: " << PerfectBinaryTree.getPreOrder(true);
            BinaryTree BTFromInAndPre;
            BTFromInAndPre.setInorder(PerfectBinaryTree.getInorder());
            BTFromInAndPre.setPreorder(PerfectBinaryTree.getPreOrder());
            BTFromInAndPre.createBTFromInandPreorder();
            cout << "Generated Tree Preorder: " << BTFromInAndPre.getPreOrder(true);
            cout << endl;

            {
            /* Generating Binary Tree from Inorder and Postorder (Recursive) */
            cout << "Generating Binary Tree from Inorder and Postorder (Recursive): " << endl;
            vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
            vector<int> post = {8, 4, 5, 2, 6, 7, 3, 1};
            cout << "Inorder: " << in << "Postorder: " << post;
            BinaryTree BTFromInandPostRecursive;
            BTFromInandPostRecursive.setInorder(in);
            BTFromInandPostRecursive.setPostorder(post);
            BTFromInandPostRecursive.createBTFromInandPostorderRecursive();
            cout << "Generated Tree Preorder: " << BTFromInandPostRecursive.getPreOrder(true);
            cout << endl;
            }

            {
            /* Generating Binary Tree from Inorder and Postorder (Iterative) */
            cout << "Generating Binary Tree from Inorder and Postorder (Iterative): " << endl;
            vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
            vector<int> post = {8, 4, 5, 2, 6, 7, 3, 1};
            cout << "Inorder: " << in << "Postorder: " << post;
            BinaryTree BTFromInandPostIterative;
            BTFromInandPostIterative.setInorder(in);
            BTFromInandPostIterative.setPostorder(post);
            BTFromInandPostIterative.createBTFromInandPostorderIterative();
            cout << "Generated Tree Preorder: " << BTFromInandPostIterative.getPreOrder(true);
            cout << endl;
            }

            /* Generating Binary Tree from Inorder and Levelorder */
            cout << "Generating Binary Tree from Inorder and Levelorder: " << endl;
            cout << "Inorder: " << PerfectBinaryTree.getInorder(true);
            cout << "Levelorder: " << PerfectBinaryTree.getLevelOrder(true);
            BinaryTree BTFromInandLevel;
            BTFromInandLevel.setLevelorder(PerfectBinaryTree.getLevelOrder());
            BTFromInandLevel.setInorder(PerfectBinaryTree.getInorder());
            BTFromInandLevel.createBTFromInandLevelorder();
            cout << "Generated Tree Preorder: " << BTFromInandLevel.getPreOrder(true);
            cout << endl; 

            cout << "Convert Left-Right Representation to LChild-RSibling Representation in-place: " << endl;
            cout << "Given Preorder: " << PerfectBinaryTree.getPreOrder(true);
            BinaryTreeLChildRSibling BTLChildRSiblingFromBT;
            BTLChildRSiblingFromBT.setRoot(PerfectBinaryTree.getRoot());
            BTLChildRSiblingFromBT.convertToLChildRSibling(BTLChildRSiblingFromBT.getRoot());
            BTLChildRSiblingFromBT.breadthFirstSearch(); 
            BTLChildRSiblingFromBT.depthFirstSearch(BTLChildRSiblingFromBT.getRoot());
            cout << "LChild RSibling BFS: " << BTLChildRSiblingFromBT.getBFS();
            cout << "LChild RSibling DFS: " << BTLChildRSiblingFromBT.getDFS();
            cout << endl;   
           

            /*
            in = BT.getInorder();
            cout << "All possible BTs from given Inorder: " << endl;
            BT.AllPossibleBinaryTreeForInorder(in);
            BT.printAllBTsForInorder();
            cout << endl;
            */
            

            break;
        }
        case BINARY_SEARCH_TREE:
        {
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

               /* Binary Search Tree Constructions */
            cout << "**********************************" << endl;
            cout << " Binary Search Tree Constructions " << endl;
            cout << "**********************************" << endl;
            cout << endl;

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

            cout << "Generating BST Postorder from Preorder: " << endl;
            post.clear();
            post = BST.BSTPostorderFromPreorder(pre);
            cout << "Postorder : " << post << endl;
            cout << endl;

            /* Binary Search Tree Operations */

            cout << "Search node with value(125) in BST: ";
            BinarySearchTreeNode* node125 = BST.Search(125);
            if(node125 != nullptr)
                cout << node125 << " " << node125->data << endl;
            else
                cout << "No Entry Found.." << endl;
            cout << "Search node with value(340) in BST: ";
            BinarySearchTreeNode* node340 = BST.Search(340);
            if(node340 != nullptr)
                cout << node340 << " " << node340->data << endl;
            else
                cout << "No Entry Found.." << endl;
            
            cout << endl;

            cout << "Find Inorder Successor of Given Node(175): ";
            BinarySearchTreeNode* InorderSuccessor175 = BST.getInorderSucessor(BST.Search(175));
            if(InorderSuccessor175 != nullptr)
                cout << InorderSuccessor175 << " " << InorderSuccessor175->data << endl;
            else
                cout << "nullptr" << endl;
            cout << "Find Inorder Successor of Given Node(125): ";
            BinarySearchTreeNode* InorderSuccessor125 = BST.getInorderSucessor(BST.Search(125));
            if(InorderSuccessor125 != nullptr)
                cout << InorderSuccessor125 << " " << InorderSuccessor125->data << endl;
            else
                cout << "nullptr" << endl;
            cout << endl; 
            break;
        }
    }
}
