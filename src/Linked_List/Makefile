HERE=.
INCLUDES= -I. \
		  -I../../include

SRC_FILES= \
$(HERE)/Singly_Linked_List.cc \
$(HERE)/Linked_List.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)

LINKED_LIST_EXEC_FILE= Linked_List.exe

all: $(LINKED_LIST_EXEC_FILE)

$(LINKED_LIST_EXEC_FILE): $(OBJ_FILES)
	@echo "===== Building Linked List Binary"
	@g++ $(OBJ_FILES) -o $(LINKED_LIST_EXEC_FILE)

%.o: %.cc
	@echo "g++ -c $(INCLUDES) $< -o $@"
	@g++ -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm $(LINKED_LIST_EXEC_FILE)