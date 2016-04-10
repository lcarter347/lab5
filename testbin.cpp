#include <istream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "bin.h"
using namespace std;

int main(){
   //read - from file to char *
   //write - from char * to file

    char * bin;
    char b[] = "010010011";
    cout << "Start data " << b << endl;
    bin = b;
    writeBin(bin,"binary.hzip"); 

    char * read = readBin("binary.hzip");
    int len = strlen(read);
    for (int i = 0; i < len; i++){
        cout << *(read + i) << " ";
    }
    
    cout << endl;

    return 0;
}
