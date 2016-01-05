/*
 * main.cpp
 * Name: Benjamin Hunt
 *
 * Will solve any 9x9 Sudoku board recursively.
 *
 * Oct 23 ,2013
 */

#include <iostream>
#include <string>
#include <fstream>

#include "Sudoku.h"

using namespace std;


int main(int argc, char* argv[]) {
  if(argc != 2){
    cout << "Enter sudoku board file to solve as single command-line argument.\n\n";
    return 0;
  }
  
  // Open file for reading
  ifstream file;
  file.open(argv[1]);
  
  // Verify the file stream is OK
  if(file.fail()){
    cout << "Error opening: " << argv[1] << " Please try again\n";
    return 0;
  }
  
  // Read in file to string, ignoring newline characters.
  string game = "";
  string line;
  while(file >> line){  // Loop through all lines and append to a game string.
    game = game + line;
  }
  file.close();
  
  // Use simpleGame below if you don't want to read from a file.  BTW, this is state0-1sol.txt
  //string game = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
  
  Sudoku s(game);         // Create a new Game object with the given board state.
  s.printCurrentBoard();  
  
  bool solvable = s.solve();// This does ALL the solving work!

  cout << endl << "Solved? :" << solvable << endl;

  s.printCurrentBoard();
  if (! solvable){
    cout << endl << "This is an invalid game board and can not be solved" << endl << endl;
  }
  
  
  return 0;  
}
