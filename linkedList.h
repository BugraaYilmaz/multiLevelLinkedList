#ifndef LLH
#define LLH
#include <iostream>
using namespace std;

template<class T>
class nodeType{
  public:
  T info;
  nodeType<T> *link;        //Additional to our textbook, i used up and down pointers
  nodeType<int> *up;        //The code uses up and down to transition between id and the
  nodeType<double> *down;   //cgpa of a single student. I have added an image representation of this 
};                          // in the files.
template<class T>
class LinkedListType{
  public: 
  bool isEmptyList();
  void print();
  void destroyList();
  virtual void insertFirst(T& item) = 0;
  virtual void insertLast(T& item) = 0;
  virtual void deleteNode(T& item) = 0;
  int count;
  nodeType<T> *first;
  LinkedListType();
  ~LinkedListType();
};
template<class T>
LinkedListType<T>::LinkedListType(){
first=NULL;
count=0;
}
template<class T>
void LinkedListType<T>::destroyList(){
count=0;
nodeType<T> *tmp;
while(first!=NULL){
  tmp=first;
  first=first->link;
  delete tmp;
}
}
template<class T>
LinkedListType<T>::~LinkedListType(){
destroyList();
}
template<class T>
void LinkedListType<T>::print(){
  nodeType<T> *temp;
  temp=first;
  while(temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->link;
  }
}
template<class T>
bool LinkedListType<T>::isEmptyList(){
  return(first==NULL);
}


























#endif