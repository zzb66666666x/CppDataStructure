#include<iostream>
#include"functions.h"

using namespace std;

int main(){
    float a = 1.5;
    cout<<"the value for a is: "<<a<<endl;
    a = type_transfer<int, float>(a);
    cout<<"the value for a is: "<<a<<endl;

    return 0;
}