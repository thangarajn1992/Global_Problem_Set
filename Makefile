HERE=.
INCLUDES= -I. \
-I$(HERE)/include \
-I$(HERE)/include/utils \
-I$(HERE)/src/Linked_List \
-I$(HERE)/src/Trees

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
$(LINKED_LIST_PATH)/Singly_Linked_List.cc

LINKED_LIST_OBJ_FILES = $(LINKED_LIST_SRC_FILES:%.cc=%.o)

TREES_PATH= $(HERE)/src/Trees
TREES_SRC_FILES= \
$(TREES_PATH)/Trees.cc \
$(TREES_PATH)/Binary_Tree.cc \
$(TREES_PATH)/Binary_Search_Tree.cc 

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
	