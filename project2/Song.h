/*
Muskan Kapoor
Song.h 
CSCI 235
FALL 2018
PROJECT 2
interface file for class Song which includes all the listing of the public and private members
*/


#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include "SetInterface.h"

using namespace std;


class Song{
 private:
  std::string title_; //title of the Song
  std::string author_; //name of the author
  std::string album_; //name of the album 

 public:
  Song(); //default constructor

  Song(const std::string& title, const std::string& author = "", const std::string& album = ""); //paramterized constructor

  //sets the title_
  void setTitle(std::string title);

  //sets the author_
  void setAuthor(std::string author);

  //sets the album_
  void setAlbum(std::string album);

  //returns the title_
  std::string getTitle() const;

  //return the author_
  std::string getAuthor() const;

  //return the album_
  std::string getAlbum() const;

  //parem: Songs information 
  friend bool operator==(const Song& lhs, const Song& rhs);

};

#endif //end of class Song
