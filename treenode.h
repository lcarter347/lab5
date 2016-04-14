/*Lisa Carter
 Section 1*/

#include <cstddef>
#include <string>
#include "datawrapper.h"

#ifndef TREENODE_H_
#define TREENODE_H_

template <class T>
class TreeNode{
    private:
        T data;
        TreeNode * left;
        TreeNode * right;
        TreeNode * parent;
        string path;
    public:
        TreeNode();
        TreeNode(T val, TreeNode *ln=NULL, TreeNode *rn=NULL);
        T getData();
        TreeNode* merge(TreeNode* b);
        void setData(T val);
        void setLeft(TreeNode *ln);
        void setRight(TreeNode *rn);
        void setParent(TreeNode *pn);
        TreeNode* getLeft();
        TreeNode* getRight();
        TreeNode* getParent();
        bool isLeaf();
        void setPath(string);
        string getPath();
        bool hasLeft();
        bool hasRight();
        
};

template <class T>
TreeNode<T>::TreeNode(){
    left = right = NULL;
    path = "";
    parent = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode *ln, TreeNode *rn){
    data = val;
    left = ln;
    right = rn;
    path = "";
    ln->setPath("0");
    rn->setPath("1");
    parent = NULL;
}

template <class T>
T TreeNode<T>::getData(){
    return data;
}

template <class T>
void TreeNode<T>::setData(T val){
    data = val;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode *ln){
    left = ln;
    ln->setPath("0");
}

template <class T>
void TreeNode<T>::setRight(TreeNode *rn){
    right = rn;
    rn->setPath("1");
}

template <class T>
void TreeNode<T>::setParent(TreeNode *pn){
    parent = pn;
}

template <class T>
void TreeNode<T>::setPath(string pa){
    if (parent != NULL)
        path = parent->getPath() + pa;
    if (left){
        left->setPath("0");
    }
    if (right){
        right->setPath("1");
    }
}

template <class T>
string TreeNode<T>::getPath(){
    return path;
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
TreeNode<T>* TreeNode<T>::getParent(){
    return parent;
}

template <class T>
bool TreeNode<T>::isLeaf(){
    return((left == NULL) && (right == NULL));
}

template <class T>
   TreeNode<T>* TreeNode<T>::merge(TreeNode<T>* b){
    T val1 = getData();
    T val2 = b->getData();
    TreeNode<T> * parent = new TreeNode<T>();
    setParent(parent);
    b->setParent(parent);
    if (val2->getWeight() < val1->getWeight()){
        parent->setLeft(b);
        parent->setRight(this);
        setPath("1");
        b->setPath("0");
    } else {
        parent->setLeft(this);
        parent->setRight(b);
        setPath("0");
        b->setPath("1");
    }
    Datawrapper * parentWrap = new Datawrapper();
    parentWrap->setWeight(*val1 + *val2);
    parent->setData(parentWrap);
    return parent;
}

template <class T>
bool TreeNode<T>::hasLeft(){
    if (left == NULL) return false;
    return true;
}

template <class T>
bool TreeNode<T>::hasRight(){
    if (right == NULL) return false;
    return true;
}

#endif
