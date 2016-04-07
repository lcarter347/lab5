#include <istream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    ofstream outfile;
    outfile.open("binary.bin", ios::binary | ios::out);
    char bin[] = "0101011";
    cout << "Starting data: " << endl;
    for (int j = 0; j < 8; j++){
        cout << bin[j] << " ";
    }  
    cout << endl;
    
    if (outfile.is_open()){
        outfile.write(reinterpret_cast<char *>(&bin), sizeof(bin));
        if (!outfile.fail()){   
            cout << "Wrote to file" << endl;
        } else {
            cout << "Error writing to file" << endl;
        }
    }
    outfile.close();
   //read - from file to char *
   //write - from char * to file 
    streampos size;
    char * memory;
    ifstream infile;
    infile.open("binary.bin", ios::binary | ios::in);
    if (infile.is_open()){
        infile.seekg(0, ios::end);
        size = infile.tellg();
        memory = new char[size];
        infile.seekg(0, ios::beg);
        infile.read(memory, size);
        infile.close();
        if (!infile.fail()){
            cout << "Read from file" << endl;
        } else {
            cout << "Error reading from file" << endl;
        }
        cout << "Ending data:" << endl;
        int len = strlen(memory);
        for (int k = 0; k < len; k++){
            cout << *(memory + k) << " ";
        }
        cout << endl;
    }

    return 0;
}
