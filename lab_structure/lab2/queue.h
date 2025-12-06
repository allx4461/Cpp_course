#ifndef QUEUE_H
#define QUEUE_H
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include "stack.h"

template <typename T>
class Queue{
private:
  Stack<T> in;
  Stack<T> out;
  
public:
  bool isEmpty() { return (this->in.isEmpty() and this->out.isEmpty());}
  void printout();
  void printin();
  void print();
  void enqueue(T x);
  T dequeue();
  std::int64_t size();
  void operator%(T temp);
  void operator^(T temp);
};
template <typename T>
std::int64_t Queue<T>::size(){
    int k=0;
    return in.get_size()+out.get_size()+2;
}
template <typename T>
void Queue<T>::enqueue(T x){
    in.push(x);
}
template <typename T>
void Queue<T>::printout(){
    if (!(out.isEmpty())){
        for (int i=0;i<=out.get_size();++i){
            std::cout<<out[i]<<" ";
        }
    std::cout<<std::endl;
}}
template <typename T>

void Queue<T>::printin(){
    if (!(in.isEmpty())){
        for (int i=in.get_size();i>=0;--i){
            std::cout<<in[i]<<" ";
        }
    std::cout<<std::endl;
}}
template <typename T>
void Queue<T>::print(){
    if (this->isEmpty()){
        throw std::underflow_error("queue is empty");}
    printout();
    printin();
    std::cout<<std::endl;
}
template <typename T>
T Queue<T>::dequeue(){
    if (this->isEmpty()){
        throw std::underflow_error("queue is empty");}
    if (out.isEmpty()){
        while (!(this->in.isEmpty())){
            out.push(in.pop());
        }
    }
    if (!(out.isEmpty())){
        return out.pop();
    }
    return 0; 
}
template <typename T>
void Queue<T>::operator%(T temp){//фибоначчизирование очереди (не знаю зачем)
  if (this->isEmpty()){ throw std::underflow_error("queue is empty");}
  if (out.isEmpty()){
        while (!(this->in.isEmpty())){
            out.push(in.pop());
        }
    }
    if (!(out.isEmpty())){
        for (int i=out.get_size(); i>=0;--i){
            out.at(i)=out.at(i)+temp;
            temp = out.at(i);
        }
    }
}
template <typename T>
void Queue<T>::operator^(T temp){//факторизирование очереди (почему нет)
  if (this->isEmpty()){ throw std::underflow_error("queue is empty");}
  if (out.isEmpty()){
        while (!(this->in.isEmpty())){
            out.push(in.pop());
        }
    }
    if (!(out.isEmpty())){
        for (int i=out.get_size(); i>=0;--i){
            out.at(i)=out.at(i)*temp;
            temp = out.at(i);
        }
    }
}
#endif 
