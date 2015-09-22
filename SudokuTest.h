#ifndef SUDOKU_TEST_H
#define SUDOKU_TEST_H

#include <Sudoku.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class SudokuTest : public CxxTest::TestSuite {
public:

  // FILL IN MORE HERE
  
  void testisComplete(){
    Sudoku g; // This relies on a default constructor being implemented (empty is OK).
              // Currently it is in private, but since we've made SudokuTest a friend of
              // the Sudoku class (see line 85 in Sudoku.h), it can reach in and use
              // the private functions.  Useful for testing individual functions.
              // This completely relies on the fact that we know how Sudoku works inside
              // the class.  This is WHITE-BOX-TESTING because we look in the box/object.
    board_t s = ".................................................................................";
    TS_ASSERT(! g.isComplete(s) );

    s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.isComplete(s) );

  }
  
  void testcheckCompletelyFilled(){
    Sudoku g;
    board_t s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.checkCompletelyFilled(s) );

    s = "12345678945678912378912345623456789156789123489123456734567891267891234591234567.";
    TS_ASSERT(! g.checkCompletelyFilled(s) );
  }

  void testcheckCols(){
	  Sudoku g;
	  board_t s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
	  TS_ASSERT( g.checkCol(s) );

	  s = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";
	  TS_ASSERT(! g.checkCol(s) );

	  s = "4........456789123789123456234567891567891234891234567345678912678912345912345678";
	  TS_ASSERT(! g.checkCol(s) );

	  s = "121456789234561891345678912456789123567891234678912345789123456891234567912345678";
	  TS_ASSERT(! g.checkCol(s) );

    s = "123456789456789123789123456234567891567891234891234567345678912678912345912345688";
    TS_ASSERT(! g.checkCol(s) );
  }

  void testcheckRows(){
	  Sudoku g;
	  board_t s = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";
	  TS_ASSERT( g.checkRow(s) );

    s = "111111111222222222333333333444444444555555555666666666777777777888888888999999999";
	  TS_ASSERT(! g.checkRow(s) );

	  s = "121456789234561891345678912456789123567891234678912345789123456891234567912345678";
	  TS_ASSERT(! g.checkRow(s) );

  }

  void testcheckBox(){
	  Sudoku g;
	  board_t s = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
	  TS_ASSERT( g.checkBox(s) );

    s = "123456789321654987231564897......................................................";
	  TS_ASSERT(! g.checkBox(s) );

	  s = "121456789234561891345678912456789123567891234678912345789123456891234567912345678";
	  TS_ASSERT(! g.checkBox(s) );

	  s = "1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.1...5.8..39.7..598.2";
	  TS_ASSERT( g.checkBox(s) );

	  s = "123456789456789123789123456234567891567891234891234567345678912678912345912345688";
	  TS_ASSERT(! g.checkBox(s) );
  }

  void testisValid(){
    Sudoku g;
    board_t s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.isValid(s) );

    s = "4........456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT(! g.isValid(s) );

    s = "121456789234561891345678912456789123567891234678912345789123456891234567912345678";
    TS_ASSERT(! g.isValid(s) );
  }

  void testsolvewhitebox(){
    Sudoku g;

    board_t s = "123.567894567891.37891234562.4567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.solve(s) );

    board_t board = g.getCurrentBoard();
    TS_ASSERT( g.isComplete(board) );

    s = "1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.1...5.8..39.7..598.2";
    TS_ASSERT( g.solve(s) );

    board = g.getCurrentBoard();
    TS_ASSERT( g.isComplete(board) );
    g.printCurrentBoard(board);
  }

  void testSampleBoardZero(){
    Sudoku g;
    board_t s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardOne(){
    Sudoku g;
    board_t s = "759.4....68.5...4..3.2.95..56.1..9....3...1....1..6.37..53.7.9..7...8.53....6.721";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardTwo(){
    Sudoku g;
    board_t s = "1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.1...5.8..39.7..598.2";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardThree(){
    Sudoku g;
    board_t s = "1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.1...5.8..39.7..598.4";
    TS_ASSERT(! g.solve(s) );
  }

  void testSampleBoardFour(){
    Sudoku g;
    board_t s = "1.657..9.84..2.1...5.9.4...6.....2.3.82.9.74.4.7.....1...4.2.....5.8.....7..59...";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardFive(){
    Sudoku g;
    board_t s = "...5..68...8.19.......3..1.3....8..679.165.484..7....5.1..5.......32.5...37..4...";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardSix(){
    Sudoku g;
    board_t s = "...5..68...8.19.......3..1.3....8..679.165.484..7....5.1..5.......32.5...37......";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardSeven(){
    Sudoku g;
    board_t s = ".7.39.........85.9....5.1...2.1..3.44.3...2.56.8..4.9...2.4....7.65.........17.4.";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardEight(){
    Sudoku g;
    board_t s = "87.39.........85.9....5.1...2.1..3.44.3...2.56.8..4.9...2.4....7........5...17.4.";
    TS_ASSERT( g.solve(s) );
  }

  void testSampleBoardNine(){
    Sudoku g;
    board_t s = "...9....3.....1..4..6.5..97....3..7..59...61..4..2....79..6.8..6..3.....2....4...";
    TS_ASSERT( g.solve(s) );
  }


  // FILL IN MORE HERE
  
  void testSolve(){
            // This is BLACK-BOX-TESTING since we only use public methods.
    board_t s = ".........456789123789123456234567891567891234891234567345678912678912345912345678";
    Sudoku g(s);
    TS_ASSERT( g.solve() );
    s = g.getCurrentBoard();
    board_t sol = "123456789456789123789123456234567891567891234891234567345678912678912345912345678";
    TS_ASSERT( s.compare(sol) == 0);
  }
  
  void testPrintBoard(){
	  Sudoku g;
	  board_t s = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";
	  //g.printCurrentBoard(s);
  }
  // FILL IN MORE HERE
  
};
  
#endif
