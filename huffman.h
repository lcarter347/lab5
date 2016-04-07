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
        void makeTree(ifstream *);
        string decode(char * data);
        char * encode(string);
};

Huffman::Huffman(){

}

void Huffman::makeTree(ifstream * in){
    my_da_array<TreeNode <Datawrapper*> *> stash;
    string charVal, charNum, line;
    ifstream infile = *in;
    while(!infile.eof()){
        getline(cin, line);
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
    }
    
    while(stash.get_size() > 1){
        int smallest, secondsmallest;
        if (stash.get_elem(0)->getData() < stash.get_elem(1)->getData()){
            smallest = 0;
            secondsmallest = 1;
        }
        else{
            smallest = 1;
            secondsmallest = 0;
        }
        for (int count = 2; count < stash.get_size(); count ++){
            if (stash.get_elem(count)->getData() < stash.get_elem(smallest)->getData()){
                secondsmallest = smallest;
                smallest = count;
            }
            else if (stash.get_elem(count)->getData() < stash.get_elem(secondsmallest)->getData())
                secondsmallest = count;
        }
        
        TreeNode<Datawrapper*> * merged = stash.get_elem(smallest)->merge(stash.get_elem(secondsmallest));
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
    for (int count = 0; count < size; count ++){
       if (current->isLeaf()){
           answer += current->getData()->getCharac();
           current = root;
       }
       else if (data[count] == '1')
           current = current->getRight();
       else
           current = current->getLeft();
    }
    return answer;
}

char * Huffman::encode(string input){
    my_da_array<string> enc;

}
