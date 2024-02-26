#ifndef BASEMENU_H
#define BASEMENU_H

#include <iostream>

#define MODE_MAIN_MENU 0
#define MODE_PROFESSOR_MENU 1
#define MODE_STUDENT_MENU 2
#define MODE_COURSE_MENU 3

using namespace std;

class BaseMenu {
public:
    BaseMenu(unsigned int min_choice, unsigned int max_choice);    
    virtual ~BaseMenu();
    
    virtual void print(ostream& os) const = 0;
    virtual bool applyChoice(int choice) = 0;
    
    unsigned int getUserChoice() const;
protected:
    const unsigned int min_choice;
    const unsigned int max_choice;

    static int mode;
};

#endif /* BASEMENU_H */

