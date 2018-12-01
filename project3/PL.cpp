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

#include "PlayList.h"
#include <iostream>
using namespace std;

PlayList::PlayList(){
    LinkedSet();
    tail_ptr_ = getPointerToLastNode();
} //end default constructor 

PlayList::PlayList(const Song& a_song){
    Node<Song>* an_entry = new Node<Song>;
    an_entry->setItem(a_song);
    an_entry->setNext(head_ptr_);
    head_ptr_ = an_entry;
    an_entry->setNext(nullptr);
    tail_ptr_ = getPointerToLastNode();
} //end parameterized constructor 

PlayList::PlayList(const PlayList& a_play_list){
    Node<Song>* present_ptr = a_play_list.head_ptr_;
    head_ptr_ = new Node<Song>();
    head_ptr_->setItem(present_ptr->getItem());
    Node<Song>* new_playlist_ptr = head_ptr_;
    present_ptr = present_ptr->getNext();
    while(present_ptr != nullptr){
        Song next_ptr = present_ptr->getItem();
        Node<Song>* new_song_entry = new Node<Song>(next_ptr);
        new_playlist_ptr->setNext(new_song_entry);
        new_playlist_ptr = new_playlist_ptr->getNext();
        present_ptr = present_ptr->getNext();
    }
    tail_ptr_ = getPointerToLastNode();
}//end copy constructor 

int PlayList::getNumberOfSongs() const {
    return getCurrentSize();
}//end getnumberofsongs function

bool PlayList::isEmpty() const{
    if (LinkedSet::isEmpty ()){
        return true;
    }
    return false;
} //end isempty function 

bool PlayList::add(const Song& new_song){
    if(!LinkedSet::contains(new_song)){
        Node<Song>* an_entry = new Node<Song>;
        an_entry->setItem(new_song);
        an_entry->setNext(nullptr);
        tail_ptr_->setNext(an_entry);
    }
    tail_ptr_ = getPointerToLastNode();
    return true;
}//end add fucntion 

bool PlayList::remove(const Song& a_song){
    Node<Song>* previous_ptr = new Node<Song>;
    Node<Song>* present_ptr = getPointerTo(a_song, previous_ptr);
    Node<Song>* temporary_ptr = nullptr;
    bool Remove = false;
    if(head_ptr_->getItem() == a_song){
        temporary_ptr = head_ptr_;
        head_ptr_ = (head_ptr_->getNext());
        Remove = true;

    }else if(present_ptr != nullptr){
        temporary_ptr = present_ptr;
        previous_ptr->setNext(present_ptr->getNext());
        Remove = true;
    }
    return Remove;
}//end remove function 


Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
    Node<Song>* present_ptr = head_ptr_;
    previous_ptr = nullptr;
    bool found = false;
    if(target == present_ptr->getItem()){
        return present_ptr;
    }
    while(!found && (present_ptr != nullptr)){
        if(target == present_ptr->getItem()){
            found = true;
        }else{
            previous_ptr = present_ptr;
            present_ptr = present_ptr->getNext();
        }
    }
    return present_ptr;
}//end getpointertolastnode

Node<Song>* PlayList::getPointerToLastNode() const{
    Node<Song>* present_ptr = head_ptr_;
    while(present_ptr != nullptr){
        if(present_ptr->getNext() == nullptr){
            return present_ptr;
        }else{
	  present_ptr = present_ptr->getNext();
        }
    }
    return present_ptr;
}//end getponter to 


void PlayList::loop(){
    tail_ptr_->setNext(head_ptr_);
}//end of loop 

void PlayList::unloop(){
    Node<Song>* current_ptr = head_ptr_;

    while(current_ptr->getNext() != head_ptr_){
        current_ptr = current_ptr->getNext();
    }
    current_ptr->setNext(nullptr);
}//end of unloop


void PlayList::displayPlayList() const{
    std::vector<Song> playlist_vector;
    Node<Song>* current_ptr = head_ptr_;
    int temp = 0;
    while ((current_ptr != nullptr)){
        playlist_vector.push_back(current_ptr->getItem());
        current_ptr = current_ptr->getNext();
        temp++;
    }

    for (unsigned i = 0; i< playlist_vector.size(); i++){
        std::cout << "* Title: " << playlist_vector.at(i).getTitle()
                  << "* Author: " << playlist_vector.at(i).getAuthor()
                  << "* Album: " << playlist_vector.at(i).getAlbum()
                  << " *" << std::endl;
    }

    std::cout << "End of playlist" << std::endl;
}//end of displayplaylist


void PlayList::clearPlayList(){
    LinkedSet::clear();
}//clear the playlist end


PlayList::~PlayList(){
    clear();
}//end of destructor 
