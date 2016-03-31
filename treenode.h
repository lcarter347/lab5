/*Lisa Carter
 Section 1*/

#include <cstddef>
#include "datawrapper.h"

#ifndef TREENODE_H_
#define TREENODE_H_

template <class T>
class TreeNode{
    private:
        T data;
        TreeNode * left;
        TreeNode * right;
    public:
        TreeNode();
        TreeNode(T val, TreeNode *ln=NULL, TreeNode *rn=NULL);
        T getData();
        TreeNode* merge(TreeNode* a, TreeNode* b);
        void setData(T val);
        void setLeft(TreeNode *ln);
        void setRight(TreeNode *rn);
        TreeNode* getLeft();
        TreeNode* getRight();
        bool isLeaf();
};

template <class T>
TreeNode<T>::TreeNode(){
    left = right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode *ln, TreeNode *rn){
    data = val;
    left = ln;
    right = rn;
}

template <>
TreeNode<Datawrapper *>::TreeNode(Datawrapper * val){
    data = val;
    left = right = NULL;
}

template <class T>
T TreeNode<T>::getData(){
    return data;
}

template <>
double TreeNode<Datawrapper>::getData(){
    return data.getWeight();
}

template <class T>
void TreeNode<T>::setData(T val){
    data = val;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode *ln){
    left = ln;
}

template <class T>
void TreeNode<T>::setRight(TreeNode *rn){
    right = rn;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft(){
    return left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight(){
    return right;
}

template <class T>
bool TreeNode<T>::isLeaf(){
    return((left == NULL) && (right == NULL));
}

template <class T>
   TreeNode<T>* TreeNode<T>::merge(TreeNode<T>* a, TreeNode<T>* b){
    T val1 = a->getData();
    T val2 = b->getData();
    TreeNode<T> parent();
    (if val2 < val1){
        parent.setLeft(b);
        parent.setRight(a);
    } else {
        parent.setLeft(a);
        parent.setRight(b);
    }
    parent.setData(val1 + val2);
}

template <>
TreeNode<Datawrapper *>* TreeNode<Datawrapper *>::merge(TreeNode<Datawrapper *>* a, TreeNode<Datawrapper *>* b){
    double val1 = a->getData();
    double val2 = b->getData();
    Datawrapper* d = new Datawrapper();
    d->setWeight(val1 + val2);
    TreeNode<Datawrapper *> parent(d);
    (if val2 < val1){
        parent.setLeft(b);
        parent.setRight(a);
    } else {
        parent.setLeft(a);
        parent.setRight(b);
    }
    parent.setData(val1 + val2);
}

#endif
