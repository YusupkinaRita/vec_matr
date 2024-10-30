#include <iostream>
#include "Vector.h"


template <class T>


class Matrix:public Vector<Vector<T>>{
    Matrix(size_t n):Vector<Vector<T>>(n){
        for(size_t i=0;i<n;i++){
            _array[i]=Vector(n-i, i);
        }
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt){
    }
    Matrix (const Vector<Vector<T>>& mt):Vector<Vector<T>>(mt){}
    Matrix& operator=(const Matrix& mt);
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt);
    



    //ввод и вывод надо



};