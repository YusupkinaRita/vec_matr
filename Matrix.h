#include <iostream>
#include "Vector.h"


template <class T>


class Matrix:public Vector<Vector<T>>{
public:
   Matrix(size_t n):Vector<Vector<T>>(n){
        for(size_t i=0;i<n;i++){
            this->_array[i]=Vector<T>(n, i);
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
        Matrix res=Matrix(this->_size);
        for (size_t i=0;i<this->_size;i++){//строчки
            for (size_t j=i;j<this->_size;j++){//столбцы
                for (size_t z=0;z<j+1;z++){
                    res[i][j]+=this->_array[i][z]*mt[z][j-this->_start_index];

                }
                
            }
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i=0; i<matr._size;i++){
            os<<matr._array[i]<<std::endl;
        }
        return os;
    }
    



    //ввод и вывод надо



};