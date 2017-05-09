#!/usr/local/bin/python

import argparse, sys


class Board:
    # Boards start as all 0s, indicating each square can hold a queen.  When a
    # square is filled, all squares along the vertical, horizontal, and both
    # diagonals get incremented by one.  place_queen() and pull_queen()
    # manipulate the board; place tries to place a queen recursively in each
    # column.
    #
    # Queens are listed as 9000 or higher, for easy printing and recognition.
    def __init__(self, n = 8):
        self.board = [[0 for i in range(n)] for j in range(n)]
        self.n = n

    def __str__(self):
        out = ""
        for i in range(self.n):
            for j in range(self.n):
                if self.board[i][j] >= 7000:
                    out += 'Q'
                else:
                    out += '.'
            out += '\n'
        return out

    def place_queen(self, i, j, val = 1):
        # Put a queen on the board
        # horizontal
        for col in range(self.n):
            self.board[i][col] += val
        # vertical
        for row in range(self.n):
            self.board[row][j] += val
        # diagonals
        x = i - 1
        y = j + 1
        while x >= 0 and y <= self.n - 1:
            self.board[x][y] += val
            x -= 1
            y += 1
        x = i - 1
        y = j - 1
        while x >= 0 and y >= 0:
            self.board[x][y] += val
            x -= 1
            y -= 1
        x = i + 1
        y = j - 1
        while x <= self.n - 1 and y >= 0:
            self.board[x][y] += val
            x += 1
            y -= 1
        x = i + 1
        y = j + 1
        while x <= self.n - 1 and y <= self.n - 1:
            self.board[x][y] += val
            x += 1
            y += 1
        # queen herself
        self.board[i][j] += 9000 * val

    def pull_queen(self, i, j):
        # remove a queen from the board
        self.place_queen(i, j, val = -1)

    def place(self, i):
        if i >= self.n:
            return True
        for j in range(self.n):
            if self.board[i][j] == 0:
                self.place_queen(i, j)
                if self.place(i + 1):
                    return True
                else:
                    self.pull_queen(i, j)
        return False

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Solve the N-Queens problem')
    parser.add_argument('n', metavar='n', type=int, nargs=1, default=8, help='size of the chessboard')

    args = parser.parse_args()
    n = vars(args)['n'][0]

    board = Board(n)
    status = board.place(0)
    if status:
        print board
    else:
        print "No solutions are possible."
        sys.exit(2)
