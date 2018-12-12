#ifndef ServiceData_H
#define ServiceData_H


#include <iostream>

using namespace std;


class ServiceData{
    friend class Servicenode;
private:

    string model;
    string clientExpl;
    string technicExpl;
    float runlength;
    float cost;

public:

    string name;

    ServiceData(string n){
        name = n;


    }

};
#endif
