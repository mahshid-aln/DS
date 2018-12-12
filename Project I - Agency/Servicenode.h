#ifndef Servicenode_H
#define Servicenode_H


#include <iostream>
#include "ServiceData.h"
#include "Agencylist.h"

using namespace std;


class Servicenode{
    friend class Servicelist;
    friend class Agencylist;
private:
    Servicenode *link;
    Servicelist *dlink;
    int tag; //-1 for data 0 for reff 1 for data
public:
    ServiceData *data;
    int reff;



public:

    Servicenode(int tg, int r, string n, Servicelist *sl){
    tag = tg;
    data = new ServiceData(n);
    reff = r;

    link = NULL;
    dlink = sl;

    }


};
#endif
