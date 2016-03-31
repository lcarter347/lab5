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
	char* value;
	string num;
	while(!myInputFile.eof()){
		cin.get(value);	
		Datawrapper* a = new Datawrapper();
		a->setCharac(value);
		cin.get();
		cin.get(num);
		a->setWeight(stod(num));
		TreeNode<Datawrapper*> * n = new TreeNode<Datawrapper*>();
		n->setData(*a);








		break;	
	}

	myInputFile.close();
	return 0;
}
