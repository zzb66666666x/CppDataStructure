// the testing file of using template class 
#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H
#include<iostream>
using namespace std;

template <class T>
class myComplex{
    public:
        myComplex():real(T(0)), imag(T(0)){}
        myComplex(T val):real(T(val)), imag(T(0)){}
        myComplex(T val, T val2):real(T(val)), imag(T(val2)){}

        double length();

        myComplex<T> operator+(const myComplex<T>& second);

        void show();
    private:
        T real;
        T imag;
};

template <class T> 
class myPair {
    T value1, value2;
public:
    myPair (T first, T second) {
        value1=first;
        value2=second;
    }
    T getmax ();
};

#include"template_class.cpp"

#endif