#include<iostream>
#include<exception>

using namespace std;

/* methods of arrayList
 * --constructors & destructors(already defined)
 * --interfaces
 * --private methods
 * */

//helper functions
template<class T>
void copy_elements(T* new_list, T* old_list, int size){
    for (int i=0; i<size; i++){
        new_list[i] = old_list[i];
    }
}

//constructors & destructors
//defined inline for the destructor: omit it here
template<class T>
arrayList<T>::arrayList(int length){
    if (length < 1){
        throw "invalid array size\n";
    }
    arrayLength = length;
    items = new T[length];
    listsize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& old_list){
    arrayLength = old_list.arrayLength;
    listsize = old_list.size;
    items = new T[arrayLength];
    copy_elements(items, old_list.items, listsize);
}

//interface
//empty() and getsize() defined inline, omit them here
template<class T>
int arrayList<T>::locate(const T& element)const{
    for (int i=0; i<listsize; i++){
        if (items[i] == element){
            return i
        }
    }
    cout<<"No such element"<<endl;
    return -1;  //nothing
}

template<class T>
T& arrayList<T>::getVal(int index) const{
    index_check(index);
    return items[index];
}

template<class T>
void arrayList<T>::remove(const T& element){

}

template<class T>
void arrayList<T>::remove_index(int index){

}

template<class T>
void arrayList<T>::insert(const T& element, int index){
    if (listsize>=arrayLength)
        allocate();
    if (index < listsize){
        //move things
        for (int i = listsize; i>index; i--){
            items[i] = items[i-1];
        }  
        listsize++;
        items[index] = element;
    }
    else{
        append(element);
    }
}

template<class T>
void arrayList<T>::append(const T& element){
    if (listsize>=arrayLength)
        allocate();
    items[listsize] = element;
    listsize++;
}

template<class T>
void arrayList<T>::output() const{

}

template<class T>
bool arrayList<T>::allocate(){

} 

template<class T>
bool arrayList<T>::deallocate(){
    
} 

template<class T>
void arrayList<T>::index_check(int index) const{

}