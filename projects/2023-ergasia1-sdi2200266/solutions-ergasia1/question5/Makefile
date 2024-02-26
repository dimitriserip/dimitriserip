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
PROGRAM = question5
LAB = test_infix_evaluation

OBJS = main.o evaluation_module/stack.o evaluation_module/evaluation.o
LAB_OBJS = test_infix_evaluation.o evaluation_module/stack.o evaluation_module/evaluation.o

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