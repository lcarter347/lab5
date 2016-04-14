/*Lisa Carter
  Section 1*/

#include <iostream>

#ifndef MY_DA_ARRAY_H_
#define MY_DA_ARRAY_H_

template <class T>
class my_da_array{
    public:
        my_da_array();
        my_da_array(T);
        ~my_da_array();
        void print();
        int da_push(T);
        T da_pop();
        int set_elem(int index, T elem);
        int da_insert(int, T);
        int da_remove(int index);
        T get_elem(int);
        int get_size();
        T find_maxmin(bool);
        int is_elem(T);
    private:
        T *ptr;
        int size;
};

using namespace std;

template<class T>
my_da_array<T>::my_da_array(){
    ptr = new T[1];
    size = 0;
}

template<class T>
my_da_array<T>::my_da_array(T num){
    ptr = new T[1];
    ptr[0] = num;
    size = 1;
}

template<class T>
my_da_array<T>::~my_da_array(){
    delete [] ptr;
}

template<class T>    	
void my_da_array<T>::print(){
    for (int i = 0; i < size; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
}

template<class T>    	
int my_da_array<T>::da_push(T num){
    try{
        int newsize = size + 1;
        T *temp = new T[newsize];
        
        for(int i = 0; i < size; i++){
            temp[i] = ptr[i];
        }
        
        temp[size] = num;
        size = newsize;
        delete [] ptr;
        ptr = temp;    
    
        return 0;
    } catch (bad_alloc& ba){
        return -1;
    }
}

template<class T>    	
T my_da_array<T>::da_pop(){
    T elem;
    if (size == 1){
        elem = ptr[0];
        ptr[0] = 0;
    } else {
        int newsize = size - 1;
        elem = ptr[newsize];
        T * temp = new T[newsize];

        for (int i = 0; i < newsize; i++){
            temp[i] = ptr[i];
        }
        size = newsize;
        delete [] ptr;
        ptr = temp;
    }

    return elem;
} 

template<class T>    	
int my_da_array<T>::set_elem(int index, T elem){
    if (index >= size){
        return -1;
    } else {
        ptr[index] = elem;
        return 0;
    }
}

template<class T>    	
int my_da_array<T>::da_insert(int pos, T elem){
    if (pos >= size){
        return -1;
    } else{
        try{
            int newsize = size + 1;
            int count = 0;
            T * temp = new T[newsize];
            for (int i = 0; i < newsize; i++){
                if (i == pos){
                    temp[i] = elem;
                } else {
                    temp[i] = ptr[count];
                    count ++;
                }
            }
            size = newsize;
            delete [] ptr;
            ptr = temp;
            return 0;
        } catch(bad_alloc& ba){
            return -1;
        } 
    }
}

template<class T>    	
int my_da_array<T>::da_remove(int index){
    if (index >= size){
        return -1;
    } else{
        try{
            int newsize = size - 1;
            T * temp = new T[newsize];
            int count = 0;
            for (int i = 0; i < size; i++){
                if (i == index){
                    ;
                } else {
                    temp[count] = ptr[i];
                    count ++;
                }
            }
            size = newsize;
            delete [] ptr;
            ptr = temp;
            return 0;
        } catch(bad_alloc& ba){
            return -1;
        } 
    }
}

template<class T>    	
T my_da_array<T>::get_elem(int elem){
    if (size > elem){
        return ptr[elem];
    } else { 
        return 0;
    }
}

template<class T>    	
int my_da_array<T>::get_size(){
    return size;
}


template<class T>    	
T my_da_array<T>::find_maxmin(bool max){
    int index = 0;
    T maxmin = ptr[index];
    if (max){
        //search for max
        maxmin = ptr[index];
        for (int i = 0; i < size; i++){
            if (ptr[i] > maxmin){
                index = i;
                maxmin = ptr[i];
            }
        }
    } else {
        //search for min
        maxmin = ptr[index];
        for (int i = 0; i < size; i++){
            if (ptr[i] < maxmin){
                index = i;
                maxmin = ptr[i];
            }
        }
    }
    return maxmin;
}

template<class T>    	
int my_da_array<T>::is_elem(T elem){
    for (int i = 0; i < size; i++){
        if (ptr[i] == elem){
            return i;
        }
    }
    return -1;
}


#endif
