#ifndef MLL
#define MLL
#include <iostream>
using namespace std;
#include "linkedList.h"

template<class T>
class multiLinkedList:public LinkedListType<T>{
public:
nodeType<int> *First1;        //First1 Represents the start pointer of the id list.
nodeType<double> *First2;     //First2 Represents the start pointer of the cgpa list.


void insert(int,double);       //in insert, i used ordered linked list type of insertation.
void insertFirst(T& item);     // while putting in the values, the code orders the values.
void insertLast(T& item);      
void deleteNode(T& item);   //deleteNode deletes 2 nodes which includes id and cgpa of a single student
void print2(char ch);     //print2 function prints based on the char that it gets.
void destroyList2();      //  It can print lists that are ordered by id or cgpa.
};                        

template<class T>
void multiLinkedList<T>::insert(int id,double cgpa){

nodeType<int> *newNode;
newNode= new nodeType<int>;
nodeType<double> *newNode2;
newNode2= new nodeType<double>;
nodeType<int> *CurrentInt;
nodeType<double> *CurrentDouble;
nodeType<int> *TrailerInt;
nodeType<double> *TrailerDouble;
int flag1=0;


newNode->info=id;
newNode->link=NULL;
newNode2->info=cgpa;
newNode2->link=NULL;

if(First1==NULL){
First1=newNode;                //If the lists are empty.
First1->down=newNode2;
First2=newNode2;
First2->up=First1;
}
else{
CurrentInt=First1;
while(CurrentInt!=NULL && flag1==0){        //Finding the place to insert node
if(id < CurrentInt->info){
  flag1=1;
}
else{
  TrailerInt=CurrentInt;
  CurrentInt=CurrentInt->link;
}
}
flag1=0;
if(CurrentInt==First1){                   //if we have to insert it to the first place.
newNode->link=CurrentInt;
First1=newNode;
}
else{
TrailerInt->link=newNode;               //if we have to insert in the middle or in the last
newNode->link=CurrentInt;
}

CurrentDouble=First2;                  //Same thing for the CGPA list.
while(CurrentDouble!=NULL && flag1==0){
if(cgpa < CurrentDouble->info){
  flag1=1;
}
else{
  TrailerDouble=CurrentDouble;
  CurrentDouble=CurrentDouble->link;
}
}
flag1=0;
if(CurrentDouble==First2){
newNode2->link=CurrentDouble;
First2=newNode2;
}
else{
TrailerDouble->link=newNode2;
newNode2->link=CurrentDouble;
}
newNode->down=newNode2;
newNode2->up=newNode;
}
} 
template<class T>
void multiLinkedList<T>::insertFirst(T& item){   //i had to implemet them because they are pure virtual in linkedList.h
  insert(item,item);
}
template<class T>
void multiLinkedList<T>::insertLast(T& item){
  insert(item,item);
}
template<class T>
void multiLinkedList<T>::deleteNode(T& item){
  nodeType<int> *CurrentInt;
  nodeType<double> *CurrentDouble;
  nodeType<int> *TrailerInt;
  nodeType<double> *TrailerDouble;
  int flag1=0;
  int flag2=0;
  CurrentInt=First1;
  nodeType<double> *TempDown;

  while(CurrentInt!=NULL && flag1==0){     //Finding the item to be deleted
    if(CurrentInt->info==item){
      flag1=1;
    }
    else{
      TrailerInt=CurrentInt;
      CurrentInt=CurrentInt->link;
    }
  }
  if(flag1==0){
    cout<<"The student cannot be found."<<endl;
  }
  else{                           //if item is found
    flag1=0; 
    if(CurrentInt==First1){       //if the item to be deleted is in the first 
      TempDown=CurrentInt->down;   //we also get TempDown because we want to find it in the cgpa list later
      First1=First1->link;
      delete CurrentInt;
    }
    else{                          //if item to be deleted in the middle or in the last
      TempDown=CurrentInt->down;
      TrailerInt->link=TrailerInt->link->link;
      delete CurrentInt;
    }
  }

  if(TempDown==First2){          //Same things for the cgpa list
    First2=First2->link;
    delete TempDown;
  }
  else{
    CurrentDouble=First2;
    while(CurrentDouble!=TempDown){   //But we use TempDown to search the list.
      TrailerDouble=CurrentDouble;
      CurrentDouble=CurrentDouble->link;
    }
    TrailerDouble->link=TrailerDouble->link->link;
    delete CurrentDouble;
  }



}
template<class T>
void multiLinkedList<T>::print2(char ch){
nodeType<int> *CurrentInt;
nodeType<double> *CurrentDouble;
if(ch=='d'){
  CurrentInt=First1;

  while(CurrentInt!=NULL){
    cout<<"id : "<< CurrentInt->info<<" CGPA : "<<CurrentInt->down->info<<endl<<endl;
    CurrentInt=CurrentInt->link;
  }
}
else if(ch=='c'){
  CurrentDouble=First2;
  while(CurrentDouble!=NULL){
    cout<<"id : "<<CurrentDouble->up->info<<" CGPA : "<<CurrentDouble->info<<endl<<endl;
    CurrentDouble=CurrentDouble->link;
  }
}
}
template <class T>
void multiLinkedList<T>::destroyList2(){  //Destroying both lists.
  nodeType<int> *CurrentInt;
  nodeType<double> *CurrentDouble;
  nodeType<int> *TrailInt;
  nodeType<double> *TrailDouble;
  TrailInt=First1;
  CurrentInt=First1->link;
  while(CurrentInt!=NULL){
    delete TrailInt;
    TrailInt=CurrentInt;
    CurrentInt=CurrentInt->link;
  }
  TrailDouble=First2;
  CurrentDouble=First2->link;
  while(CurrentDouble!=NULL){
    delete TrailDouble;
    TrailDouble=CurrentDouble;
    CurrentDouble=CurrentDouble->link;
  }
}






















#endif