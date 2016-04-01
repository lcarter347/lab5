#include "treenode.h"
#include "datawrapper.h"
#include "my_da_array.h"
#include <iostream>


using namespace std;

int main(){
    Datawrapper * a1 = new Datawrapper();
    TreeNode<Datawrapper *> * n1 = new TreeNode<Datawrapper *>();
    a1->setCharac("a");
    a1->setWeight(.45);
    n1->setData(a1);
    cout << n1->getData()->getWeight() << endl;
    cout << n1->getData()->getCharac() << endl;
    Datawrapper * a2 = new Datawrapper();
    TreeNode<Datawrapper *> * n2 = new TreeNode<Datawrapper *>();
    a2->setCharac("b");
    a2->setWeight(.1);

    cout << (*a1 < *a2) << endl;
    if (*a1 > *a2)
        cout << "Greater than worked." << endl;
    else
        cout << "Greater than didn't work." << endl;
    if (*a2 < *a1)
        cout << "Less than worked." << endl;
    else
        cout << "Less than didn't work." << endl;

    n2->setData(a2);
    cout << n2->getData()->getWeight() << endl;
    cout << n2->getData()->getCharac() << endl;
    my_da_array<TreeNode <Datawrapper *> *> * myarray = new my_da_array<TreeNode <Datawrapper *> *>(); 
    myarray->da_push(n1);
    myarray->da_push(n2);
    cout << "Length: " << myarray->get_size() << endl;
    
    TreeNode<Datawrapper *> * popPrac = myarray->da_pop();
    cout << popPrac->getData()->getWeight() << endl;
    cout << popPrac->getData()->getCharac() << endl;
    cout << "Length: " << myarray->get_size() << endl;

}
