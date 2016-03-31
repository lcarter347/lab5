/*Lisa Carter
 Section 1*/

#include <cstddef>

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

#endif
