#ifndef pQueue_H
#define pQueue_H


#include <iostream>
#include <vector>
#include <math.h>
#include "request.h"
#include "Agencylist.h"
#include "Servicelist.h"
using namespace std;


class priorityqueue{
private:

    vector<request> requests;

    Agencylist *al;
    Servicelist *sl;
public:
     priorityqueue(Agencylist *AL, Servicelist *SL){

        al = AL;
        sl = SL;
    }

    /*int leftleaf(int i){
        return (2*i + 1);

    }
    int rightleaf(int i){
        return (2*i + 2);
    }

    void maxheapify(int i){
        if(i >= requests.size()) return;
        int l = leftleaf(i);
        int r = rightleaf(i);
        int largest;
        if(requests.size() > l && requests[l].key > requests[i].key)
            largest = l;
        else
            largest = i;
        if(requests.size() > r && requests[r].key > requests[largest].key)
            largest = r;
        if(largest != i){
            //request tmp = new request(requests[i].service , requests[i].username , requests[i].agency , requests[i].key);
            request *tmp = new request("" , "", "", -1);
            *tmp = requests[i];
            requests[i] = requests[largest];
            requests[largest] = *tmp;
        }
            if(i-1 >= 0)
                maxheapify((int)floor((i-1)/2));
               // maxheapify(largest);
    }*/


    void sortrequests(){
        int s = requests.size();
        request *r = new request("", "", "", -1);
        for(int i = s-1; i>= 1; i--){
            if(requests[i].key < requests[i-1].key){
                *r = requests[i-1];
                requests[i-1] = requests[i];
                requests[i] = *r;
            }
        }
    }

    void addrequest(request r){
        requests.push_back(r);
        //maxheapify((int)floor((requests.size()-1)/2));
        sortrequests();
    }

    void getrequest(string agency){
        for(int i=0; i < requests.size(); i++){
            if(requests[i].agency == agency) {
                cout<<"Agency: "<<agency<<endl;
                cout<<"Username: "<<requests[i].username<<endl;
                cout<<"Service: "<<requests[i].service<<endl;
                cout<<"Priority: "<<requests[i].key<<endl<<endl;
            }
        }

    }

};
#endif
