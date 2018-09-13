#ifndef SET_H
#define SET_H

class Set: public SetInterface {
 private:
  static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
  ItemType items_[DEFAULT_SET_SIZE]; // array of set items_
  int item_count_;                  // current count of set items_
  int max_items_;                   // max capacity of the Set
  // post: Either returns the index of target in the array items_
  // or -1 if the array does not contain the target
  int getIndexOf(const ItemType& target) const;

};

#endif
//comment  


  
