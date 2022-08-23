HERE=.
INCLUDES= -I. \
		  -I../../include \
		  -I../Linked_List \
		  -I../Linked_List/singly_linked_list

SRC_FILES= \
$(HERE)/Binary_Tree.cc \
$(HERE)/Binary_Search_Tree.cc \
$(HERE)/Trees.cc \
$(HERE)/Trees_Main.cc \
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