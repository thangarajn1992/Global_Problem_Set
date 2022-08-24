#include "../../include/DataStructProbIndex.h"

void
addTreeProblems()
{
    /* Tree Constructions */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BT_From_Parent_Array_Representation");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BT_From_Linked_List_Representation");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BT_From_Inorder_And_Preorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BT_From_Inorder_And_Postorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BT_From_Inorder_And_Levelorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_Complete_BT_From_Levelorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_Full_BT_From_Preorder_And_Postorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_Full_BT_From_Preorder_And_Preorder_Of_Mirror_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_Full_BT_From_Preorder_And_PreLN_Array");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_One_BT_From_Ancestor_Matrix");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_Greater_Parent_BT_From_Inorder");
    
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Construct_BST_From_Preorder");


    /* Tree Traversals */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Preorder_Traversal"); // Recursive , Iterative
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Preorder_Morris_Traversal");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Inorder_Traversal");  // Recursive, Iterative
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Inorder_Morris_Traversal"); 
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Postorder_Traversal"); // Recursive, Two-Stack, One-Stack, Hash-Map
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Postorder_From_Preorder_And_Inorder");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Pre_Post_Inorder_Single_Recursive");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Nth_Inorder_Node");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Nth_Postorder_Node");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Level_Order_Traversal");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Reverse_Level_Order_Traversal");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Levelorder_LeftRight_Alternate_Top_To_Bottom");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Levelorder_LeftRight_Alternate_Bottom_To_Top");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "ZigZag_Traversal"); // Queue, deque, Two Stacks
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Spiral_Traversal"); // deque, Two Stacks
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Diagonal_Traversal");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Boundary_Traversal");

    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Postorder_From_Preorder_In_BST");

    /* Tree Properties */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Total_Nodes_In_Binary_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Is_Symmetric_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Find_Height_Size_Density_Of_Binary_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Has_Path_With_Target_Sum");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Has_Children_Sum_Property");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Ancestor_Matrix_For_BT_Backtracking");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Ancestor_Matrix_For_BT_Transitive_Closure");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Inorder_Successor_For_Node_In_BT");
    
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Get_Inorder_Successor_For_Node_In_BST");

    /* Tree Transformations */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_To_Sum_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_To_Left_Subtree_Sum"); /* Node = node + left sub-tree */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_To_Mirror_Image"); /* Recursive, Iterative */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Right_Flip");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_Nodes_To_Inorder_Predecessor_Successor_Sum");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_To_Children_Sum_Tree");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Populate_All_Nodes_With_Inorder_Successor");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Reverse_Path_Till_Node_Specified_In_BT");
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Reverse_Nodes_In_Alternate_Level_In_Perfect_BT"); /* Two inorder, single swap traversal */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Convert_Right_pointers_To_Have_Preorder_Traversal");

    /* Tree Generation */
    dsProblemDB.add_dsProblem(DSTYPE_TREE, "Generate_All_Possible_BT_For_Inorder");




    


}