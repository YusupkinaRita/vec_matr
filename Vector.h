#include <iostream>
template <class T>

class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _start_index//перывй индекс с которого начинается вектор
public:
    Vector(size_t size, size_t start);//выделение памяти, проверка на старт индекс не больше размера, размер не нулевой
    Vector(const Vector& tmp);
    Vector(Vector&& moved);//конструктор перемещения надо сделать
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

    T& At(size_t pos);//не должно быть выхода за границу
    T& operator[](size_t position);
    Vector& operator=(const Vector& tmp);//нужно понять когда вызывается перемещение а когда это
    Vector operator+(const T& tmp);
    Vector operator-(const T& tmp);
    Vector operator*(const T& tmp);
    Vector operator+(const Vector& tmp);
    Vector operator-(const Vector& tmp);
    T operator* (const Vector& tmp);//скалярное
    //ввод и вывод еще написать...
};
