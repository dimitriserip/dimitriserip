
#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "BaseMenu.h"
#include "ProfessorMenu.h"
#include "StudentMenu.h"
#include "CourseMenu.h"

using namespace std;


class MainMenu : public BaseMenu {
public:
    MainMenu(Database & database);
    virtual ~MainMenu();
    
    virtual void print(ostream& os) const;
    virtual bool applyChoice(int choice);
    
    unsigned int getUserChoice() const;
    
    friend ostream& operator<<(ostream& os , const MainMenu& obj);
private:
    Database & database;
    
    ProfessorMenu professorMenu;
    StudentMenu studentMenu;
    CourseMenu courseMenu;
    
    // TODO: add more menus ....
};

#endif /* MENU_H */
