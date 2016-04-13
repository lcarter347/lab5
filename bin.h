/*Lisa Carter, Justin Rice, Hannah Zontine*/

#include <istream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "StanfordCPPLib/bitstream.h"

#ifndef BIN_H_
#define BIN_H_

using namespace std;

void writeBin(char * bin, string filename);
char * readBin(string filename, int length);


void writeBin(char * bin, string filename){
    ofbitstream outfile (filename.c_str());    
    if (outfile.is_open()){
        for (int i = 0; i < strlen(bin); i++){
            if (*(bin + i) == '0'){
                outfile.writeBit(0);
            } else if (*(bin + i) == '1'){
                outfile.writeBit(1);
            } else {
                cout << "Char array is corrupted" << endl;
                break;
            }
            if (outfile.fail()){
                cout << "Error writing to file" << endl;
                break;
            }
        }
        outfile.close();

    }
}


char * readBin(string filename, int length){
    string bits;
    int temp;
    string str;
    char * bin;
    ifbitstream infile;
    stringstream ss;
    infile.open(filename.c_str());
    if (infile.is_open()){   
        for (int i = 0; i < length; i++){
            if (infile.fail()){
                cout << "Error reading from file" << endl;
                return NULL;
            }  
            
            temp = infile.readBit();
            if (temp == -1){
                break;
            } else {
                ss << temp;
                while(!(ss >> str)){
                    cout << "File cannot be read" << endl;
                    infile.close();
                    return NULL;
                }
                bits += str;
            }
            ss.clear();
            ss.str("");
        }
        infile.close();
        bin = const_cast<char*>(bits.c_str());
        return bin;
    } else {
        return NULL;
    }
}

#endif
