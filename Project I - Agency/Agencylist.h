#ifndef Agencylist_H
#define Agencylist_H


#include <iostream>
#include <string.h>
#include "Servicelist.h"
#include "Agencynode.h"

using namespace std;


class Agencylist{

private:
    Servicelist *sl;
    Agencynode *first;

public:
    Agencylist(Servicelist *s){
        sl = s;
        first = NULL;
    }

    void addAgency(string name, string id){
        if(!first){
            Agencynode *newnode = new Agencynode(name, id);
            newnode->dlink = sl->first;
            sl->first->reff++;
            first = newnode;
            return;
        }
        Agencynode *p = first;
        while(p->link)
            p = p->link;
        Agencynode *newnode = new Agencynode(name, id);
        newnode->dlink = sl->first;
        sl->first->reff++;
        p->link = newnode;
        newnode->link = NULL;
    }

    void listprint(){
        Agencynode *p = first;
        while(p){
            cout<<"Agency Name: " <<p->Agencyname<<"  ID: "<<p->ID<<endl;
            p = p->link;
        }

    }



};
#endif
