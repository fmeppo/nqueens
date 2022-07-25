#include <iostream>
#include <string>
#include <getopt.h>
#include <stdlib.h>

#include "Board.h"


const std::string usage = "Usage:\n  -h, --help for help\n  -n, --number N to set board size N";


int
main(int argc, char **argv)
{
  int c;
  int n = 8;
  bool status;

  while (1) {
    static struct option long_options[] = {
      {"number", required_argument, &n, 'n'},
      {"help",   no_argument,       0,  'h'},
      {0, 0, 0, 0}
    };

    int option_index = 0;
    int tmp;

    c = getopt_long(argc, argv, "n:h", long_options, &option_index);

    if( c == -1 )
      break;

    switch(c) {
      case 0:
      case 'h':
        std::cout << usage << std::endl;
        continue;
      case 'n':
        tmp = strtol(optarg, NULL, 10);
        if( errno == EINVAL || errno == ERANGE )
          std::cout << "Unsupported number: " << optarg << std::endl;
        else
          n = tmp;
        continue;
      case '?':
        // getopt_long should already print an error message
        break;
      default:
        std::cerr << c << std::endl;
        abort();
    }
  }

  Board board(n);
  status = board.place(0);
  if(status)
    std::cout << board.str() << std::endl;
  else {
    std::cout << "No solutions are possible." << std::endl;
    return 2;
  }

  return 0;
}
