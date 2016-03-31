/*Lisa Carter
  Section 1*/

#include <cstddef>
#include "treenode.h"
#include <iostream>

#ifndef BST_H_
#define BST_H_

template <class T>
class BST{
    private:
        TreeNode<T>* root;
    public:
        BST();
        bool isEmpty();
        TreeNode<T> * getRoot();
        bool search(T item);
        void insertNode(T item);
        void deleteNode(T item);
        void inOrder(TreeNode<T> * ptr);
        void preOrder(TreeNode<T> * ptr);
        void postOrder(TreeNode<T> * ptr);

};

using namespace std;

template<class T>
BST<T>::BST(){
    root = NULL;
}

template<class T>
bool BST<T>::isEmpty(){
    if (root == NULL){
        return true;
    } else {
        return false;
    }
}

template<class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}

template<class T>
bool BST<T>::search(T item){
    TreeNode<T> * ptr = root;
    bool found = false;
    for(;;){
        if (found||ptr == NULL){
            break;
        }
        if (item < ptr->getData()){
            ptr = ptr->getLeft();
        } else if (item > ptr->getData()){
            ptr = ptr->getRight();
        } else if (item == ptr->getData()){
            found = true;
        } else {
            ptr = NULL;
        }
    }
    return found;
}

template<class T>
void BST<T>::insertNode(T item){
    TreeNode<T> * ptr = root;
    TreeNode<T> * parent = NULL;
    bool found = false;
    for(;;){
        //search and set parent
        if (found || ptr == NULL){
            break;
        }
        if (item < ptr->getData()){
            parent = ptr;
            ptr = ptr->getLeft();
        } else if (item > ptr->getData()){
            parent = ptr;
            ptr = ptr->getRight();
        } else if (item == ptr->getData()){
            found = true;
        } else {
            ptr = NULL;
        }
    }

    if (found){
        cout << "Item already in tree" << endl;
    } else {
        ptr = new TreeNode<T>(item);
        if (parent == NULL){
            root = ptr; //tree is empty
        } else {
            if (item < parent->getData())
                parent->setLeft(ptr);
            else
                parent->setRight(ptr);
        }
    }
}

template<class T>
void BST<T>::deleteNode(T item){
    TreeNode<T> * ptr = root;
    TreeNode<T> * parent = NULL;
    TreeNode<T> * temp = NULL;
    bool found = false;
    for(;;){
        //search and set parent
        if (found || ptr == NULL){
            break;
        }
        if (item < ptr->getData()){
            parent = ptr;
            ptr = ptr->getLeft();
        } else if (item > ptr->getData()){
            parent = ptr;
            ptr = ptr->getRight();
        } else if (item == ptr->getData()){
            found = true;
            temp = ptr;
        } else {
            ptr = NULL;
        }
    }  
    if (!found){
        cout << "Item to be deleted not found" << endl;
    } else {
        bool isLeft = false;
        if (parent->getLeft()==temp){
            isLeft = true;
        }
        if (temp->isLeaf()){
            if (isLeft){
                parent->setLeft(NULL);
            } else {
                parent->setRight(NULL);
            }
            delete temp;
        } else if (temp->getLeft() == NULL){
            if (isLeft){
                parent->setLeft(temp->getRight());
                delete temp;
            } else {
                parent->setRight(temp->getRight());
            }
        } else if (temp->getRight() == NULL){
            if (isLeft){
                parent->setLeft(temp->getLeft());
                delete temp;
            } else {
                parent->setRight(temp->getLeft());
            }
        } else {
            TreeNode<T> * successor = temp->getRight();
            TreeNode<T> * oneUp;
            ptr = successor->getLeft();
            while (ptr != NULL){
                ptr = successor->getLeft();
                if (ptr != NULL){
                    oneUp = successor;
                    successor = ptr;
                }
            }
            cout << "oneUp " << oneUp->getData() << endl; 

            if (successor->isLeaf()){
                if (isLeft){
                    parent->setLeft(successor);
                } else {
                    parent->setRight(successor);
                }
            } else {
                oneUp->setLeft(successor->getRight());
                if (isLeft){
                    parent->setLeft(successor);
                } else {
                    parent->setRight(successor);
                }

                successor->setLeft(temp->getLeft());
                successor->setRight(temp->getRight());
                
                delete temp;
            }

        }       
    }
}

template<class T>
void BST<T>::inOrder(TreeNode<T> * ptr){
    if (ptr != NULL){
        inOrder(ptr->getLeft());
        cout << ptr->getData() << endl;
        inOrder(ptr->getRight());
    }
} 

template<class T>
void BST<T>::preOrder(TreeNode<T> * ptr){
    if (ptr != NULL){
        cout << ptr->getData() << endl;
        preOrder(ptr->getLeft());
        preOrder(ptr->getRight());
    }
}

template<class T>
void BST<T>::postOrder(TreeNode<T> * ptr){
    if (ptr != NULL){
        postOrder(ptr->getLeft());
        postOrder(ptr->getRight());
        cout << ptr->getData() << endl;
    }
}

#endif
