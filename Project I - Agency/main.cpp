#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "Agencylist.h"
#include "Agencynode.h"
#include "Servicelist.h"
#include "Servicenode.h"
#include "priorityqueue.h"
#include "request.h"

using namespace std;

int main()
{
    Servicelist *allService = new Servicelist();
    Agencylist *allAgency = new Agencylist(allService);
    priorityqueue *allRequest = new priorityqueue(allAgency, allService);
    string command;
    cout<<"enter command!"<<endl<<"press <end> exit"<<endl;

    while(1){
        cin>>command;
        if(command == "Add"){
            cin>>command;
            if(command == "new"){
                cin>>command;
                if(command == "service"){
                    cin>>command;
                    allService->addservice(command);
                }
                else
                if(command == "agency"){
                    cin>>command;
                    string id = "";
                    string name = "";
                    int i = 0;
                    while(command[i] != ':'){
                        id += command[i];
                        i++;
                    }
                    while(i < command.size()){
                        name += command[i+1];
                        i++;
                    }
                    allAgency->addAgency(name , id);
                }
            }
            else
            if(command == "subservice"){
                cin>>command;
                string sub = command;
                cin>>command;
                cin>>command;
                allService->addsubservice(sub, command);
                //Servicenode *p;
                //Servicenode *q = allService->findadress(command, p);
                //if(q)
//                cout<<q->data->name<<endl;
//                if(p)
//                cout<<p->data->name<<endl;
            }
            else
            if(command == "parent"){
                cin>>command;
                string par = command;
                cin>>command;
                cin>>command;
                allService->addparent(command, par);
            }


        }
        else
        if(command == "List"){
            getline(cin, command);
            if(command == " agency"){
                allAgency->listprint();
            }
            else
            if(command == " services"){
                allService->printmainservice();
            }
            else
            {   string check;
                for(int j=0; j<15; j++)
                    check += command[j];
                if(check == " services from "){
                    string par = "";
                    for(int i = 15; i < command.size(); i++)
                        par += command[i];
                    allService->printsubservice(par);
                }
            }
        }

        else
        if(command == "Delete"){
            cin>>command;
            allService->deletefunc(command);
        }
        else
        if(command == "Request"){
            cin>>command;
            string sname = command;
            cin>>command;
            cin>>command;
            string agname = command;
            cin>>command;
            cin>>command;//username
            string uname = command;
            int k;
            cout<<"enter priority"<<endl;
            cin>>k;
            request *r = new request(sname, uname, agname, k);
            allRequest->addrequest(*r);
        }
        else
        if(command == "Get"){
            cin>>command;
            if(command == "requests"){
                cin>>command;
                cout<<command<<" 121 ";
                allRequest->getrequest(command);
            }
        }
        else
        if(command == "end")
            break;



    }

    return 0;

}
