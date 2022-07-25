#include <string>

#include "Board.h"


Board::Board(int n) {
  count = n;
  
  board = new bool*[n];
  for( int i = 0; i < n; i++ ) {
    board[i] = new bool[n];
    for( int j = 0; j < n; j++ ) {
      board[i][j] = false;
    }
  }
}


Board::~Board() {
  for( int i = 0; i < count; i++ ) {
    delete[] board[i];
  }
  delete[] board;
}


bool
Board::place(int n) {
  return true;
}


std::string
Board::str() {
  return "asdf";
}
