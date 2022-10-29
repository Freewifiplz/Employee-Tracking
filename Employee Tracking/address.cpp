#include "address.h"
#include <iostream>
#include <iomanip>
using namespace std;

void setString(const char*, char *&);

int address::address_counter = 0; //static counter

//constructor
address::address() {
    address_id = 0;
    streetNum = 0;
    streetName = nullptr;
    city = nullptr;
    state = nullptr;
    zip = 0;
    address::setaddress_counter(address::getaddress_counter() + 1);
}
//getters
int address::getaddress_id() const {return address_id;}
int address::getStreetNum() const {return streetNum;}
char * address::getStreetName() const {return streetName;}
char * address::getCity() const  {return city;}
char * address::getState() const {return state;}
int address::getZip() const {return zip;}
int address::getaddress_counter() {return address_counter;}

//mutators
void address::setaddress_id(int g) {address_id = g;}
void address::setStreetNum(int g) {streetNum = g;}
void address::setStreetName(char * g) {
    setString(g, streetName);
}

void address::setCity(char * g) {
   setString(g, city);
}

void address::setState(char * g) {
    setString(g, state);
}

void address::setZip(int g) {zip = g;}
void address::setaddress_counter(int g) {address_counter = g;}

//destructor
address::~address() {
    if (streetName != nullptr) {
        delete [] streetName;
    }
    if (city != nullptr) {
        delete [] city;
    }
    if (state != nullptr) {
        delete [] state;
    }
}

//friend function
void display (address* obj) {
    cout << left << setw(5) << obj->address_id << "\t"
              << setw(5) << obj->streetNum << "\t";

    if (obj->streetName != nullptr)
        cout << setw(30) << obj->streetName << "\t";
    else cout << left << setw(30) << "NO STREET NAME" << "\t";

    if (obj->getCity() != nullptr)
        cout << setw(30) << obj->getCity() << "\t";
    else cout << left << setw(30) << "NO CITY NAME" << "\t";

    if (obj->getState() != nullptr)
        cout << setw(30) << obj->getState() << "\t";
    else cout << left << setw(30) << "NO STATE ABBREVIATION" << "\t";

    cout << setw(10) << obj->getZip() << endl;
}


