#include "my_da_array.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <ctype.h>
#include <string>

#ifndef CALCWEIGHTS_H_
#define CALCWEIGHTS_H_

int calcweights(string filename){
    ifstream infile;
    infile.open(filename.c_str());
    string str;
    my_da_array<char> characters;
    my_da_array<int> count;    

    if (!infile.is_open()){
        cout << "Unable to open file" << endl;
        return -1;
    } else {
        getline(infile, str);
        char c;
        bool inarray;
        int worked;
        while(!infile.eof()){
            for (int i = 0; i < str.length(); i++){
                inarray = false;
                for (int j = 0; j < characters.get_size(); j++){
                    c = characters.get_elem(j);
                    if (c == str[i]){
                        inarray = true;
                        count.set_elem(j, (count.get_elem(j)+ 1));
                        break;
                    }
                } 
                if (!inarray){
                    worked = characters.da_push(str[i]);
                    if (worked == 0){
                        worked = count.da_push(1);
                        if (worked == -1){
                            cout << "Error adding to count array" << endl;
                            return -1;
                        }
                   } else {
                       cout << "Error adding to character array" << endl;
                       return -1;
                   }
                }
            }

            getline(infile, str);        
        }
        
        ofstream outfile;
        outfile.open("testweights.txt");
        if (!outfile.is_open()){
            cout << "Unable to open output file" << endl;
            return -1;
        } else {
            for (int k = 0; k < characters.get_size(); k++){
                outfile << characters.get_elem(k) << " " << count.get_elem(k) << endl;
            }
            outfile.close();
        }
    }

}
#endif
