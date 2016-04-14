// Justin Rice, Lisa Carter, Hannah Zontine
// Lab 5
// Sources: Stack Overflow, cplusplus.com

#include <iostream>
#include <fstream>
#include <string>
#include "treenode.h"
#include "datawrapper.h"
#include "huffman.h"
#include "bin.h"
#include "calcweights.h"


using namespace std;

string compute(string inputFile);

int main(){
    string inputFileName;
    string compressedFile, encodedFile;
    string task, fileAsString;
    Huffman* h = new Huffman();
    cout << "Would you like to encode or decode your file? " << endl;
    getline(cin, task);
    while(true){
    if (task == "encode" || task == "Encode" || task == "E" || task == "e"){
	    cout << "Please enter the name of an input file: " << endl;
   	    getline(cin, inputFileName);
	    string outputFileName = inputFileName + ".hzip";
	    fileAsString = compute(inputFileName);
	    calcweights(inputFileName);
	    string weightsFile = inputFileName + ".w";
	    h->makeTree(weightsFile);
	    char* answer = h->encode(fileAsString);
	    h->setMessageLength(strlen(answer));
	    writeBin(answer, outputFileName);
	    string str = inputFileName + ".hcodes";
	    h->writeTreeToFile(str, h->getMessageLength());
	    break;
    }else{
    	if (task == "decode" || task == "Decode" || task == "D" || task == "d"){
	    cout << "Please enter the name of a compressed input file (.hzip file): " << endl;
	    getline(cin, compressedFile);
	    cout << "Please enter the name of an encoded input file (.hcodes file): " << endl;
	    getline(cin, encodedFile);
	    if(compressedFile.find(".hzip") != -1  && encodedFile.find(".hcodes") != -1){
		    h->makeTreeFromFile(encodedFile);
		    char* value = readBin(compressedFile, h->getMessageLength());
	            string g = h->decode(value);
		    cout << g << endl;
	    }
	    break;
	}else{
		cout << "If you wish to encode your file, enter encode, or e." << endl;
		cout << "If you wish to decode your file, enter decode, or d." << endl;
		getline(cin, task);
	}
    }
    }
    //output encoded file: filename.hzip
     //output compressed file: filename.hcodes
     //print the compression ratio (# of bits in compressed file /  total # in original file)

    return 0;
}


string compute(string inputFile){
	ifstream file;
	string line, str = "";
	if(!file.is_open()){
		file.open(inputFile.c_str());
	}
	getline(file,line);
	while(!file.eof()){
		str = str + line;
		getline(file,line);
	}
	file.close();
	return str;
}
