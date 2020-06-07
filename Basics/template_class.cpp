#include<math.h>
#include<iostream>
#include"template_class.h"

using namespace std;

// class myComplex
template<class T>
double myComplex<T>::length(){
    return sqrt(pow(real, 2)+pow(imag, 2));
}

template<class T>
myComplex<T> myComplex<T>::operator+(const myComplex<T>& second){
    myComplex<T> ans = myComplex<T>();
    T ans_imag, ans_real;
    ans_real = real + second.real;
    ans_imag = imag + second.imag;
    printf("the value of this real is: %f\n", this->real);
    printf("the value of this imag is: %f\n", this->imag);
    printf("the value of second real is: %f\n", second.real);
    printf("the value of second imag is: %f\n", second.imag);
    ans.imag = ans_imag;
    ans.real = ans_real;
    return ans;
}

template<class T>
void myComplex<T>::show(){
    cout<<real<<endl;
    cout<<imag<<endl;
    cout<<"("<<real<<", "<<imag<<"i )"<<endl;
}

//class myPair
template <class T>
T myPair<T>::getmax(){ // Please use Pair<T>, not Pair here.
    T retval;
    retval = value1>value2? value1 : value2;
    return retval;
}