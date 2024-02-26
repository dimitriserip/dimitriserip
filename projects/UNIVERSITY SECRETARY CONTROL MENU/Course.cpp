
#include <fstream>
#include "Course.h"

using namespace std;

ostream& operator<<(ostream& os, const Course& obj) {
    os << "--------------------------------------------" << endl;
    os << "Name is            : " << obj.name << endl;
    os << "Credits            : " << obj.credits << endl;
    os << "Semester           : " << obj.semester << endl;
    os << "Optional           : " << ((obj.optional) ? "true" : "false") << endl;
    os << "Professors         : ";
    
    for (const Professor * p : obj.professors) {
        cout << p->getName() << ", " ;
    }
    cout << endl;
    return os;
}
