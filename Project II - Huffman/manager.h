#ifndef MANAGER_H
#define MANAGER_H


#include <iostream>
#include "huffmantree.h"
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

class manager{

public:
     huffmantree *huff;
     manager(){
       huff = new huffmantree();
     }

     char getbyAscii(string in){
            int out;
            for (int f=0; f<8; f++){
                out += ((in[7-f]-'0')*pow(2,f));
            }
            return (char)out;
        }

        string binaryOfAscii(char cc){
            string out;
            string invert = "";
            int difer;
            int cint = (int) ((unsigned char) cc);
            out = "";
            while(cint != 0) {
                out += (cint % 2) + '0';
                cint /= 2;
            }
            for(int i = out.length(); i < 8; i++) {
                out += '0';
            }
            invert = out;

            for(int i = 0; i < out.length(); i++) {
                invert[out.length() - i - 1] = out[i];
            }

            return invert;
        }

        void encoding(){
            char ch;
            string one;
            string eight;
            ifstream fp("my.bin", ios::binary);
            ofstream nf("zip.bin", ios::binary);
            if(!nf) cout<<"could not create a file to save the encoded one"<<endl;
            for(int index=0; index < huff->Csize; index++){
                nf << huff->listC[index].c;
                string stcode = " " + huff->bstSearchen(huff->listC[index].c[0])+ " ";
                nf << stcode;
            }
            while(fp.get(ch)){
                one += huff->bstSearchen(ch);
            }
            int modeeight = one.size()%8;
            for(int leg=0; leg<((8-modeeight)%8); leg++){
                one += "1";
            }
            char khar = modeeight + '0';
            nf << khar << ' ';
            string nline = "$& ";
            nf << nline;
            int iter = 0;
            eight = "";
           // cout << "one: " << one << endl;
            while(iter < one.size()){
                for(int j=iter; j<8+iter; j++){
                    eight += one[j];
                }
                nf << getbyAscii(eight);
                eight = "";
                iter += 8;
            }
            fp.close();
            nf.close();
        }

        void decoding(){
            string codes[256];
            for(int i = 0 ; i < 256; i ++) {
                codes[i] = "";
            }
            char toread;
            int i = 0;
            string storage = "";
            string codeplace = "";
            int deadend;
            char first;
            char second;
            char thirdchar = 'a';
            string third = "";
            ifstream fp("zip.bin", ios::binary);
            while(third != "$&"){
                if(third != ""){
                    codes[(unsigned char)first] = third;
                }
                fp.get(first);
                fp.get(second);
                fp >> third;
                fp.get(second);
              //  cout << "aqqq: " << third << endl;
            }
            deadend = (8-(first-'0'))%8;
            //cout<<"endofdic"<<deadend<<endl;
            while(fp.get(toread)) {
                storage += binaryOfAscii(toread);
            }
            //cout << storage.size() << endl;
            ofstream nf("unzip.bin", ios::binary);
            for(int patu=0; patu<(storage.size()-deadend); patu++){
                codeplace += storage[patu];
                for(int toshak=0; toshak<256;toshak++){
                    if( codes[toshak] != "" && codeplace == codes[toshak]){
                        nf << (unsigned char)(toshak);
                        cout << "code: " << codeplace << endl;
                        cout<<(char)toshak<<endl;
                        codeplace = "";
                        break;
                    }

                }
            }
            fp.close();
            nf.close();
        }
};
#endif
