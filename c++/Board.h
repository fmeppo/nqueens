#include <string>


#ifndef BOARD_H
#define BOARD_H

class Board {
  public:
    Board(int n);
    ~Board();

    bool place(int);
    std::string str();

  private:
    int         count;
    int**       board;

    void place_queen(int, int, int);
    void pull_queen(int, int);
};

#endif // BOARD_H
