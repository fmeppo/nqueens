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
    bool**       board;
};

#endif // BOARD_H
