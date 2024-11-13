#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main(){
    Vector<int> vec1=Vector<int>(3);
    Vector<int> vec2=Vector<int>(3);
    Vector<int> vec3=Vector<int>(3);
    
    Matrix<int> m=Matrix<int>(3);
    std::cin>>vec1;
    std::cin>>vec2;
    std::cin>>vec3;

    m[0]=vec1;
    m[1]=vec2;
    m[2]=vec3;
    Matrix<int> m2=Matrix<int>(m);
    Matrix<int> res=m*m2;
    std::cout<<m<<std::endl;
    std::cout<<m2<<std::endl;
    std::cout<<res<<std::endl;
    
    
    



    return 0;
}