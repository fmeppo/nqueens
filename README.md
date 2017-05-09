# N-Queens

Sample implementations of the N-queens problem.  I'm using this as a little exercise to pick up the basics of new languages, so my solutions likely won't be as concise as possible.  For more information on the problem, see the [Wikipedia page](https://en.wikipedia.org/wiki/Eight_queens_puzzle).

My programs only find the first solution - others may exist.  I'm intentionally adding some nice trappings, like basic argument parsing (--help should always be supported, along with a required argument for the number of queens).  The solution is a basic recursive constraint-propagating chessboard; queens are placed and removed at runtime.  The code recurses through the rows; if propagated constraints preclude placing a queen in a row, False is returned and backtracking occurs.  At the end, the board should be printed.

Where possible, I'm representing the board logic with a class.  This is silly - there's only one board in the program, and gathering all the queen-manipulation functions as methods is unnecessary.  Consider this more an exercise in grammar than in decent software design (after all, my primary goal here is language practice).
