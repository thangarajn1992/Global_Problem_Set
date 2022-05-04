HERE=.
INCLUDES= -I.

SRC_FILES= \
$(HERE)/Binary_Tree.cc \
$(HERE)/Binary_Search_Tree.cc \
$(HERE)/Trees.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)

TREE_EXEC_FILE= Tree.exe

all: $(TREE_EXEC_FILE)

$(TREE_EXEC_FILE): $(OBJ_FILES)
	@echo "===== Building Tree Binary"
	@g++ $(OBJ_FILES) -o $(TREE_EXEC_FILE)

%.o: %.cc
	@echo "g++ -c $(INCLUDES) $< -o $@"
	@g++ -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm $(TREE_EXEC_FILE)