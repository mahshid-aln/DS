#include <iostream>
#include <fstream>
#include <string>
#include "huffmantree.h"
#include "manager.h"
using namespace std;

int main()
{
    manager *prog;
    string decide;
    string filename;
    while(true){
        cout<<"'zip' to zip or 'unzip' to unzip"<<endl;
        cout<<"press end to exit"<<endl;
        cin>>decide;
        if(decide == "zip"){
            cout<<"enter the name of the file"<<endl;
            cin>>filename;
            filename += ".bin";
            prog = new manager();

            prog->huff->countTheChars();
            prog->huff->configureListB();
            prog->huff->configureListC();
            prog->huff->makeTree();
            prog->huff->preorderIteration(prog->huff->listB[0].point);
            prog->huff->makeBstofC();
            prog->encoding();
            cout<<"done"<<endl;
        }
        else
        if(decide == "unzip"){
            prog->decoding();
        }
        else
        if(decide == "end")
            return 0;
    }
}


