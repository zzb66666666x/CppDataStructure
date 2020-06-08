#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>

using namespace std;

template<class T>
class arrayList{
    //constructors and destructors
    public:
        arrayList(int length = 10);
        arrayList(const arrayList<T>&);
        ~arrayList(){delete[] items;}

    //Interface
        int locate(const T& element) const;
        T& getVal(int index) const;
        void remove(const T& element);
        void remove_index(int index);
        void insert(const T& element, int index);
        void append(const T& element);
        void output(ostream& out) const;
        //inline func
        bool empty() const {return listsize == 0;}
        int getsize() const {return listsize;}
        int capacity() const {return arrayLength;};

    private:
    //private methods
        void allocate();
        void deallocate();
        bool index_check(int index) const;

    //data
        int arrayLength;
        int listsize;
        int min_length;
        T* items;
};

#include"arrayList.cpp"
#endif 