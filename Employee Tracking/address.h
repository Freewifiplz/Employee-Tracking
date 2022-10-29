//address.h
#ifndef ADDRESS_H
#define ADDRESS_H

class address{
    private:
    int address_id;
    int streetNum;
    char * streetName;
    char * city;
    char * state;
    int zip;
    static int address_counter;
public:
//constructor
    address();
    //destructor
    ~address();
    
    //accessors
    int getaddress_id() const;
    int getStreetNum() const;
    char * getStreetName() const;
    char * getCity() const;
    char * getState() const;
    int getZip() const;
    static int getaddress_counter();

    //mutators
    void setaddress_id(int);
    void setStreetNum(int);
    void setStreetName(char *);
    void setCity(char *);
    void setState(char *);
    void setZip(int);
    void setaddress_counter(int g);
    
    //friend function
    friend void display(address*);
};
#endif