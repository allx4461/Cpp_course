#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray{
private:
  T* data;
  std::int64_t size = -1;
  std::int64_t capacity;
  bool isEmpty() { return size == -1;}
  

public:
  DynamicArray();
  DynamicArray(std::int64_t capacity);
  DynamicArray(DynamicArray& other);
  ~DynamicArray();
  void push_back(T x);
  T add(std::int64_t idx1, std::int64_t idx2);
  T max();
  T min();
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();
  void push_front(T j);
  T front();
  std::int64_t get_size();//
  std::int64_t get_capacity();//
  T& at(std::int64_t idx);
  float back();
  void insert(std::int64_t idx,T val);
  void deleted(std::int64_t idx);
  void erase_after(std::int64_t idx);
  void increase_capacity(std::int64_t newCapacity);
  void decrease_capacity(std::int64_t newCapacity);

  T operator[](std::int64_t idx);
  T operator()();

};
template <typename T>
DynamicArray<T>::DynamicArray() {
  this->capacity = 8;
  this->data = new T[this->capacity];}

template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); 
  }
  this->capacity = capacity;
  this->data = new T[this->capacity];}
  
template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }}
template <typename T>
void DynamicArray<T>::push_back(T x) {
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;}
template <typename T>
T DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];}
template <typename T>
T DynamicArray<T>::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMax = -1e+38; // -1 * 10^38
  // float currentMax = std::numeric_limits<float>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;}

template <typename T>
T DynamicArray<T>::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMin = 1e+38; // -1 * 10^38
  // float currentMin = std::numeric_limits<float>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;}
template <typename T>
void DynamicArray<T>::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;}
template <typename T>
void DynamicArray<T>::reinitialize() {
  clear();
  data = new T[capacity]();}
template <typename T>
void DynamicArray<T>::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;}
template <typename T>
T DynamicArray<T>::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx];} // Arabic operator[]
template <typename T>
T DynamicArray<T>::operator()() {
  if (isEmpty()) {
    return 0;
  }
  float sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;}
//
template <typename T>
void DynamicArray<T>::push_front(T j){
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
  
    for (int i = 0; i < size; ++i) {
      tempArray[i+1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  } else {
    for (int i=size+1; i>0; --i){
      data[i]=data[i-1];
    }
  }
  data[0] = j;
  ++size;
  }
template <typename T>
T DynamicArray<T>::front(){
  return data[0];}
template <typename T>
float DynamicArray<T>::back(){
  return data[size];}
template <typename T>
void DynamicArray<T>::insert(std::int64_t idx,T val){
  if (idx>size || idx<0 || isEmpty()){
    throw std::invalid_argument("юзер ромб");}
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = idx; i < size; ++i) {
      tempArray[i+1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  } else {
    for (int i=size+1; i>idx; --i){
      data[i]=data[i-1];
    }
  }
  data[idx] = val;
  ++size;}
template <typename T>
void DynamicArray<T>::deleted(std::int64_t idx){
  if (idx>size || idx<0 || isEmpty()){
    throw std::invalid_argument("юзер круг");}
  for (int i=idx; i<size;++i){
    data[i]=data[i+1]; 
  }  size-=1;}
template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx){
  if (idx>size || idx<0 || isEmpty()){
    throw std::invalid_argument("юзер эллипс");}
  T* tempArray = new T[capacity];
  for (int i = 0; i <= idx+1; ++i) {
    tempArray[i] = data[i];
  }
    delete[] data;
    data = tempArray;
  size-=(idx);}
template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t newCapacity){
  if (newCapacity<capacity){
    throw std::invalid_argument("юзер циклоид");
  }
  T* tempArray = new T[newCapacity];
  for (int i = 0; i <= size; ++i) {
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;}
template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t newCapacity){
  if (newCapacity<0){
    throw std::invalid_argument("юзер эвольвента");
  }
  T* tempArray = new T[newCapacity];
  for (int i = 0; i <newCapacity; ++i) {
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;
  if (newCapacity<size){size=newCapacity-1;}}
template <typename T>
std::int64_t DynamicArray<T>::get_size(){
  return size;}
template <typename T>
std::int64_t DynamicArray<T>::get_capacity(){
  return capacity;}
template <typename T>
T& DynamicArray<T>::at(std::int64_t idx) { 
  if (idx < 0 || idx > size) {
        throw std::out_of_range("bad index");
    }
    return data[idx];}

#endif // DYN_ARR_H
