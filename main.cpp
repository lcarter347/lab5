// Justin Rice, Lisa Carter, Hannah Zontine
// Lab 5
// Sources:

#include <iostream>
#include <fstream>
#include <string>
#include "treenode.h"
#include "datawrapper.h"

using namespace std;

int main(){
	string inputFileName;
	cout << "Please enter the name of an input file: " << endl;
	getline(cin, inputFileName);
	ifstream myInputFile;
	if(!myInputFile.is_open()){
		myInputFile.open(inputFileName.c_str());
	}
	string line, charNum, charVal;
	int space;
	//make array
	while(!myInputFile.eof()){
		getline(cin, line);
		if (line.length() > 2){
			for (int i = 0; i < line.length(); i++){
				if (isspace(line[i])){
					space = i;
					break;
   				}
 			}
			for(int i = 0; i < space; i++){
				charVal = charVal + line[i];
			}
			for(int i = space; i < line.length; i++){
		
			}
		}		


		Datawrapper* a = new Datawrapper();
		a->setCharac(value);
		a->setWeight(stod(num));
		TreeNode<Datawrapper*> * n = new TreeNode<Datawrapper*>();
		n->setData(*a);




//dynamic array of node pointers



		break;	
	}

	myInputFile.close();
	return 0;
}
