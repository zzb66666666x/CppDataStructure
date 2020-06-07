#include<iostream>
#include"array2d.h"

using namespace std;

template<class T>
void try_makeArray(T** &x, int rows, int columns){
    x = new T*[rows];
    for(int i = 0; i<rows; i++){
        x[i] = new T[columns];
    }
}

template<class T>
void makeArray(T** &x, int rows, int columns){
    try{
        try_makeArray(x, rows, columns);
    }
    catch(bad_alloc &e){
        //catch by reference to avoid warning
        cerr<<"failed to allocate"<<endl;
        exit(1);
    }
}

template<class T>
void  deleteArray(T** &x, int rows){
    for(int i = 0; i<rows; i++){
        delete [] x[i];
    }
    delete [] x;
    x = NULL;
}

template<class T>
void init(T** &x, int rows, int columns){
    T value = 0;
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            x[i][j] = value;
        }
    }
}

template<class T>
void show(T** &x, int rows, int columns){
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            cout<<x[i][j]<<"  ";
        }
        cout<<endl;
    }
}