#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;


void setString(const char *, char*&);
int employee::employee_counter = 0;

//constructor
employee::employee() {
    employee_id= 0;
    full_name = nullptr;
    object = DEFAULT;
    employee::setemployee_counter(employee::getemployee_counter() + 1);
}
//getters
char *employee::getfull_name() const {return full_name;}
int employee::getemployee_id() const {return employee_id;}
int employee:: getemployee_counter() {return employee_counter;}
DEPARTMENT employee::getobject() const {return object;}

//setters
void employee::setfull_name(const char * g) { //setter for fullname
    setString(g, full_name);
}

void employee::setemployee_id(int g) {employee_id = g;}
void employee::setobject(int g) {
     if (g > 0 && g <= 6){
        object = (DEPARTMENT)g;
        return;
    }
    object = DEFAULT;
    return;
}

void employee::setemployee_counter(int g) {employee_counter = g;}

//destructor
employee::~employee() {
    if (full_name != nullptr) {
        delete [] full_name;
        employee::setemployee_counter(employee::getemployee_counter() - 1);
    }
}
//friend function
void display(employee* obj) {
    cout << left << setw(5) << obj->employee_id << "\t";

    if(obj->full_name != nullptr) {
        cout << setw(30) << obj->full_name << "\t";
    }
    else {
        cout << left << setw(30) << "NO NAME" << "\t";
    }

    if(obj->object != DEFAULT) {
        cout << setw(15) << obj->object << "\t";
    }
    else {
        cout << left << setw(15) << "NO DEPARTMENT\t";
    }
}
