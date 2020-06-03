#include<iostream>
#include"functions.cpp"
#include"template_class.h"

using namespace std;

int main(){
    // the test of writing template functions
    float a = 1.5;
    cout<<"the value for a is: "<<a<<endl;
    a = type_transfer<int, float>(a);
    cout<<"the value for a is: "<<a<<endl;

    //the test of template class
    //mypair
    myPair<int> myobject(100, 75);
    cout << myobject.getmax()<<endl;

    //myComplex
    myComplex<float> value1(1.69, 2.59);
    myComplex<float> value2(3.3, 4.4);
    myComplex<float> value3 = value1 + value2;
    value3.show();
    return 0;
}
