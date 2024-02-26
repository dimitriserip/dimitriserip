# compile with gcc
CC=gcc

# Compiler options:
#
# -pg is used for profiling (gprof)
CFLAGS = -g

# Linker options:
#
# -lm: link with the math library
LDFLAGS += -lm

# set the name of the executable file to compile here
PROGRAM = question6
LAB = test_BT

OBJS = main.o btree.o item.o
LAB_OBJS = test_BT.o btree.o item.o

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

$(LAB): $(LAB_OBJS)
	$(CC) $(CFLAGS) $(LAB_OBJS) $(LDFLAGS) -o $(LAB)

clean:
	rm -f $(PROGRAM) $(OBJS) $(LAB) $(LAB_OBJS)

run: clean $(PROGRAM)
	./$(PROGRAM)

test: clean $(LAB)
	./$(LAB)