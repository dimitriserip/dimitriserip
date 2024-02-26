
#include <fstream>
#include "Professor.h"

using namespace std;

ostream& operator<<(ostream& os , const Professor& obj) {
    os << (Person&) obj;
    os << "Year experience    : " << obj.getExperience_in_years() << endl;
    return os;
}