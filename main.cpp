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
    string compressedFile, encodedFile;
    string task;
    Huffman h;
    cout << "Would you like to encode or decode your file? " << endl;
    getline(cin, task);
    if (task == "encode" || task == "Encode" || task == "E" || task == "e"){
	    cout << "Please enter the name of an input file: " << endl;
    	    getline(cin, inputFileName);
	    h.makeTree(inputFileName);
    }else{
    	if (task == "decode" || task == "Decode" || task == "D" || task == "d"){
	    cout << "Please enter the name of a compressed input file (.hzip file): " << endl;
	    getline(cin, compressedFile);
	    cout << "Please enter the name of an encoded input file (.hcodes file): " << endl;
	    getline(cin, encodedFile);
            //produce a decompressed file
	}else{
		cout << "If you wish to encode your file, enter encode, or e." << endl;
		cout << "If you wish to decode your file, enter decode, or d." << endl;
		getline(cin, task);
	}
    }
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
    cout << h.encode(" ") << endl;
    cout << h.encode("aabbccddabcd") << endl;
    string test2 = "000001011010111100011011";
    char * test2A = new char[test2.size()+1];
    copy(test2.begin(), test2.end(), test2A);
    test2A[test2.size()] = '\0';
    
    cout << h.decode(test2A) << endl; 

    char * test3 = h.encode("abcabcabc");
    cout << test3 << endl;
    cout << h.decode(test3) << endl;


     //output encoded file should be named: filename.hzip
     //output compressed file: filename.hcodes
     // print the compression ratio (# of bits in compressed file /  total # in original file)

    return 0;
}
