HERE=.
INCLUDES= -I. \
-I$(HERE)/include \
-I$(HERE)/include/utils \
-I$(HERE)/src/Linked_List \
-I$(HERE)/src/Linked_List/singly_linked_list \
-I$(HERE)/src/Trees \
-I$(HERE)/src/Trees/binary_tree \
-I$(HERE)/src/Trees/binary_tree/binary_search_tree

SRC_FILES= \
$(HERE)/src/main.cc \
$(HERE)/src/AlgoProbIndex.cc \
$(HERE)/src/DataStructProbIndex.cc \
$(HERE)/src/utils/dumps.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)
DEP_FILES= $(SRC_FILES:%.cc=%.d)

ALGO_INDEX_PATH = $(HERE)/src/algorithm_problem_index
ALGO_INDEX_SRC_FILES= \
$(ALGO_INDEX_PATH)/back_tracking_problem_index.cc \
$(ALGO_INDEX_PATH)/binary_search_problem_index.cc \
$(ALGO_INDEX_PATH)/dynamic_programming_problem_index.cc \
$(ALGO_INDEX_PATH)/greedy_problem_index.cc

ALGO_INDEX_OBJ_FILES= $(ALGO_INDEX_SRC_FILES:%.cc=%.o)
ALGO_INDEX_DEP_FILES= $(ALGO_INDEX_SRC_FILES:%.cc=%.d)

DATASTRUCT_INDEX_PATH = $(HERE)/src/data_struct_problem_index
DATASTRUCT_INDEX_SRC_FILES = \
$(DATASTRUCT_INDEX_PATH)/array_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/bit_manipulation_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/graph_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/linked_list_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/mathematics_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/ndarray_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/queue_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/stack_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/string_problem_index.cc \
$(DATASTRUCT_INDEX_PATH)/tree_problem_index.cc

DATASTRUCT_INDEX_OBJ_FILES= $(DATASTRUCT_INDEX_SRC_FILES:%.cc=%.o)
DATASTRUCT_INDEX_DEP_FILES= $(DATASTRUCT_INDEX_SRC_FILES:%.cc=%.d)

LINKED_LIST_PATH= $(HERE)/src/Linked_List
LINKED_LIST_SRC_FILES= \
$(LINKED_LIST_PATH)/Linked_List.cc \
$(LINKED_LIST_PATH)/singly_linked_list/Singly_Linked_List.cc \
$(LINKED_LIST_PATH)/singly_linked_list/Reverse_Linked_List.cc \

LINKED_LIST_OBJ_FILES = $(LINKED_LIST_SRC_FILES:%.cc=%.o)

TREES_PATH= $(HERE)/src/Trees
TREES_SRC_FILES= \
$(TREES_PATH)/Trees.cc \
$(TREES_PATH)/binary_tree/Binary_Tree.cc \
$(TREES_PATH)/binary_tree/Binary_Tree_Array.cc \
$(TREES_PATH)/binary_tree/binary_search_tree/Binary_Search_Tree.cc \
$(TREES_PATH)/binary_tree/binary_search_tree/Construct_BST_From_Preorder.cc \
$(TREES_PATH)/binary_tree/binary_search_tree/Inorder_Successor_For_Node.cc \
$(TREES_PATH)/binary_tree/binary_search_tree/Postorder_From_Preorder.cc \
$(TREES_PATH)/binary_tree/complete_binary_tree/In_And_Levelorder_Array.cc \
$(TREES_PATH)/binary_tree/full_binary_tree/Pre_And_Mirror_Preorder.cc \
$(TREES_PATH)/binary_tree/full_binary_tree/Pre_And_Postorder.cc \
$(TREES_PATH)/binary_tree/full_binary_tree/Pre_And_PreLNArray.cc \
$(TREES_PATH)/binary_tree/perfect_binary_tree/Reverse_Nodes_In_Alternate_Level.cc \
$(TREES_PATH)/binary_tree/tree_creation/Ancestor_Matrix.cc \
$(TREES_PATH)/binary_tree/tree_creation/Greater_Parent_BT_From_Inorder.cc \
$(TREES_PATH)/binary_tree/tree_creation/In_And_Levelorder.cc \
$(TREES_PATH)/binary_tree/tree_creation/In_And_Postorder.cc \
$(TREES_PATH)/binary_tree/tree_creation/In_And_Preorder.cc \
$(TREES_PATH)/binary_tree/tree_creation/Linked_List.cc \
$(TREES_PATH)/binary_tree/tree_creation/Parent_Array.cc \
$(TREES_PATH)/binary_tree/tree_generation/All_BT_For_Inorder.cc \
$(TREES_PATH)/binary_tree/tree_properties/Ancestor_Matrix.cc \
$(TREES_PATH)/binary_tree/tree_properties/Children_Sum_Property.cc \
$(TREES_PATH)/binary_tree/tree_properties/Density.cc \
$(TREES_PATH)/binary_tree/tree_properties/Inorder_Successor.cc \
$(TREES_PATH)/binary_tree/tree_properties/Is_Symmetric.cc \
$(TREES_PATH)/binary_tree/tree_properties/Path_Sum.cc \
$(TREES_PATH)/binary_tree/tree_properties/Total_Nodes.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Children_Sum_Tree.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Inorder_Predecessor_Successor_Sum.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Left_Sum_Tree.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Mirror_Image.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Populate_Inorder_Successor.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Preorder_Through_Right_Pointers.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Reverse_Path_To_Node.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Right_Flip.cc \
$(TREES_PATH)/binary_tree/tree_transformations/Sum_Tree.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Boundary.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Diagonal.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Inorder.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Level_Order.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Postorder.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Pre_Post_Inorder.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Preorder.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Spiral.cc \
$(TREES_PATH)/binary_tree/tree_traversals/Zigzag.cc

TREES_OBJ_FILES= $(TREES_SRC_FILES:%.cc=%.o)

OBJ := 	$(OBJ_FILES) $(ALGO_INDEX_OBJ_FILES) $(DATASTRUCT_INDEX_OBJ_FILES) \
		$(LINKED_LIST_OBJ_FILES) $(TREES_OBJ_FILES)
		
DEP := 	$(DEP_FILES) $(ALGO_INDEX_DEP_FILES) $(DATASTRUCT_INDEX_DEP_FILES)


#Image
GLOBAL_PROBLEM_SET= global_problem_set

all: $(GLOBAL_PROBLEM_SET)

$(GLOBAL_PROBLEM_SET): 	$(OBJ_FILES) $(ALGO_INDEX_OBJ_FILES) $(DATASTRUCT_INDEX_OBJ_FILES) \
					   	$(LINKED_LIST_OBJ_FILES) $(TREES_OBJ_FILES)
	@echo "===== Building Global Problem Set Binary"
	@g++ $(OBJ) -o $(GLOBAL_PROBLEM_SET)

%.o: %.cc
	@echo "g++ -std=c++17 -c $(INCLUDES) $< -o $@"
	@g++ -std=c++17 -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ)
	rm $(GLOBAL_PROBLEM_SET)
	find . -name "*.o" -delete
	