/*
GeniusBar.cpp
Muskan Kapoor
This file has the implementation for the class GeniusBar. Each method has its implemntation details detailed. 
August 30, 2018
*/

//including interface files 
#include "GeniusBar.h"
#include "Customer.h"


//default constructor
//have to initalize these uninitalized variables
GeniusBar::GeniusBar(){
  current_wait_time_ = 0;
  number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
  number_of_customers_ = 0;

}


//pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS
//post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false
bool GeniusBar::addWaitingCustomer(Customer &new_customer){
  if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS){
    current_wait_time_ += WAIT_TIME_INCREMENT; //increment it
    new_customer.updateWaitTime(current_wait_time_); //update it 
    genius_bar_[number_of_customers_] = new_customer; //add the customer 
    number_of_customers_++; //update
    return true;
  }
  return false;
}


//pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)
//post: decrement number_of_customers_ and number_of_available_geniuses_
//return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise
bool GeniusBar::assignGeniusToCustomer(){
  if ((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)){
    number_of_customers_--; 
    number_of_available_geniuses_--;
    return true;
  }
  return false;
}


//pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES
//post: increment number_of_available_geniuses
//return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise
bool GeniusBar::releaseGenius(){
  if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES){
    number_of_available_geniuses_++;
    return true;
  }
  return false;
}


//pre: number_of_customers_ > 0
//post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ > 0, false otherwise
bool GeniusBar::updateCustomersWaitTime(){
  if (number_of_customers_ > 0){
    for (int i = 0; i < number_of_customers_; i++){
      genius_bar_[i].updateWaitTime(current_wait_time_ += WAIT_TIME_INCREMENT);
    }
    return true;
  }
  return false;
}
