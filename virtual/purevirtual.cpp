#include <iostream>
using namespace std;

class DataBase{
public:
  virtual void getName()=0;
};

class Accountant:public DataBase{
public:
  void getName(){
    cout<<"THis is accountatn class"<<endl;
  }
};

class Manager:public DataBase{
public:
  void getName(){
    cout<<"this is manager class"<<endl;
  }
};

class Customer: public DataBase{
public:
  void getName(){
    cout<<"this is customer"<<endl;
  }
};

int main(){
  Manager m;
  Accountant a;
  Customer c;

  m.getName();
  a.getName();
  c.getName();
}
