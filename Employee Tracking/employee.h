//employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

enum DEPARTMENT{DEFAULT=0,SALES, CUSTOMER_SERVICE, PRODUCTION, HUMAN_RESOURCES, ACCOUNTING, RESEARCH_AND_DEVELOPMENT};

class employee{
    private:
    char * full_name;
    int employee_id;
    static int employee_counter;
    DEPARTMENT object;

public:
    // constructor
    employee();
    //destructor
    ~employee();

    //accessors
    char * getfull_name() const;
    int getemployee_id() const;
    static int getemployee_counter();
    DEPARTMENT getobject() const;

    //mutators
    void setfull_name(const char *);
    void setemployee_id(int); //setter for id
    void setobject(int);
    void setemployee_counter(int g);

friend void display(employee*); // display friend member function
};
#endif