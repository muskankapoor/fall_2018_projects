#include<iostream>

#include "Bag.h"

using namespace std;

int main(){
  Bag<int> intObject=Bag<int>(6);
  cout<<intObject.getData()<<endl;
  Bag<string> intObject2=Bag<string>("Vishal");
  cout<<intObject2.getData()<<endl;

return 0;

}
