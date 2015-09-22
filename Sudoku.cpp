/*
 * Sudoku.cpp
 * Name: Benjamin Hunt
 *
 * Oct 23 ,2013
 */
 
#include <iostream>
#include <string>
#include <vector>

#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku(const string& state){
  startstate = state;
  currentstate = state;
}

Sudoku::Sudoku(){
  // A default constructor doesn't make any sense in this case, but having this defined
  // here without any code allows a unit test to create a dummy object (with 
  // non-initialized private variables), so that it can test the private functions
  // Takeaway: leave this as is and SudokuTest.h will work as written.
}

string Sudoku::getCurrentBoard(){
  return currentstate;
}

string Sudoku::getStartBoard(){
  return startstate;
}

void Sudoku::printState(){
  printCurrentBoard(currentstate);
}

void Sudoku::printCurrentBoard(){
  printCurrentBoard(currentstate);
}

bool Sudoku::isValid(){
	return isValid(currentstate);
}

bool Sudoku::isComplete(){
	return isComplete(currentstate);
}

bool Sudoku::solve(){
	return solve(startstate);
}

void Sudoku::printCurrentBoard(const board_t& state){
    cout << "+---+---+---+" << endl;
	  for (int i = 0; i < 3; i++){
		  for (int j = 0; j < 3; j++){
		    cout << "|";
			  for (int k = 0; k < 3; k++){
				  for (int p = 0; p < 3; p++){
					  cout << state[(i*27)+(j*9)+(k*3)+p];
				  }
				  cout << "|";
			  }
			  cout << endl;
		  }
		cout << "+---+---+---+" << endl;
	  }
}

bool Sudoku::checkRow(const board_t& state){
  int boxstarts[] = {0,9,18,27,36,45,54,63,72};
  char test_two[] = {'0','0','0','0','0','0','0','0','0'};
  char test_values[] = {'0','0','0','0','0','0','0','0','0'};
  for (int i = 0; i < 9; i++){


    test_values[0]=(state[boxstarts[i]]);
    test_values[1]=(state[boxstarts[i]+1]);
    test_values[2]=(state[boxstarts[i]+2]);
    test_values[3]=(state[boxstarts[i]+3]);
    test_values[4]=(state[boxstarts[i]+4]);
    test_values[5]=(state[boxstarts[i]+5]);
    test_values[6]=(state[boxstarts[i]+6]);
    test_values[7]=(state[boxstarts[i]+7]);
    test_values[8]=(state[boxstarts[i]+8]);


    test_two[0]=(state[boxstarts[i]]);
    test_two[1]=(state[boxstarts[i]+1]);
    test_two[2]=(state[boxstarts[i]+2]);
    test_two[3]=(state[boxstarts[i]+3]);
    test_two[4]=(state[boxstarts[i]+4]);
    test_two[5]=(state[boxstarts[i]+5]);
    test_two[6]=(state[boxstarts[i]+6]);
    test_two[7]=(state[boxstarts[i]+7]);
    test_two[8]=(state[boxstarts[i]+8]);

    for (int t = 0; t < 9; t++){
      for(int p = 0; p < 9; p++){
        if (test_values[t] - '0' > 0){ //ensures element is a number, not a period
          if ( t!=p ){
            if (test_values[t] == test_two[p]){
              return false;
            }
          }
        }
      }
    }
  }
  return true;
}

bool Sudoku::checkCol(const board_t& state){
  char test_values[]={'0','0','0','0','0','0','0','0','0'};
  char test_two[]={'0','0','0','0','0','0','0','0','0'};
  for (int i = 0; i < 9; i++){


    test_values[0]=(state[i]);
    test_values[1]=(state[i+9]);
    test_values[2]=(state[i+18]);
    test_values[3]=(state[i+27]);
    test_values[4]=(state[i+36]);
    test_values[5]=(state[i+45]);
    test_values[6]=(state[i+54]);
    test_values[7]=(state[i+63]);
    test_values[8]=(state[i+72]);



    test_two[0]=(state[i]);
    test_two[1]=(state[i+9]);
    test_two[2]=(state[i+18]);
    test_two[3]=(state[i+27]);
    test_two[4]=(state[i+36]);
    test_two[5]=(state[i+45]);
    test_two[6]=(state[i+54]);
    test_two[7]=(state[i+63]);
    test_two[8]=(state[i+72]);

    for (int t = 0; t < 9; t++){
      for(int p = 0; p < 9; p++){
        if (test_values[t] - '0' > 0){ //ensures element is a number, not a period
          if ( t!=p ){
            if (test_values[t] == test_two[p]){
              return false;
            }
          }
        }
      }
    }
  }
	return true;
}

bool Sudoku::checkBox(const board_t& state){
  int boxstarts[] = { 0, 3, 6, 27, 30, 33, 54, 57, 60};
  char test_values[]={'0','0','0','0','0','0','0','0','0'};
  char test_two[]={'0','0','0','0','0','0','0','0','0'};
  for (int i = 0; i < 9; i++){     //cycle through boxes from upper left element


    test_values[0]=(state[boxstarts[i]]);
    test_values[1]=(state[boxstarts[i]+1]);
    test_values[2]=(state[boxstarts[i]+2]);
    test_values[3]=(state[boxstarts[i]+9]);
    test_values[4]=(state[boxstarts[i]+10]);
    test_values[5]=(state[boxstarts[i]+11]);
    test_values[6]=(state[boxstarts[i]+18]);
    test_values[7]=(state[boxstarts[i]+19]);
    test_values[8]=(state[boxstarts[i]+20]);

    test_two[0]=(state[boxstarts[i]]);
    test_two[1]=(state[boxstarts[i]+1]);
    test_two[2]=(state[boxstarts[i]+2]);
    test_two[3]=(state[boxstarts[i]+9]);
    test_two[4]=(state[boxstarts[i]+10]);
    test_two[5]=(state[boxstarts[i]+11]);
    test_two[6]=(state[boxstarts[i]+18]);
    test_two[7]=(state[boxstarts[i]+19]);
    test_two[8]=(state[boxstarts[i]+20]);
/*
    for (int k = boxstarts[i]; k <= boxstarts[i] + 18  ; k += 9){  //cycle through rows of box
      for (int p = 0; p < 3; p++){ //cycle through box elements in same row
        test_values.push_back(state[ k + p ]);
      }
    }
*/

    for (int t = 0; t < 9; t++){
      for(int p = 0; p < 9; p++){
        if (test_values[t] - '0' > 0){ //ensures element is a number, not a period
          if ( t!=p ){
            if (test_values[t] == test_two[p]){
              return false;
            }
          }
        }
      }
    }
  }
  return true;
}

bool Sudoku::isValid(const board_t& state){
		if ( checkCol(state) ){
		  if ( checkRow(state) ){
		    if ( checkBox(state) ){
		      return true;
		    }
		  }
		}
		return false;
}

bool Sudoku::checkCompletelyFilled(const board_t& state){
  for (int i = 0; i < 81; i++){
    if (state[i] == '.'){
      return false;
    }
  }
  return true;
}

bool Sudoku::isComplete(const board_t& state){
	 if ( isValid(state) ){
	   if ( checkCompletelyFilled(state) ){
	     return true;
	     }
	 }
	 return false;
}

 vector<board_t> Sudoku::getSuccessors(const board_t& state){
	 vector<board_t> ret;
	 int index;
	 char inserts[] = {'1','2','3','4','5','6','7','8','9'};
	 for (int i = 0; i < 81; i++){ //find index of next open element
		 if (state[i] == '.'){
			 index = i;
			 //break;
		 }
	 }
	 board_t newstate = state;
	 for (int j = 0; j < 9; j++){
	   newstate[index] = inserts[j];
	   if ( isValid(newstate) ){
	     ret.push_back(newstate);
	   }
	 }
	 return ret;
}
 
bool Sudoku::solve(const board_t& state){
  if ( isComplete(state) ){
    currentstate = state;
	  return true;
  }
  vector<board_t> children = getSuccessors(state);
  for (unsigned i = 0; i < children.size(); i++){
	  if ( solve(children[i]) ){
		  return true;
	  }
  }
  return false;
}

