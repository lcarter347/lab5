// Justin Rice, Lisa Carter, Hannah Zontine
// Lab 5
// Sources: Stack Overflow, cplusplus.com

#include <iostream>
#include <fstream>
#include <string>
#include "treenode.h"
#include "datawrapper.h"
#include "huffman.h"

using namespace std;

int main(){
	string inputFileName;
	cout << "Please enter the name of an input file: " << endl;
	getline(cin, inputFileName);
    Huffman h;
    h.makeTree(inputFileName); 
    char * test = new char[8];
    test[0] = '0';
    test[1] = '0';
    test[2] = '0';
    test[3] = '1';
    test[4] = '1';
    test[5] = '0';
    test[6] = '1';
    test[7] = '1';
    cout << h.decode(test) << endl;




	return 0;
}
