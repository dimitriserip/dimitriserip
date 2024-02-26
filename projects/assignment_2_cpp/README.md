# Part 1 of the first assignment

1. I created 2 classes , one person and one secretary.Each class has a cpp and a header file.
2. Also there is a main file ass asked.
3. All questions asked are implemented in the code.
4. In operator+ i create a new array , copy the already existing data , destroy the old and copy the new to the department array which is the array of the Secretary class. There is a better way of implementing this , using vectors so that i dont duplicate the array with every entry of a Person in the Secretary class.
5. I also created a make file with the following commands:
    a. make , to compile.
    b. make run , to run.
    c. make clean , to clean extra files.
6. Only difficulty i encountered was understanding how to use oparators.

# Part 2 of the assignment

1. First of all , there are some questions asking us to load and save files , i have seperate files for the load and seperate for the save because its easier to fix mistakes if made , the code works perfectly , and i have done all the questions asked , but i did it this way to preserve the load file so i dont make changes to it from  a mistake in the code.
2. As i said all the questions are done , i have defined the year as 2024 -> 24.Also in the same file: constants.h i have implemented the concept of the academic semester and added it where is needed in the tasks.
3. There are 3 seperate menus , one for students , ne for professors and one for the courses.
4. Every menu has its own questions to it .
5. I have also created a database to store all the information and be able to access it from everywhere i want with ease.
6. The BaseMenu is a base for all the menus , such as the main menu and the other i said in the 3rd bullet.
7. The main function is very simple , i have just created a loop where it takes in a choice and i apply it with the applyChoice funtion and it keeps printing the menu.
8. The editor of choice is Netbeans , so the makefile is a little different here.
