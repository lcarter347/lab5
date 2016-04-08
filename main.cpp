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
    cout << h.encode("a") << endl;
    cout << h.encode("b") << endl;
    cout << h.encode("c") << endl;
    cout << h.encode("d") << endl;
    cout << h.encode("aabbccddabcd") << endl;
    string test2 = "000001011010111100011011";
    char * test2A = new char[test2.size()+1];
    copy(test2.begin(), test2.end(), test2A);
    test2A[test2.size()] = '\0';
    
    cout << h.decode(test2A) << endl; 

    char * test3 = h.encode("abcabcabc");
    cout << h.decode(test3) << endl;
	return 0;
}
