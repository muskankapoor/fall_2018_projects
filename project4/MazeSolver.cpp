/*
Muskan Kapoor
MazeSolver.cpp
11/6/18
Project 4
implementation of MazeSolver.h
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "MazeSolver.h"
using namespace std;

//constructor that reads in and uses helper function
MazeSolver::MazeSolver(string input_file){
  ifstream in_stream;
  in_stream.open(input_file);
  if(in_stream.fail()){
    cout << "Cannot read from input file" <<endl;
    exit(1);
  }
  int rows, cols;
  in_stream >> rows >> cols;
  maze_rows_ = rows;
  maze_columns_ = cols;
  initializeMaze(rows, cols);
  fillMaze(in_stream); 
  initializeSolution();
  maze_ready = true;

  in_stream.close();
}

//destructor that clears the maze
MazeSolver::~MazeSolver(){
  for(int i = 0; i < maze_rows_; i++){
    delete maze_[i];
    delete solution_[i];
  }
  delete maze_;
  delete solution_;
}

//maze is ready 
bool MazeSolver::mazeIsReady(){
  return maze_ready;
}

//finding the current position 
bool MazeSolver::solveMaze(){
  Position current_pos = backtrack_stack_.top();
  while(!backtrack_stack_.empty()) {
    if(solution_[current_pos.row][current_pos.column] == '$'){
      cout << "Found the exit!!!" << endl;
      return true;
    }
    else if(extendPath(current_pos)){
      solution_[current_pos.row][current_pos.column] = '>';
      current_pos = backtrack_stack_.top(); 
    }
    else {
      maze_[current_pos.row][current_pos.column] = 'X';
      solution_[current_pos.row][current_pos.column] = '@';
      backtrack_stack_.pop(); 
      if(!backtrack_stack_.empty()){
        current_pos = backtrack_stack_.top(); 
      }
      else {
        cout << "This maze has no solution." << endl;
        return false;
      }
    }
  }
  return true;
}


//initializemaze and creating that maze
void MazeSolver::initializeMaze(int rows, int columns){  
  maze_ = new char*[rows];
  for(int i = 0; i < rows; i++){
    maze_[i] = new char[columns];
  }
}

//filling up the maze
void MazeSolver::fillMaze(ifstream& input_stream){
  for(int i = 0; i < maze_rows_; i++){
    for(int j = 0; j < maze_columns_; j++){
      input_stream >> maze_[i][j];
    }
  }
}


//intilaiing the solution of the maze
void MazeSolver::initializeSolution() {
  copyMazetoSolution();
  Position pos; 
  pos.row = 0;
  pos.column = 0; 

  backtrack_stack_.push(pos);
  if(extendPath(pos)){
   solution_[0][0] = '>';
  }

}

//copying the maze solution 
void MazeSolver::copyMazetoSolution(){  
  solution_ = new char*[maze_rows_];
  for(int i = 0; i < maze_rows_; i++){
     solution_[i] = new char[maze_columns_];
  }
 
  for(int i = 0; i < maze_rows_; ++i){
    for(int j = 0; j < maze_columns_; ++j){
      solution_[i][j] = maze_[i][j];
    }
  }
}

//creating the path for the maze
bool MazeSolver::extendPath(Position current_position){ 
  Position new_position; 
  bool extended = false;

  if(isExtensible(current_position, SOUTH)){
    new_position = getNewPosition(current_position, SOUTH);
    backtrack_stack_.push(new_position);
    extended = true;
  }
  if(isExtensible(current_position, EAST)){
    new_position = getNewPosition(current_position, EAST);
    backtrack_stack_.push(new_position);
    extended = true;
  }
  return extended;
}

//getting a newpostion and ending to the new direcion 
Position MazeSolver::getNewPosition(Position old_position, direction dir) {
  Position new_position;

  if(dir == SOUTH){
    new_position.row = old_position.row+1;
    new_position.column = old_position.column;
  }
  else if(dir == EAST){
    new_position.column = old_position.column+1;
    new_position.row = old_position.row;
  }
  return new_position; 
}


//whether or not you can continue to the maze
bool MazeSolver::isExtensible(Position current_position, direction dir) { 
  if(dir == SOUTH){
    if(current_position.row < maze_rows_-1 && ((maze_[current_position.row+1][current_position.column] == '_') || (maze_[current_position.row+1][current_position.column] == '$'))){
      return true;
    }
  }
  else if(dir == EAST){
    if(current_position.column < maze_columns_-1 && ((maze_[current_position.row][current_position.column+1] == '_') || (maze_[current_position.row][current_position.column+1] == '$'))){
      return true;
    }
  }
  return false;
}


//printing the maze solution 
void MazeSolver::printSolution(){  
  cout << "The solution to this maze is:" << endl;
  for(int i = 0; i < maze_rows_; i++){
    for(int j = 0; j < maze_columns_; j++){
      cout << solution_[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
