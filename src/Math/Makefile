HERE=.
INCLUDES= -I.

SRC_FILES= \
$(HERE)/Math.cc \
$(HERE)/Catalan_Number.cc \
$(HERE)/Binomial_Coefficient.cc

OBJ_FILES= $(SRC_FILES:%.cc=%.o)

MATH_EXEC_FILE= math.exe

all: $(MATH_EXEC_FILE)

$(MATH_EXEC_FILE): $(OBJ_FILES)
	@echo "===== Building Math Binary"
	@g++ $(OBJ_FILES) -o $(MATH_EXEC_FILE)

%.o: %.cc
	@echo "g++ -c $(INCLUDES) $< -o $@"
	@g++ -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES)
	rm $(MATH_EXEC_FILE)