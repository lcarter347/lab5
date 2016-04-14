/*Justin Rice, Hannah Zontine, Lisa Carter*/
#include<fstream>
#include<sstream>
#include<string>
#include<ctype.h>
#include "my_da_array.h"
#include "treenode.h"
#include "datawrapper.h"
#include <string.h>

using namespace std;

class Huffman{
    private:
        TreeNode<Datawrapper*> * root;
        TreeNode<Datawrapper*> * current;
        my_da_array<string> key;
        my_da_array<string> value;
        int messageLength;

    public:
        Huffman();
        void makeTree(string);
        string decode(char * data);
        char * encode(string);
        void setMessageLength(int length);
        int getMessageLength();
        void writeTreeToFile(string filename, int length);
        void makeTreeFromFile(string filename);
};

Huffman::Huffman(){
    my_da_array<string> key;
    my_da_array<string> value;
}

void Huffman::makeTree(string fname){
    my_da_array<TreeNode <Datawrapper*> *> stash;
    my_da_array<TreeNode <Datawrapper*> *> keybuilder;
    string charVal, charNum, line;
    ifstream infile;
    if(!infile.is_open()){
        infile.open(fname.c_str());
    }
    getline(infile, line);
    while(!infile.eof()){
        charVal = line[0];
        int len = line.length() - 2;
        charNum = line.substr(2,len);
        Datawrapper* a = new Datawrapper();
        a->setCharac(charVal);

        stringstream is(charNum);
        int num = 0;
        is >> num;

        a->setWeight(num);
        TreeNode<Datawrapper*>* n = new TreeNode<Datawrapper*>();
        n->setData(a);
        stash.da_push(n);
        keybuilder.da_push(n);
        getline(infile,line);
    }
    
    while(stash.get_size() > 1){
        int smallest, secondsmallest;
        if (stash.get_elem(0)->getData()->getWeight() < stash.get_elem(1)->getData()->getWeight()){
            smallest = 0;
            secondsmallest = 1;
        }
        else{
            smallest = 1;
            secondsmallest = 0;
        }
        for (int count = 2; count < stash.get_size(); count ++){
            if (stash.get_elem(count)->getData()->getWeight() < stash.get_elem(smallest)->getData()->getWeight()){
                secondsmallest = smallest;
                smallest = count;
            }
            else if (stash.get_elem(count)->getData()->getWeight() < stash.get_elem(secondsmallest)->getData()->getWeight())
                secondsmallest = count;
        }
        
        TreeNode<Datawrapper*> * merged = stash.get_elem(secondsmallest)->merge(stash.get_elem(smallest));

        stash.da_remove(smallest);
        if (secondsmallest < smallest)
            stash.da_remove(secondsmallest);
        else
            stash.da_remove(secondsmallest -1);
        stash.da_push(merged);
    }
    root = stash.get_elem(0);
    current = root;
    
    for (int x = 0; x < keybuilder.get_size(); x ++){
        TreeNode<Datawrapper *> * node = keybuilder.get_elem(x);
        key.da_push(node->getData()->getCharac());
        value.da_push(node->getPath());
    }

}

string Huffman::decode(char * data){
    current = root;
    string answer = "";
    int size = strlen(data);
    for (int count = 0; count < size +1; count ++){
       if (data[count] == '1')
           current = current->getRight();
       else if (data[count] == '0')
           current = current->getLeft();
       if (current->isLeaf()){
           answer += current->getData()->getCharac();
           current = root;
        }
    }
    return answer;
}

char *  Huffman::encode(string input){
    string answer = "";
    for (int x = 0; x < input.length(); x ++){
        string thisLetter = input.substr(x,1);
        int keyIndex;
        for (int y = 0; y < key.get_size(); y++){
            if (key.get_elem(y) == thisLetter)
                keyIndex = y;
        }
        answer += value.get_elem(keyIndex);
    }

    char * finAnswer = new char[answer.size() +1];
    copy(answer.begin(), answer.end(), finAnswer);
    finAnswer[answer.size()] = '\0';
    return finAnswer;
}

void Huffman::writeTreeToFile(string filename, int length){
   ofstream outfile;
   cout << filename << endl;
   if(!outfile.is_open()){
	   outfile.open(filename.c_str());
   }
   if(outfile.is_open()){
       outfile << length << endl;
       for (int i = 0; i < key.get_size(); i++){
           outfile << key.get_elem(i) << " " << value.get_elem(i) << endl;
       }
       outfile.close();
   } else {
      cout << "Error writing to code key file" << endl;
   } 
}

void Huffman::makeTreeFromFile(string filename){
    Datawrapper * dw = new Datawrapper();
    TreeNode<Datawrapper *> * newRt = new TreeNode<Datawrapper *>();
    newRt->setData(dw);
    root = newRt;
    current = root;
    fstream infile;
    infile.open(filename.c_str());
    if (!infile.is_open()){
        cout << "Error opening code key file" << endl;
    } else {
        string line;
        getline(infile, line);
        if (!infile.eof()){
            stringstream ss(line);
            int length;
            if (!(ss >> length)){
                cout << "Code key file is corrupted" << endl;
            } else {
                setMessageLength(length);
                getline(infile, line);
                string charVal, path;
                while(!infile.eof()){
                    charVal = line[0];
                    int len = line.length() - 2;
                    path  = line.substr(2,len);
                    key.da_push(charVal);
                    value.da_push(path);                   
                    for (int count = 0; count < path.length(); count ++){
                        string thisChar = path.substr(count, 1);
                        if (thisChar == "1"){
                            if (current->hasRight()){
                                current = current->getRight();
                            }
                            else{
                                Datawrapper * newrightDW = new Datawrapper();
                                TreeNode<Datawrapper *> * newRight = new TreeNode<Datawrapper *>();
                                newRight->setData(newrightDW);
                                current->setRight(newRight);
                                newRight->setParent(current);
                                current = newRight;
                            }
                        }
                        else{
                            if (current->hasLeft()) {
                                current = current->getLeft();
                            }
                            else{
                                Datawrapper * newleftDW = new Datawrapper();
                                TreeNode<Datawrapper *> * newLeft = new TreeNode<Datawrapper *>();
                                newLeft->setData(newleftDW);
                                current->setLeft(newLeft);
                                newLeft->setParent(current);
                                current = newLeft;
                            }
                        }
                        if (count == path.length()-1){
                            current->getData()->setCharac(charVal);     
                            current = root;
                        }
                    }

                    getline(infile, line);
                }
            }
        }
    }
}

void Huffman::setMessageLength(int length){
    messageLength = length;
}

int Huffman::getMessageLength(){
    return messageLength;
}

