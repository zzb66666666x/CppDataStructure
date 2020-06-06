#ifndef ARRAYLIST_H
#define ARRAYLIST_H

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
        void output() const;
        //inline func
        bool empty() const {return listsize == 0;}
        int getsize() const {return listsize;}
        int capacity() const {return arrayLength;};
    
    private:
    //private methods
        bool allocate();
        bool deallocate();
        void index_check(int index) const;

    //data
        int arrayLength;
        int listsize;
        T* items;
};

#include"arrayList.cpp"
#endif 