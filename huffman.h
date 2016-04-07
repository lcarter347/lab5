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

    public:
        Huffman();
        void makeTree(string);
        string decode(char * data);
        char * encode(string);
};

Huffman::Huffman(){

}

void Huffman::makeTree(string fname){
    my_da_array<TreeNode <Datawrapper*> *> stash;
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
        getline(infile,line);
    }
    
    while(stash.get_size() > 1){
        int smallest, secondsmallest;
        cout << " Weight at 0: " << stash.get_elem(0)->getData()->getWeight() << endl;
        cout << " Charac at 0: " << stash.get_elem(0)->getData()->getCharac() << endl;
        cout << " Weight at 1: " << stash.get_elem(1)->getData()->getWeight() << endl;
        cout << " Charac at 1: " << stash.get_elem(1)->getData()->getCharac() << endl;
        if (stash.get_elem(0)->getData()->getWeight() < stash.get_elem(1)->getData()->getWeight()){
            cout << "In first swap." << endl;
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



        cout << " merged left weight: " << merged->getLeft()->getData()->getWeight() << " merged left charac: " << merged->getLeft()->getData()->getCharac() << endl;

        cout << " merged right weight: " << merged->getRight()->getData()->getWeight() << " merged right charac: " << merged->getRight()->getData()->getCharac() << endl;



        stash.da_remove(smallest);
        if (secondsmallest < smallest)
            stash.da_remove(secondsmallest);
        else
            stash.da_remove(secondsmallest -1);
        stash.da_push(merged);
    }
    root = stash.get_elem(0);
    current = root;

}

string Huffman::decode(char * data){
    string answer = "";
    int size = strlen(data);
    for (int count = 0; count < size +1; count ++){
       cout << "Current weight: " << current->getData()->getWeight() << endl;
       cout << "Next instruction: " << data[count] << endl;
       if (current->isLeaf()){
           cout << "Added letter." << endl;
           answer += current->getData()->getCharac();
           count --;
           current = root;
       }
       else if (data[count] == '1'){
           cout << "Moved right." << endl;
           current = current->getRight();
       }
       else{
           cout << "Moved left." << endl;
           current = current->getLeft();
       }
    }
    return answer;
}

char * Huffman::encode(string input){
    /*my_da_array<string> enc;*/

}
