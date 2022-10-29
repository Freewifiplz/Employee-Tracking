/*

This program implements 2 base classes and a derived class, along with displaying a menu with the information from 2 text files implemented within the classes.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "employee.h"
#include "employee.cpp"
#include "address.cpp"
#include "address.h"
#include "record.h"
using namespace std;


int numRecords(const char* filename){
    ifstream input;
    input.open(filename);

    if (!input.is_open()){
        cout << "Error opening file...\n";
        return -1;
    }

    int i = 0;
    const int n = 1000;
    char buffer[n];
    while(!input.eof()){
        input.getline(buffer, n);
        if (buffer[0] != '\n')
            i++;
    }

    return i;

}

bool readEmployees(const char* filename, employee*& obj){

    ifstream input;
    input.open(filename);

    if (!input.is_open()){
        cout << "Error opening file...\n";
        return false;
    }

    int id;
    char fullname[1000];
    int dept;
    int i = 0;
    while(input >> id){

        input.getline(fullname, 1000);
        input >> dept;
        obj[i].setemployee_id(id);
        obj[i].setfull_name(fullname);
        obj[i].setobject(dept);
        i++;
    }

    if (input.eof())
        return true;

    return false;
}

bool readAddresses(const char* filename, address* &obj){

    ifstream input;
    input.open(filename);

    if (!input.is_open()){
        cout << "Error opening file...\n";
        return false;
    }

    int ID;
    int street;
    char streetName[1000];
    char city[1000];
    char helper[1000];
    int zip = 0;
    char state[3];

    int c = 0;
    while(input >> ID >> street){
        input.getline(streetName, 1000);
        input.getline(city, 1000);
        input.getline(helper,1000);

        state[0] = helper[0];
        state[1] = helper[1];
        state[2] = '\0';

        int counter = 0;
        zip = 0;

        while(helper[counter++] != '\0');

        for (int i = 0; i < counter; i++){
            if ( (helper[i] - '0') >= 0 && (helper[i] - '0' <= 9)){
                zip = zip * 10 + (helper[i] - '0');
            }
        }

        obj[c].setaddress_id(ID);
        obj[c].setStreetNum(street);
        obj[c].setStreetName(streetName);
        obj[c].setCity(city);
        obj[c].setState(state);
        obj[c].setZip(zip);

        c++;
    }

    if (input.eof())
        return true;

    return false;
}

bool validateRecords(employee* emp, int numEmp, address* add, int numAdd, record* &obj, int& recordSize){

    recordSize = numEmp;

    obj = new record[recordSize];

    for (int i = 0; i < numEmp; i++){

        employee currentEmp = emp[i];

        for (int j = 0; j < numAdd; j++){

            if (currentEmp.getemployee_id() == add[j].getaddress_id()){

                obj[i].setemployee_id(currentEmp.getemployee_id());
                obj[i].setfull_name(currentEmp.getfull_name());
                obj[i].setobject(currentEmp.getobject());

                obj[i].setaddress_id(add[j].getaddress_id());
                obj[i].setCity(add[j].getCity());
                obj[i].setState(add[j].getState());
                obj[i].setStreetName(add[j].getStreetName());
                obj[i].setStreetNum(add[j].getStreetNum());
                obj[i].setZip(add[j].getZip());
                break;

            }
        }
    }

    return true;
}

void display(const employee* obj){

    cout << left << setw(5) << obj->getemployee_id() << "\t";

    if (obj->getfull_name() != nullptr)
        cout << setw(30) << obj->getfull_name() << "\t";
    else cout << left << setw(30) << "NO NAME" << "\t";

    if (obj->getobject() != DEFAULT)
        cout << setw(15) << obj->getobject() << "\t";
    else cout << setw(15) << "NO DEPARTMENT\t";

    cout << endl;

    return;

}

void display(const address* obj){

    cout << left << setw(5) << obj->getaddress_id() << "\t"
              << setw(5) << obj->getStreetNum() << "\t";

    if (obj->getStreetName() != nullptr)
        cout << setw(30) << obj->getStreetName() << "\t";
    else cout << left << setw(30) << "NO STREET NAME" << "\t";

    if (obj->getCity() != nullptr)
        cout << setw(30) << obj->getCity() << "\t";
    else cout << left << setw(30) << "NO CITY NAME" << "\t";

    if (obj->getState() != nullptr)
        cout << setw(30) << obj->getState() << "\t";
    else cout << left << setw(30) << "NO STATE ABBREVIATION" << "\t";

    cout << setw(10) << obj->getZip() << endl;

}

void display(const record* obj){

    cout << left << setw(5) << obj->getemployee_id() << "\t";

    if (obj->getfull_name() != nullptr)
        cout << setw(30) << obj->getfull_name() << "\t";
    else cout << left << setw(30) << "NO NAME" << "\t";

    if (obj->getobject() != DEFAULT)
        cout << setw(15) << obj->getobject() << "\t";
    else cout << setw(15) << "NO DEPT" << "\t";

    cout << left << setw(5) << obj->getaddress_id() << "\t"
              << setw(5) << obj->getStreetNum() << "\t";

    if (obj->getStreetName() != nullptr)
        cout << setw(30) << obj->getStreetName() << "\t";
    else cout << left << setw(30) << "NO STREET NAME" << "\t";

    if (obj->getCity() != nullptr)
        cout << setw(30) << obj->getCity() << "\t";
    else cout << left << setw(30) << "NO CITY NAME" << "\t";

    if (obj->getState() != nullptr)
        cout << setw(30) << obj->getState() << "\t";
    else cout << left << setw(30) << "NO STATE ABBREVIATION" << "\t";

    cout << setw(10) << obj->getZip() << endl;
}

void setString(const char* from, char* &to){

    if (to != nullptr)
        delete[] to;

    int i = 0;
    while(from[i++] != '\0');

    if (from[0] == ' ')
        i-=1;

    to = new char[i];

    i = 0;
    int c = 0;

    if (from[0] == ' ')
        i+=1;

    while (from[i] != '\0'){
        to[c] = from[i];
        i++;
        c++;
    }
    to[c] = '\0'; // valid c-string

    return;
}

void outputHeader (bool is_first, char c, int num=0){
    if (c == 'e'){
        if (is_first)
            cout << left << setw(5) << "ID: " << "\t"
                  << setw(30) << "Employee name: " << "\t"
                  << setw(15) << "Department: " << "\t"
                  << endl;

        else{
            if (num != 1)
                cout << "There are " << num << " employees!\n\n";
            else cout << "There is " << num << " employee!\n\n";
        }
    }if (c == 'a'){
        if (is_first)
            cout << left << setw(5) << "ID: " << "\t"
                      << setw(5) << "num: " << "\t"
                      << setw(30) << "Street name: " << "\t"
                      << setw(30) << "City name: " << "\t"
                      << setw(30) << "State abbreviation: " << "\t"
                      << setw(10) << "Zip code: "
                      << endl;
        else{
            if (num != 1)
                cout << "There are " << num << " addresses!\n\n";
            else cout << "There is " << num << " address!\n\n";
        }
    }if (c == 'r'){
        if (is_first)
            cout << left << setw(5) << "ID: " << "\t"
                      << setw(30) << "Employee name: " << "\t"
                      << setw(15) << "Department: " << "\t"
                      << setw(5) << "ID: " << "\t"
                      << setw(5) << "num: " << "\t"
                      << setw(30) << "Street name: " << "\t"
                      << setw(30) << "City name: " << "\t"
                      << setw(30) << "State abbreviation: " << "\t"
                      << setw(10) << "Zip code: "
                      << endl;
    }
}

void searchAddresses(int key, record* obj, int recordSize){

    bool has_header = false;

    for (int i = 0; i < recordSize; i++){

        if (obj[i].getaddress_id() == key){
            if (!has_header){
                has_header = true;
                outputHeader(true, 'r');
            }
            display(obj+i);
        }

    }

    if (!has_header)
        return;

    outputHeader(false, 'r', obj->getaddress_counter());
}

void searchZipcode(int key, record* obj, int recordSize){
    bool has_header = false;

    for (int i = 0; i < recordSize; i++){

        if (obj[i].getZip() == key){
            if (!has_header){
                has_header = true;
                outputHeader(true, 'r');
            }
            display(obj+i);
        }

    }

    if (!has_header)
        return;

    outputHeader(false, 'r', obj->getaddress_counter());
}

void sortAddresses(record* &obj, int recordSize){

    bool SWAP;
    do{
        SWAP = false;
        for (int i = 0; i < recordSize - 1; i++){
            if (obj[i].getaddress_id() > obj[i+1].getaddress_id()){
                SWAP = true;

                record* temp = new record();

                temp->setaddress_id(obj[i].getaddress_id());
                temp->setCity(obj[i].getCity());
                temp->setobject(obj[i].getobject());
                temp->setemployee_id(obj[i].getemployee_id());
                temp->setfull_name(obj[i].getfull_name());
                temp->setState(obj[i].getState());
                temp->setStreetName(obj[i].getStreetName());
                temp->setStreetNum(obj[i].getStreetNum());
                temp->setZip(obj[i].getZip());

                obj->setaddress_id(obj[i+1].getaddress_id());
                obj->setCity(obj[i+1].getCity());
                obj->setobject(obj[i+1].getobject());
                obj->setemployee_id(obj[i+1].getemployee_id());
                obj->setfull_name(obj[i+1].getfull_name());
                obj->setState(obj[i+1].getState());
                obj->setStreetName(obj[i+1].getStreetName());
                obj->setStreetNum(obj[i+1].getStreetNum());
                obj->setZip(obj[i+1].getZip());

                obj[i+1].setaddress_id(temp->getaddress_id());
                obj[i+1].setCity(temp->getCity());
                obj[i+1].setobject(temp->getobject());
                obj[i+1].setemployee_id(temp->getemployee_id());
                obj[i+1].setfull_name(temp->getfull_name());
                obj[i+1].setState(temp->getState());
                obj[i+1].setStreetName(temp->getStreetName());
                obj[i+1].setStreetNum(temp->getStreetNum());
                obj[i+1].setZip(temp->getZip());

            }
        }
    }while(SWAP);
}

void sortZipcode(record* &obj, int recordSize){

    bool SWAP;
    do{
        SWAP = false;
        for (int i = 0; i < recordSize - 1; i++){
            if (obj[i].getZip() > obj[i+1].getZip()){
                SWAP = true;

                record* temp = new record();

                temp->setaddress_id(obj[i].getaddress_id());
                temp->setCity(obj[i].getCity());
                temp->setobject(obj[i].getobject());
                temp->setemployee_id(obj[i].getemployee_id());
                temp->setfull_name(obj[i].getfull_name());
                temp->setState(obj[i].getState());
                temp->setStreetName(obj[i].getStreetName());
                temp->setStreetNum(obj[i].getStreetNum());
                temp->setZip(obj[i].getZip());

                obj->setaddress_id(obj[i+1].getaddress_id());
                obj->setCity(obj[i+1].getCity());
                obj->setobject(obj[i+1].getobject());
                obj->setemployee_id(obj[i+1].getemployee_id());
                obj->setfull_name(obj[i+1].getfull_name());
                obj->setState(obj[i+1].getState());
                obj->setStreetName(obj[i+1].getStreetName());
                obj->setStreetNum(obj[i+1].getStreetNum());
                obj->setZip(obj[i+1].getZip());

                obj[i+1].setaddress_id(temp->getaddress_id());
                obj[i+1].setCity(temp->getCity());
                obj[i+1].setobject(temp->getobject());
                obj[i+1].setemployee_id(temp->getemployee_id());
                obj[i+1].setfull_name(temp->getfull_name());
                obj[i+1].setState(temp->getState());
                obj[i+1].setStreetName(temp->getStreetName());
                obj[i+1].setStreetNum(temp->getStreetNum());
                obj[i+1].setZip(temp->getZip());

            }
        }
    }while(SWAP);
}

int main(){

    char* input = new char[3];

    record* allRecords = nullptr;

    char employeesFilename[1000];
    char addressFilename[1000];

    int numEmployees = 0;
    int numAddresses = 0;

    int recordSize = 0;

    bool selection [7];

    enum{ a = 0, b, c, d, e, f, g };

    bool to_break;

    employee* allEmployees = nullptr;
    address* allAddresses = nullptr;

    do{
        cout << "Select a letter from the following menu" << endl;
        cout << "a. Enter address file location\nb. Enter employee file location\nc. Read files\nd. Display data\ne. Search\n";
        cout << "\t1. Address ID\n\t2. ZipCode\nf. Sort\n\t1. Address ID\n\t2. ZipCode\ng. Exit\n";

        cin >> input[0];

        if (input[0] == 'e')
            cout << "e. Search";
        if (input[0] == 'f')
            cout << "f. Sort";
        if (input[0] == 'e' || input[0] == 'f'){
            cout << "\n\t1. Address ID\n\t2. ZipCode\n";
            cin >> input[1];
        }

        if (input[0] != 'g'){

            switch(input[0]){
            case 'a':
                selection[a] = true;
                cout << "Enter address file location: \n> ";
                cin >> addressFilename;
                numAddresses = numRecords(addressFilename);
                if (numAddresses != -1){
                    numAddresses /= 3;
                    allAddresses = new address[numAddresses];
                    break;
                }
                selection[a] = false;
                break;
            case 'b':
                selection[b] = true;
                cout << "Enter employees file location: \n> ";
                cin >> employeesFilename;
                numEmployees = numRecords(employeesFilename);
                if (numEmployees != -1){
                    numEmployees /= 2;
                    allEmployees = new employee[numEmployees];
                    break;
                }
                selection[b] = false;
                break;
            case'c':
                if (selection[a] && selection[b]){
                    selection[c] = true;
                }

                if (!selection[c]){
                    cout << "Complete option \'a\' and/or \'b\' first" << endl;
                    break;
                }

                cout << "reading employees file...\n";
                if (!readEmployees(employeesFilename, allEmployees))
                { cout << "unable to read employees file"  << endl; selection[c] = false; break; }
                cout << "reading address file...\n";
                if (!readAddresses(addressFilename, allAddresses))
                { cout << "unable to read address file" << endl; selection[c] = false; break;}
                validateRecords(allEmployees, numEmployees, allAddresses, numAddresses, allRecords, recordSize);
                break;
            case'd':
                if (!(selection[a] && selection[b] && selection[c])){
                    cout << "complete options \'a\', \'b\', \'c\'" << endl;
                    break;
                }
                selection[d] = true;

                for (int i = 0; i < recordSize; i++){

                    if (i==0)
                        outputHeader(true, 'r', allRecords->getaddress_counter());

                    display(allRecords + i);

                }
                break;
            case'e':
                to_break = false;
                for (int i = 0; i < 3; i++){
                    if (!selection[i])
                        to_break = true;
                }

                selection[e] = !to_break;

                if (selection[e]){

                    if (input[1] == '1'){
                        cout << "SEARCH ADDRESS" << endl;
                        cout << "Enter address ID key: " << endl;
                        int key;
                        cin >> key;
                        searchAddresses(key, allRecords, recordSize);
                    }

                    else if (input[1] == '2'){
                        cout << "SEARCH ZIPCODE" << endl;
                        cout << "Enter zipcode key: " << endl;
                        int key;
                        cin >> key;
                        searchZipcode(key, allRecords, recordSize);
                    }

                    else cout << "invalid input" << endl;
                    break;
                }
                cout << "complete options \'a\', \'b\', \'c\'" << endl;
                break;
            case'f':
                to_break = false;
                for (int i = 0; i < 3; i++){
                    if (!selection[i])
                        to_break = true;
                }

                selection[f] = !to_break;

                if (selection[f]){
                    if (input[1] == '1'){
                        sortAddresses(allRecords, recordSize);
                    }

                    else if (input[1] == '2'){
                        sortZipcode(allRecords, recordSize);
                    }

                    else cout << "invalid input" << endl;
                    break;
                }
                else cout << "complete options \'a\', \'b\', \'c\'" << endl;
                break;
            default:
                cout << "INVAILD INPUT" << endl;
            };

        }

    }while(input[0] != 'g');

    delete[] allRecords;

    return 0;

}