OBJS	= Person.o Secretary.o main.o
SOURCE	= Person.cpp Secretary.cpp main.cpp
HEADER	= Person.h Secretary.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Person.o: Person.cpp
	$(CC) $(FLAGS) Person.cpp 

Secretary.o: Secretary.cpp
	$(CC) $(FLAGS) Secretary.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
