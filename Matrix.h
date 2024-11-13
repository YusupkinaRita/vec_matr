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
    Matrix operator*(const Matrix& mt){
        Matrix res=Matrix(_size);
        for (size_t i=0;i<_size;i++){//строчки
            for (size_t j=i;j<_size;j++){//столбцы
                for (size_t z=0;z<j+1;z++){
                    res[i][j]+=_array[i][z]+mt[z][j-_start_index];

                }
                
            }
        }
        
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i=0; i<matr._size;i++){
            os<<matr._array[i]<<std::endl;
        }
        return os;
    }
    



    //ввод и вывод надо



};