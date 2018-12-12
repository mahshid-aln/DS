#ifndef Agencynode_H
#define Agencynode_H


#include <iostream>
#include <string.h>

using namespace std;

class Agencynode{
    friend class Agencylist;

private:
    Agencynode *link;
    Servicenode *dlink;
    string Agencyname;
    string ID;

public:
    Agencynode(string name, string id){
        Agencyname = name;
        ID = id;
        link = NULL;
        dlink = NULL;

    }
};
#endif
