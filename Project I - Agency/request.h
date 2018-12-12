#ifndef request_H
#define request_H


#include <iostream>
#include "priorityqueue.h"

using namespace std;



class request{
    friend class priorityqueue;

private:
    string service;
    string username;
    string agency;
    int key;
public:
    request(string s, string u, string a, int k){
        service = s;
        username = u;
        agency = a;
        key = k;
    }

};
#endif // request_H
