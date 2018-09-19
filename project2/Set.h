/*
Muskan Kapoor
Set.h 
CSCI 235
FALL 2018
PROJECT 2
interface file for class Set which includes all the listing of the public and private members
*/


#ifndef SET_
#define SET_

#include "SetInterface.h"

template<class ItemType>
class Set : public SetInterface<ItemType>{
private:
  static const int DEFAULT_SET_SIZE = 4;     // Small size to test for a full bag
  ItemType items_[DEFAULT_SET_SIZE];         // Array of bag items
  int item_count_;                           // Current count of bag items
  int max_items_;                            // Max capacity of the bag

  // Returns either the index of the element in the array items that
  // contains the given target or -1, if the array does not contain
  // the target.
  int getIndexOf(const ItemType& target) const;

 public:
  Set(); //default constructor

  //pre: may be empty or have some something
  //post: recieves the current size
  //return: the number of the current size
  int getCurrentSize() const;

  //pre: set may or may contain something
  //post: determines whether this set is empty or not
  //return: True if the set is empty, or false if not. 
  bool isEmpty() const;

  //pre: may or may not contain an item
  //post: a soong will be added
  //return: True if addition was successful, or false if not.
  bool add(const ItemType& newEntry);

  //pre:must already have a item from before
  //post:a song will be removed
  //return: True if removal was successful, or false if not.
  bool remove(const ItemType& anEntry);

  //pre:must be filled with at least one Song
  //post:True if removal was successful, or false if not. 
  //return: empty list 
  void clear();

  //pre: may or may not have something contained
  //post: contains that entry or not
  //return  True if set contains anEntry, or false otherwise.
  bool contains(const ItemType& anEntry) const;

  //pre:may or not may not contain empty vector Fills a vector with all entries that are in this set.
  //post:something contained in the set
  //return:A vector containing all the entries in the set. 
  std::vector<ItemType> toVector() const;
  
}; // end Set

#include "Set.cpp"
#endif
