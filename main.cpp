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
	string space; 
//make array

	while(!myInputFile.eof()){
		getline(cin, line);
		if (line.length() > 2){
			for (int i = 0; i < line.length(); i++){
				if (isspace(line[i])){
					space.append(i);
					cat(i);
					break;
   				}
 			}
			if(space.length() == 1){
				for(int i = 0; i < space[0]; i++){
					charVal = charVal + line[i];
				}
				for(int i = space[0]; i < line.length(); i++){
					charNum = charNum + line[i];
				}
			}
		}
		Datawrapper* a = new Datawrapper();
		a->setCharac(charVal);
		a->setWeight(stod(charNum));
		TreeNode<Datawrapper*>* n = new TreeNode<Datawrapper*>();
		n->setData(*a);
		
		TreeNode<Datawrapper*>* ptrArray = new TreeNode<Datawrapper*>()[];
		


//dynamic array of node pointers



		break;	
	}

	myInputFile.close();
	return 0;
}
