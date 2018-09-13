/*
Customer.cpp
Muskan Kapoor
This file has the implementation for the class Customer. Each method has its implemntation details detailed. 
August 30, 2018
*/

//including interface files 
#include "Customer.h"


//default constructor
//the second constructor will be used 
Customer::Customer(){
}


//constructor
//assinging the new variables to the private variable 
Customer::Customer(string name, string device, int wait_time){
  name_ = name;
  defective_device_ = device;
  wait_time_ = wait_time;
}


//return name of customer 
string Customer::getName(){
  return name_;
}


//return device
string Customer::getDevice(){
  return defective_device_;
}


//return wait time
int Customer::getWaitTime(){
  return wait_time_;
}


//updating wait time with new wait time
void Customer::updateWaitTime(int new_wait_time){
  wait_time_ = new_wait_time;
}
