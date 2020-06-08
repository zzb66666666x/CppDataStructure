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
    min_length = 5;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& old_list){
    arrayLength = old_list.arrayLength;
    listsize = old_list.listsize;
    min_length = old_list.min_length;
    items = new T[arrayLength];
    copy_elements(items, old_list.items, listsize);
}

//interface
//empty() and getsize() defined inline, omit them here
template<class T>
int arrayList<T>::locate(const T& element)const{
    for (int i=0; i<listsize; i++){
        if (items[i] == element){
            return i;
        }
    }
    cout<<"No such element"<<endl;
    return -1;  //nothing
}

template<class T>
T& arrayList<T>::getVal(int index) const{
    if (index_check(index) == false){
        throw "index error\n";
    }
    return items[index];
}

template<class T>
void arrayList<T>::remove(const T& element){
    //first find the index 
    int index = -1;
    for(int i = 0; i<listsize; i++){
        if (items[i] == element){
            index = i;
            break;
        }
    }
    if (index < 0){
        cout<<"no such element in the list\n";
    }
    else{
        remove_index(index);
    }
}

template<class T>
void arrayList<T>::remove_index(int index){
    if (index_check(index) == false){
        cout<<"index error"<<endl;
        return;
    }
    if (listsize <= arrayLength/4)
        deallocate();
    for (int i = index; i<listsize; i++){
        items[i] = items[i+1];
    }
    listsize --;
}

template<class T>
void arrayList<T>::insert(const T& element, int index){
    //don't use the index_check here for better functionality
    if (index<0){
        cout<<"index error"<<endl;
        return;
    }
    if (listsize>=arrayLength){
        allocate();
    }
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
    // for (int i = 0; i<listsize; i++){
    //     cout<<items[i]<<endl;
    // }
    // cout<<endl;
}

template<class T>
void arrayList<T>::output(ostream& out) const{
    if (listsize == 0){
        out<<"[]"<<endl;
        return;
    }
    out<<"[";
    int i;
    for (i = 0; i<listsize-1; i++){
        out<<items[i]<<", ";
    }
    out<<items[i]<<"]"<<endl;
}

template<class T>
void arrayList<T>::allocate(){
    //cout<<"allocate()"<<endl;
    int newlength = arrayLength*2;
    T* newitems = new T[newlength];
    copy_elements(newitems, items, listsize);
    arrayLength = newlength;
    //cout<<"new arraylength: "<<arrayLength<<endl;
    delete[] items;
    items = newitems;
} 

template<class T>
void arrayList<T>::deallocate(){
    int newlength = arrayLength/2;
    if (newlength<min_length){
        newlength = min_length;
    }
    T* newitems = new T[newlength];
    copy_elements(newitems, items, listsize);
    arrayLength = newlength;
    delete[] items;
    items = newitems;
} 

template<class T>
bool arrayList<T>::index_check(int index) const{
    if (index>=0 && index<listsize){
        return true;
    }
    else{
        return false;
    }
}

//friend
template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x){
    x.output(out);
    return out;
} 