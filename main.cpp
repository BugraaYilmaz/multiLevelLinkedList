#include <iostream>
using namespace std;
#include "multiLinkedList.h"
int main(){
char ch=' ';
int id=0;
double cgpa;
multiLinkedList<int> obj;



cout<<"-----------Welcome----------------"<<endl;
while(ch!='e'){
  cout<<"Enter 'i' to insert student informations"<<endl;
  cout<<"Enter 's' to delete any stundet's information"<<endl;
  cout<<"Enter 'c' or 'd' to print all student's informations as sorted (CGPA/id)"<<endl;
  cout<<"Enter 'e' to Exit"<<endl;
  cin>>ch;
  if(ch=='i'){
    cout<<"Enter -1 to exit"<<endl;
    while(id!=-1){
      cout<<endl<<"id :";
      cin>>id;
      if(id==-1){
        id=0;   //To avoid problems, we set id to 0 and break
        break;
      }
      cout<<endl<<"CGPA : ";
      cin>>cgpa;
      obj.insert(id,cgpa);
    }
  }
  if(ch=='s'){
    cout<<"Enter the student's id who you want to delete"<<endl;
    cout<<"id : ";
    cin>>id;
    obj.deleteNode(id);
  }
  if(ch=='c'){
    obj.print2('c');
  }
  if(ch=='d'){
    obj.print2('d');
  }
  if(ch=='e'){
    cout<<"---------Good Bye !---------------"<<endl;
    obj.destroyList2();
    cout<<endl<<"The list has been removed!";
  }
}
return 0;

}