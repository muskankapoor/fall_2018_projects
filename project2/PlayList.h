/*
Muskan Kapoor
PlayList.h 
CSCI 235
FALL 2018
PROJECT 2
interface file for class PlayList which includes all the listing of the public and private members
*/

 
#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Set.h"
#include "Song.h"

using namespace std;

class PlayList{
 private:
  Set<Song> playlist_; //vector to store Songs
 public:
  PlayList(); //default customer

  PlayList(const Song& a_song); //paramaterized customer

  //pre: number of Songs default capacity
  //post: recieves the number of song
  //return: the number of Songs 
  int getNumberOfSongs() const;

  //pre: set may or may contain something
  //post: determines whether this set is empty or not
  //return: True if the set is empty, or false if not. 
  bool isEmpty() const;

  //pre: may or may not contain a song from before
  //post: a soong will be added
  //return: True if addition was successful, or false if not. 
  bool addSong(const Song& new_song);

  //pre:must already have a song from before
  //post:a song will be removed
  //return: True if removal was successful, or false if not. 
  bool removeSong(const Song& a_song);

  //pre:must be filled with at least one Song
  //post:True if removal was successful, or false if not. 
  //return: empty list 
  void clearPlayList();

  //pre:list will have some song
  //post:will display
  //return:display the PlayList
  void displayPlayList() const;

};


#endif //end of PlayList
