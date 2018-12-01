/*
Muskan Kapoor
Song.cpp 
CSCI 235
FALL 2018
PROJECT 2
implementation file for class Song which includes all the member functions
*/



#include "Song.h"
#include <cstddef>

Song::Song():author_(""), album_(""){
}

Song::Song(const string& title, const string& author, const string& album){

  title_ = title;

  author_ = author;

  album_ = album;

}

void Song::setTitle(string title){ //"set" in setTitle here means "give a value" and has nothing

  title_ = title ;

}

void Song::setAuthor(string author){

  author_ = author;

}

void Song::setAlbum(string album){

  album_ = album;

}

string Song::getTitle() const{

  return title_;

}

string Song::getAuthor() const{

  return author_;

}

string Song::getAlbum() const{

  return album_;

}

bool operator==(const Song& lhs, const Song& rhs){

  if(lhs.getTitle()==rhs.getTitle() && lhs.getAlbum()==rhs.getAlbum() && lhs.getAuthor()==rhs.getAuthor()){

    return true;

  }

  return false;

}
