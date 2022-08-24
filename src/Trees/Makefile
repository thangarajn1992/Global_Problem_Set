HERE=.
INCLUDES= -I. \
		  -I./binary_tree \
		  -I./binary_tree/binary_search_tree \
		  -I./binary_tree/complete_binary_tree \
		  -I./binary_tree/full_binary_tree \
		  -I./binary_tree/perfect_binary_tree \
		  -I./binary_tree/tree_creation \
		  -I./binary_tree/tree_generation \
		  -I./binary_tree/tree_properties \
		  -I./binary_tree/tree_transformations \
		  -I./binary_tree/tree_traversals \
		  -I../../include \
		  -I../Linked_List \
		  -I../Linked_List/singly_linked_list

SRC_FILES= \
$(HERE)/Trees.cc \
$(HERE)/Trees_Main.cc \
$(HERE)/binary_tree/Binary_Tree.cc \
$(HERE)/binary_tree/Binary_Tree_Array.cc \
$(HERE)/binary_tree/binary_search_tree/Binary_Search_Tree.cc \
$(HERE)/binary_tree/binary_search_tree/Construct_BST_From_Preorder.cc \
$(HERE)/binary_tree/binary_search_tree/Inorder_Successor_For_Node.cc \
$(HERE)/binary_tree/binary_search_tree/Postorder_From_Preorder.cc \
$(HERE)/binary_tree/complete_binary_tree/In_And_Levelorder_Array.cc \
$(HERE)/binary_tree/full_binary_tree/Pre_And_Mirror_Preorder.cc \
$(HERE)/binary_tree/full_binary_tree/Pre_And_Postorder.cc \
$(HERE)/binary_tree/full_binary_tree/Pre_And_PreLNArray.cc \
$(HERE)/binary_tree/perfect_binary_tree/Reverse_Nodes_In_Alternate_Level.cc \
$(HERE)/binary_tree/tree_creation/Ancestor_Matrix.cc \
$(HERE)/binary_tree/tree_creation/Greater_Parent_BT_From_Inorder.cc \
$(HERE)/binary_tree/tree_creation/In_And_Levelorder.cc \
$(HERE)/binary_tree/tree_creation/In_And_Postorder.cc \
$(HERE)/binary_tree/tree_creation/In_And_Preorder.cc \
$(HERE)/binary_tree/tree_creation/Linked_List.cc \
$(HERE)/binary_tree/tree_creation/Parent_Array.cc \
$(HERE)/binary_tree/tree_generation/All_BT_For_Inorder.cc \
$(HERE)/binary_tree/tree_properties/Ancestor_Matrix.cc \
$(HERE)/binary_tree/tree_properties/Children_Sum_Property.cc \
$(HERE)/binary_tree/tree_properties/Density.cc \
$(HERE)/binary_tree/tree_properties/Inorder_Successor.cc \
$(HERE)/binary_tree/tree_properties/Is_Symmetric.cc \
$(HERE)/binary_tree/tree_properties/Path_Sum.cc \
$(HERE)/binary_tree/tree_properties/Total_Nodes.cc \
$(HERE)/binary_tree/tree_transformations/Children_Sum_Tree.cc \
$(HERE)/binary_tree/tree_transformations/Inorder_Predecessor_Successor_Sum.cc \
$(HERE)/binary_tree/tree_transformations/Left_Sum_Tree.cc \
$(HERE)/binary_tree/tree_transformations/Mirror_Image.cc \
$(HERE)/binary_tree/tree_transformations/Populate_Inorder_Successor.cc \
$(HERE)/binary_tree/tree_transformations/Preorder_Through_Right_Pointers.cc \
$(HERE)/binary_tree/tree_transformations/Reverse_Path_To_Node.cc \
$(HERE)/binary_tree/tree_transformations/Right_Flip.cc \
$(HERE)/binary_tree/tree_transformations/Sum_Tree.cc \
$(HERE)/binary_tree/tree_traversals/Boundary.cc \
$(HERE)/binary_tree/tree_traversals/Diagonal.cc \
$(HERE)/binary_tree/tree_traversals/Inorder.cc \
$(HERE)/binary_tree/tree_traversals/Level_Order.cc \
$(HERE)/binary_tree/tree_traversals/Postorder.cc \
$(HERE)/binary_tree/tree_traversals/Pre_Post_Inorder.cc \
$(HERE)/binary_tree/tree_traversals/Preorder.cc \
$(HERE)/binary_tree/tree_traversals/Spiral.cc \
$(HERE)/binary_tree/tree_traversals/Zigzag.cc \
$(HERE)/../Linked_List/Linked_List.cc \
$(HERE)/../Linked_List/singly_linked_list/Singly_Linked_List.cc \
$(HERE)/../Linked_List/singly_linked_list/Reverse_Linked_List.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)

TREE_EXEC_FILE= Tree.exe

all: $(TREE_EXEC_FILE)

$(TREE_EXEC_FILE): $(OBJ_FILES)
	@echo "===== Building Tree Binary"
	@g++ $(OBJ_FILES) -o $(TREE_EXEC_FILE)

%.o: %.cc
	@echo "g++ -std=c++17 -c $(INCLUDES) $< -o $@"
	@g++ -std=c++17 -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm $(TREE_EXEC_FILE)