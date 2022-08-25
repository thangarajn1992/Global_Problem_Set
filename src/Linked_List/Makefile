HERE=.
INCLUDES= -I. \
		  -I../../include \
		  -I./singly_linked_list

SRC_FILES= \
$(HERE)/Linked_List_Main.cc \
$(HERE)/Linked_List.cc \
$(HERE)/singly_linked_list/Singly_Linked_List.cc \
$(HERE)/singly_linked_list/Reverse_Linked_List.cc \
$(HERE)/singly_linked_list/Is_Palindrome.cc \
$(HERE)/singly_linked_list/Linked_List_Cycle.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)

LINKED_LIST_EXEC_FILE= Linked_List.exe

all: $(LINKED_LIST_EXEC_FILE)

$(LINKED_LIST_EXEC_FILE): $(OBJ_FILES)
	@echo "===== Building Linked List Binary"
	@g++ $(OBJ_FILES) -o $(LINKED_LIST_EXEC_FILE)

%.o: %.cc
	@echo "g++ -std=c++17 -c $(INCLUDES) $< -o $@"
	@g++ -std=c++17 -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm $(LINKED_LIST_EXEC_FILE)