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
PROGRAM = question2
LAB = test_question_2

OBJS = double_linked_list.o main.o
LAB_OBJS = test_double_linked_list.o double_linked_list.o

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