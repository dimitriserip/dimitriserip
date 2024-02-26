
#ifndef COURSEMENU_H
#define COURSEMENU_H

#include <iostream>

#include "BaseMenu.h"
#include "Course.h"
#include "vector"
#include "Database.h"

using namespace std;

class CourseMenu : public BaseMenu {
public:
    CourseMenu(Database & database);
    virtual ~CourseMenu();
    
    virtual void print(ostream& os) const;

    bool deleteCourse(const string& courseName){
        bool found = false;

        for(size_t i = 0; i < database.courses.size(); ++i){
            if(database.courses[i].getName() == courseName) {
                database.courses.erase(database.courses.begin() + i);
                cout << "Course deleted: " <<courseName << endl;
                found = true;
                break;
            }
        }

        if(!found){
            cout << "No course with such name exists: " << courseName << endl;
        }
        return found;
    }

    void printAllCourses(){
        cout << "All Courses: " << endl;
        for(size_t i = 0; i < database.courses.size(); ++i){
            cout << i << " ";
            database.courses[i].printName();
        }
    }
    
    void assignProfessorToCourse();
    
    void unassignProfessorToCourse();

    virtual bool applyChoice(int choice);
private:
    Database & database;
            
    void addCourse(const string& name){
        
        int credits;
        unsigned int semester;
        unsigned int optional;
        
        cout << "Type the credits: ";
        cin >> credits;
        
        cout << "Type the semester [1-8]: ";
        cin >> semester;
        
        cout << "Type optional [0-1] ";
        cin >> optional;
        
        Course course(name, credits, semester, optional == 1);
        
        database.courses.emplace_back(course);
        cout << "Course added: " << name << endl;
    }
    
    void editCourse(const string& name) {
        for (Course & c  : database.courses) {
            if (c.getName() == name) {
                unsigned int semester ;
                unsigned int credits;
                bool optional;

                cout << "Type the semester [1-8]: ";
                cin >> semester;

                cout << "Type the credits [1-6]: ";
                cin >> credits;

                cout << "Is the course optional [true-false]: ";
                cin >> optional;
        
                c.setSemester(semester);
                
                c.setCredits(credits);
                
                c.setOptional(optional);
        
                return;
            }
        }
        
        cout << "Course with such name not found " << endl;
    }
};

#endif /* COURSEMENU_H */
