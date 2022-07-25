#include <string>

#include "Board.h"


Board::Board(int n) {
  count = n;
  
  board = new int*[n];
  for( int i = 0; i < n; i++ ) {
    board[i] = new int[n];
    for( int j = 0; j < n; j++ ) {
      board[i][j] = 0;
    }
  }
}


Board::~Board() {
  for( int i = 0; i < count; i++ ) {
    delete[] board[i];
  }
  delete[] board;
}


void
Board::place_queen(int i, int j, int val = 1) {
  // Put a queen on the board
  // horizontal
  for( int col = 0; col < count; col++ )
    board[i][col] += val;

  // vertical
  for( int row = 0; row < count; row++ )
    board[row][j] += val;

  // diagonals
  int x = i - 1;
  int y = j + 1;
  while( x >= 0 && y <= count - 1 ) {
    board[x][y] += val;
    x -= 1;
    y += 1;
  }
  x = i - 1;
  y = j - 1;
  while( x > 0 && y >= 0 ) {
    board[x][y] += val;
    x -= 1;
    y -= 1;
  }
  x = i + 1;
  y = j - 1;
  while( x < count - 1 && y >= 0 ) {
    board[x][y] += val;
    x += 1;
    y -= 1;
  }
  x = i + 1;
  y = j + 1;
  while( x <= count - 1 && y <= count - 1 ) {
    board[x][y] += val;
    x += 1;
    y += 1;
  }
  board[i][j] += 9000 * val;
}


void
Board::pull_queen(int i, int j) {
  place_queen(i, j, -1);
}


bool
Board::place(int i) {
  if( i >= count )
    return true;
  for( int j = 0; j < count; j++ ) {
    if( board[i][j] == 0 ) {
      place_queen(i, j);
      if( place(i + 1) )
        return true;
      else
        pull_queen(i, j);
    }
  }
  return false;
}


std::string
Board::str() {
  std::string out = "";
  for( int i = 0; i < count; i++ ) {
    for( int j = 0; j < count; j++ ) {
      if( board[i][j] >= 7000 )
        out += 'Q';
      else
        out += '.';
    }
    out += '\n';
  }
  return out;
}
