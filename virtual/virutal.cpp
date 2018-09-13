#include <iostream>
#include <string>
using namespace std;

class A{
public:
 virtual void display(){
    cout<<"this is class a"<<endl;
  }
};

class B:public A{
public:
  void display(){
    cout<<"this is class b"<<endl;
  }
};

int main(){
  A *a;
  B b;
  a=&b;
  a->display();
}
