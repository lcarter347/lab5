// Justin Rice, Lisa Carter, Hannah Zontine
// Lab 5
// Sources:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string inputFileName;
	cout << "Please enter the name of an input file: " << endl;
	getline(cin, inputFileName);
	ifstream myInputFile;
	if(!myInputFile.is_open()){
		myInputFile.open(inputFileName.c_str());
	}
	while(













	myInputFile.close();
	return 0;
}
