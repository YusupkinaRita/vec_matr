#pragma once
#include <iostream>
template <class T>

class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _start_index;//перывй индекс с которого начинается вектор
public:
    
    Vector(size_t size=10){
        _size=size;
        _start_index=0;
        _array=new T[_size];
    }
    Vector(size_t size, size_t start){
        if(size<=0)
        throw "error";
        _size=size;
        _start_index=start;
        _array=new T[_size];
        for(size_t i=0; i<size;i++){
            _array[i]=0;
        }
    
    }//выделение памяти, проверка на старт индекс не больше размера, размер не нулевой
    Vector(const Vector& tmp){
        _size=tmp._size;
        _array=new T[_size];
        _start_index=tmp._start_index;
        for(size_t i=0;i<_size;i++){
            _array[i]=tmp._array[i];
        }
    }//тут чета надо с типами Т, но я пока не знаю что
    Vector(Vector&& moved){
        _size=moved._size;
        _start_index=moved._start_index;
        _array=moved._array;
        moved._array=nullptr;
        moved._size=0;
        moved._start_index=0;

    }//конструктор перемещения надо сделать
    ~Vector(){
        delete[] _array;
        _array=nullptr;
    }
    size_t GetSize()const{
        return _size;
    }
    size_t GetStartIndex()const{
        return _start_index;

    }

    T& At(size_t pos){
        if(pos>=_size)
        throw"out of range";
        return _array[pos];
    }
    
    T& operator[](size_t position)const{
        return _array[position];
    }
    Vector& operator=(const Vector& tmp){
        if(_size!=tmp._size){
        delete [] _array;
        _array=new T [tmp._size];
        }
        _size=tmp._size;
        _start_index=tmp._start_index;
        for(size_t i=0;i<_size;i++){
            _array[i]=tmp._array[i];
        }
        return *this;

    }
    Vector operator+(const T& tmp){
    }
    Vector operator-(const T& tmp){
        
    }
    Vector operator*(const T& tmp){
        Vector x=Vector(*this);
        for(size_t i=0;i<_size;i++){
            x._array[i]*=tmp;
        }
        return x;
    }
    Vector operator+(const Vector& tmp){
        if(sizeof(_array[0])!=sizeof(tmp._array[0])||_size!=tmp._size)
            throw "invalid operation";
        Vector x=Vector(*this);
        for(size_t i=0;i<_size;i++){
            x._array[i]+=tmp._array[i];
        }
        return x;
    }
    Vector operator-(const Vector& tmp){
        if(sizeof(_array[0])!=sizeof(tmp._array[0])||_size!=tmp._size)
            throw "invalid operation";
        Vector x=Vector(*this);
        for(size_t i=0;i<_size;i++){
            x._array[i]-=tmp._array[i];
        }
        return x;
    }
    T operator* (const Vector& tmp){
        if(sizeof(_array[0])!=sizeof(tmp._array[0])||_size!=tmp._size)
            throw "invalid operation";
        T res=0;
        for(size_t i=_start_index;i<_size;i++){
            res+=_array[i]*tmp._array[i];
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vect){
        os<<"(";
        for(int i=0; i<vect._size+vect.GetStartIndex();i++){
            if(vect._start_index>i)
            os<<0<<", ";
            else{
            os<<vect._array[i-vect._start_index];
            if(i+1!=vect._size+vect.GetStartIndex())
                os<<", ";
            }
        }
        os<<")";
        return os;
    }

     friend std::istream& operator>>(std::istream& istr, Vector& vec){
        T current;
        for (size_t i=0; i<vec._size; i++){
            std::cout<<"elem n"<<i+vec._start_index<<": ";
            istr>>current;
            vec._array[i]=current;

        }
        return istr;
    }
    
};
