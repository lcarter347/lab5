
#include <string>

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
};

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
