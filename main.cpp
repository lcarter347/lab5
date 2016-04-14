// Justin Rice, Lisa Carter, Hannah Zontine
// Lab 5
// Sources: Stack Overflow, cplusplus.com, our brains, prayers

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
   while(true){
    cout << "Would you like to encode or decode your file? (to quit: q or quit)" << endl;
    getline(cin, task);
    if (task == "quit" || task == "q"){
	break; 
    }
    while(true){
	    if (task == "encode" || task == "Encode" || task == "E" || task == "e"){
		    cout << "Please enter the name of an input file: " << endl;
		    getline(cin, inputFileName);
		    string outputFileName = inputFileName + ".hzip";
		    fileAsString = compute(inputFileName);
		    if(fileAsString == ""){
			cout << "File not found." << endl;
			break;
		    }
		    calcweights(inputFileName);
		    string weightsFile = inputFileName + ".w";
		    h->makeTree(weightsFile);
		    char* answer = h->encode(fileAsString);
		    h->setMessageLength(strlen(answer));
		    writeBin(answer, outputFileName);
		    string str = inputFileName + ".hcodes";
		    h->writeTreeToFile(str, h->getMessageLength());
		    int length = h->getMessageLength();
		    double fileSize = fileAsString.length() * 8.0;
		    cout << "The compression ratio is: " << length/fileSize << endl;
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
			    ofstream output;
			    string oldFile = compressedFile;
			    string zipped = ".hzip";
			    int num = compressedFile.find(zipped);
			    oldFile = oldFile.erase(num,zipped.length());
			    if(!output.is_open()){
				output.open(oldFile.c_str());
			    }
		   	    if(!output.is_open()){
				cout << "Error: file is not opened!!" << endl;
			    }else{
				output << g;
			 	output.close();
			    }
		    }else{
			if(compressedFile.find(".hzip") == -1){
				cout << "The compressed file you entered could not be found (.hzip file)" << endl;
			}
			if(encodedFile.find(".hcodes") == -1){
				cout << "The encoded file you entered could not be found (.hcodes file)" << endl;
			}
		    }
		    break;
		}else{
			cout << "If you wish to encode your file, enter encode, or e." << endl;
			cout << "If you wish to decode your file, enter decode, or d." << endl;
			getline(cin, task);
		}
	    }
    }
   }
    return 0;
}


string compute(string inputFile){
	ifstream file;
	string line, str = "";
	if(!file.is_open()){
		file.open(inputFile.c_str());
	}
	if(file.is_open()){
		getline(file,line);
		while(!file.eof()){
			str = str + line;
			getline(file,line);
		}
	}
	file.close();
	return str;
}
