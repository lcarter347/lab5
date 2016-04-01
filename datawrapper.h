
#include <string>
#include <iostream>

#ifndef DATAWRAPPER_H_
#define DATAWRAPPER_H_

using namespace std;

class Datawrapper{
    private:
        double weight;
        string charac;
    public:
        Datawrapper();
        double getWeight();
        string getCharac();
        void setWeight(double);
        void setCharac(string);
        bool operator< (const Datawrapper dw2);
        bool operator> (const Datawrapper dw2);
/*
        friend bool operator<(const Datawrapper &dw2) const;
        friend bool operator>(const Datawrapper &dw2) const;*/
};


bool Datawrapper::operator< (const Datawrapper dw2){
    cout << "Made it into less than." << endl;
    return weight < dw2.weight;
}

bool Datawrapper::operator> (const Datawrapper dw2){
    cout << "Made it into greater than." << endl;
    return weight > dw2.weight;
}
/*

bool Datawrapper::operator<(const Datawrapper &dw2) const{
    return weight<dw2.weight;
}

bool Datawrapper::operator>(const Datawrapper &dw2) const{
    return weight>dw2.weight;
}
*/

Datawrapper::Datawrapper(){
        double weight;
        string charac;
}

double Datawrapper::getWeight(){
    return weight;
}

string Datawrapper::getCharac(){
    return charac;
}

void Datawrapper::setWeight(double w){
    weight = w;
}

void Datawrapper::setCharac(string c){
    charac = c;
}



#endif
