#ifndef Servicelist_H
#define Servicelist_H


#include <iostream>
#include "Servicenode.h"

using namespace std;


class Servicelist{
    friend class Agencylist;
private:
    Servicenode *first;

public:
    Servicelist(){
        first = new Servicenode(0, 1,"" , this);
    }


    void addservice(string name){
        Servicenode *x;
        if(findadress(name, x)!=NULL){
            cout<<"service was added before"<<endl;
            return;
        }
        if(!first->link){
            Servicenode *newnode = new Servicenode(1, -1,name, NULL);
            first->link = newnode;
            return;
        }
        Servicenode *p = first;
        while(p->link)
            p = p->link;
        Servicenode *newnode = new Servicenode(1,-1, name, NULL);
        p->link = newnode;

    }

    Servicenode *findadress(string wanted, Servicenode* &prev){
        Servicenode *s = first->link;
        Servicenode *run = first;
        Servicenode *res;

        while(s){
                //cout<<"start of while"<<endl;
            if(s->data->name == wanted){
                //cout<<s->data->name<<"func";
                prev = run;
                return s;
            }
                //cout<<"middle of while"<<endl;
            if(s->dlink){
                res = s->dlink->findadress(wanted, run);
                if(res){
                    prev = run;
                    return res;
                }
            }
            s = s->link;
            run = run->link;
        }
        return NULL;
    }


    void addsubservice(string subname, string parentname){
        Servicenode *ptr;
        Servicenode *sth = findadress(parentname, ptr);
        if(!sth)
            return;
        if(!(sth->dlink)){
            sth->dlink = new Servicelist();
            sth->dlink->addservice(subname);
        }
        else{
            sth->dlink->addservice(subname);
        }
    }


    void addparent(string service, string parent){
        Servicenode *parprev;
        Servicenode *parentadress = findadress(parent, parprev);
        if(!parentadress) return;
        Servicenode *serprev;
        Servicenode *servicadress = findadress(service, serprev);
        if(!servicadress) return;
        if (serprev->tag!=0)
            return;
        serprev->dlink->first->reff++;
        parentadress->dlink = serprev->dlink;


    }

    void printmainservice(){
        Servicenode *p = first->link;
        if(!p) return;
        while(p){
            cout<<"Service Name: "<<p->data->name<<endl;
            p = p->link;
        }
    }

    void printsubservice(string parent){
        Servicenode *q;
        //cout << 111 << endl;
        Servicenode *p = findadress(parent, q);
        //cout << 222 << endl;
        if(p->dlink){
            //cout << "ref: " << p->dlink->first->reff << endl;
            p->dlink->printmainservice();
        }
        //cout << 333 << endl;
    }

    void deletefunc(string deleted){
        Servicenode *kooft;
        Servicenode *marg = findadress(deleted, kooft);
        if(!marg) return;
        kooft->link = marg->link;
        if(marg->dlink) {
            deletelist(marg->dlink->first);
        }
        delete marg;
    }

    void deletelist(Servicenode *p){
        Servicenode *q;
        if(!p) return;
        p->reff--;
        if(p->reff) return;
            while(p){
                if(p->dlink){
                    deletelist(p->dlink->first);
                }
                q = p->link;
                delete p;
                p = q;
            }

    }
};

#endif
