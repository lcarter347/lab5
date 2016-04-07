
#include <string>
#include <iostream>

#ifndef DATAWRAPPER_H_
#define DATAWRAPPER_H_

using namespace std;

class Datawrapper{
    private:
        int weight;
        string charac;
    public:
        Datawrapper();
        int getWeight();
        string getCharac();
        void setWeight(int);
        void setCharac(string);

        bool operator< (const Datawrapper &dw2);
        bool operator> (const Datawrapper &dw2);
        int operator+ (const Datawrapper &dw2);
        
};


bool Datawrapper::operator< (const Datawrapper &dw2){
    return weight < dw2.weight;
}

bool Datawrapper::operator> (const Datawrapper &dw2){
    return weight > dw2.weight;
}

int Datawrapper::operator+ (const Datawrapper &dw2){
    return weight + dw2.weight;
}

Datawrapper::Datawrapper(){
        double weight;
        string charac;
}

int Datawrapper::getWeight(){
    return weight;
}

string Datawrapper::getCharac(){
    return charac;
}

void Datawrapper::setWeight(int w){
    weight = w;
}

void Datawrapper::setCharac(string c){
    charac = c;
}



#endif
