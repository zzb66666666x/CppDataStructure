#include<iostream>
#include"arrayList.h"

using namespace std;

int main(){
    arrayList<int> mylist(20);
    //testing append
    for (int i = 0; i<30; i++){
        mylist.append(i);
    }
    cout<<mylist;
    cout<<"the capacity of the list is: "<<mylist.capacity()<<endl;
    //testing remove
    cout<<endl;
    for (int i = 0; i<29; i++){
        mylist.remove_index(0);
    }
    cout<<mylist;
    mylist.remove(29);
    cout<<mylist;
    cout<<"the capacity of the list is: "<<mylist.capacity()<<endl;
    //testing insert
    cout<<endl;
    for (int i = 0; i<25; i++){
        mylist.insert(i, 0);
    }
    cout<<mylist;
    cout<<"the capacity of the list is: "<<mylist.capacity()<<endl;
    //testing getVal
    cout<<endl;
    cout<<"testing the getVal(): getVal(index = 666) -> "<<endl;
    try{
        mylist.getVal(666);
    }
    catch(char const* info){
        cout<<info;
    }
    cout<<"testing the getVal(): getVal(index = 2) -> "<<mylist.getVal(2)<<endl;
    //testing locate
    cout<<endl;
    cout<<"search 16's index -> "<<mylist.locate(16)<<endl;
    return 0;
}