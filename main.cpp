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
	char* line;
	string num;
	string val;
	while(!myInputFile.eof()){
		getline(cin, line);
     f (command.length() > 2){
254         for (int i = 0; i < command.length(); i++){
 255             if (isspace(command[i])){
256                 space = i;
257                 break;
258             } else {
    259                 space = -1;
    260             }
 261         }
   262         if (space == -1){
       263             cout << "Incorrect command format" << endl;

	
		Datawrapper* a = new Datawrapper();
		a->setCharac(value);
		a->setWeight(stod(num));
		TreeNode<Datawrapper*> * n = new TreeNode<Datawrapper*>();
		n->setData(*a);








		break;	
	}

	myInputFile.close();
	return 0;
}
