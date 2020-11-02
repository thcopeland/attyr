OBJ_DIR=./obj
SRC_DIR=./src
INC_DIR=./inc
TST_DIR=./test
TST_OBJ_DIR=./test/obj

TEST_BIN=run_tests

LIBS=-lm
CFLAGS=-I$(INC_DIR) -O3 -Wall

_MAIN_OBJ=matrices.o rasterize.o main.o transform.o
MAIN_OBJ=$(patsubst %,$(OBJ_DIR)/%,$(_MAIN_OBJ))

_TEST_OBJ=test_matrices.o test_helpers.o test_main.o
TEST_OBJ=$(patsubst %,$(TST_OBJ_DIR)/%,$(_TEST_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -o $@ $< $(CFLAGS)

$(TST_OBJ_DIR)/%.o: $(TST_DIR)/%.c
	gcc -c -o $@ $< $(CFLAGS)

tggr: $(MAIN_OBJ)
	gcc -o $@ $^ $(LIBS)

test: $(MAIN_OBJ) $(TEST_OBJ)
	gcc -o $(TEST_BIN) $^ $(LIBS)

.PHONY: clean

clean:
	rm $(MAIN_OBJ) $(TEST_OBJ) $(TEST_BIN)
