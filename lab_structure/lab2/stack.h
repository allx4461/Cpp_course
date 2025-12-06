#ifndef STACK_H
#define STACK_H
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include "dyn_arr.h"
template<typename T>
class Stack:public DynamicArray<T>{
public:
    bool isEmpty() {
        return this->get_size() == -1;}
  void push(T x);
  T top();
  T pop();
  void operator/(std::int64_t temp);
};  
template <typename T>
void Stack<T>::push(T x) {
    if (this->get_size() + 1 >= this->get_capacity()) {
        throw std::overflow_error("stack is full");
    }
    this->push_back(x);
}
template <typename T>
T Stack<T>::top(){
    if (isEmpty()) {
    throw std::underflow_error("stack is empty");}
    return this->at(this->get_size());}
template <typename T>
T Stack<T>::pop(){
    if (isEmpty()){throw std::underflow_error("stack is empty");}
    T temp=top();
    this->deleted(this->get_size());
    return temp;}
template <typename T>
void Stack<T>::operator/(std::int64_t temp){//попнуть несколько раз
  if (temp>this->get_size()){
    if (isEmpty()){throw std::underflow_error("stack is smaller");}
  }
  for (int i=0; i<temp;++i){
    this->pop();
  }
}

#endif // STACK_H
//скажите пожалуйста, а почему у вас системный язык на ноутбуке - немецкий?
