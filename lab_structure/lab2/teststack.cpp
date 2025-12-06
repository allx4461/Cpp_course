#include "stack.h"
#include "dyn_arr.h"
#include <iostream>

int main() {
  Stack<int> st;
  std::int64_t k=2;
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(7);
  std::cout<<"дикий стек"<<std::endl;
  st.printData();
  std::cout<<st.top()<<" лежит сверху стека"<<std::endl;
  std::cout<<"достали "<<st.pop()<<" с вершины стека"<<std::endl;
  std::cout<<"вот такой стал стек"<<std::endl;
  st.printData();
  std::cout<<"достали "<<st.pop()<<" с вершины стека"<<std::endl;
  std::cout<<st.isEmpty()<<" - пустота стека"<<std::endl;
  std::cout<<"достали "<<k <<" раз вершины стека"<<std::endl;
  st/(k);
  std::cout<<"вот такой стал стек"<<std::endl;
  st.printData();
  std::cout<<st.isEmpty()<<" - пустота стека"<<std::endl;
  return 0;}
