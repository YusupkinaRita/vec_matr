#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main(){
  Matrix<int> m=Matrix<int>(4);
  Matrix<int> m2=Matrix<int>(4);
  std::cin>>m;
  std::cin>>m2;
  //Matrix<int> m2=Matrix<int>(m);
  Matrix<int> res=m*m2;
  std::cout<<m<<std::endl;
  std::cout<<m2<<std::endl;
  std::cout<<res<<std::endl;
    
    



    return 0;
}