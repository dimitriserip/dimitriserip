OBJS	= BaseMenu.o main.o MainMenu.o Person.o ProfessorMenu.o StudentMenu.o
SOURCE	= BaseMenu.cpp main.cpp MainMenu.cpp Person.cpp ProfessorMenu.cpp StudentMenu.cpp
HEADER	= BaseMenu.h Course.h MainMenu.h Person.h Professor.h ProfessorMenu.h Secretary.h Student.h StudentMenu.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

BaseMenu.o: BaseMenu.cpp
	$(CC) $(FLAGS) BaseMenu.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

MainMenu.o: MainMenu.cpp
	$(CC) $(FLAGS) MainMenu.cpp 

Person.o: Person.cpp
	$(CC) $(FLAGS) Person.cpp 

ProfessorMenu.o: ProfessorMenu.cpp
	$(CC) $(FLAGS) ProfessorMenu.cpp 

StudentMenu.o: StudentMenu.cpp
	$(CC) $(FLAGS) StudentMenu.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
