#ifndef ARRAY2D_H
#define ARRAY2D_H

template<typename T>
void try_makeArray(T** &x, int rows, int columns);

template<class T>
void makeArray(T** &x, int rows, int columns);

template<typename T>
void deleteArray(T** &x, int rows);

template<class T>
void init(T** &x, int rows, int columns);

template<class T>
void show(T** &x, int rows, int columns);

#endif
