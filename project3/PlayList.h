/*Muskan Kapoor
  CSCI 235
  Professor Ligorio
  Project 3
  PlayList.h interface file for PlayList
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include "LinkedSet.h"

class PlayList: public LinkedSet<Song>
{
 private:
  Node<Song>* tail_ptr_; //node to tail pointer  data item 
  Node<Song>* getPointerToLastNode() const; //get pointer to last node
  //private member function 
  Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
  ////get pointer to last node
  //private member function 

 public:
  PlayList(); //default constructor
  PlayList(const Song& a_song);   //parameterized constructor
  PlayList(const PlayList& a_play_list);  // copy constructor

  //return value of number of songs
  int getNumberOfSongs() const;

  //return empty
  bool isEmpty() const;

  //post: an added member
  //return if item is added 
  bool add(const Song& new_song) override;

  //item is removed
  //return if item is removed
  bool remove(const Song& a_song) override;

  
  //post: clears playlist
  void clearPlayList();
  
  //post: displays playlist
  void displayPlayList() const;
  
  //post: loops through playlist 
  void loop();
  
  //post: unloops through playlist
  void unloop();
  
  ~PlayList(); //destructor 

}; // end PlayList
#endif //end of playlist.h 
