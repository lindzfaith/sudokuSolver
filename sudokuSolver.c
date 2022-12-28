#include <stdbool.h>
#include <stdio.h>

const int size = 9;

bool solve(int sudokuBoard[][size]) {
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      // Zero is the placeholder
      if (sudokuBoard[x][y] == 0) {
        // check all the possible numbers
        for (int checkValue = 1; checkValue <= size; checkValue++) {
          bool valid = true;
          // Check the columns for validity
          for (int i = 0; i < size; i++) {
            if (sudokuBoard[i][y] == checkValue) {
              valid = false;
            }
          }
          // Then, check the rows
          for (int i = 0; i < size; i++) {
            if (sudokuBoard[x][i] == checkValue) {
              valid = false;
            }
          }
          // Finally, check the box
          int boxRow = x - (x % 3);
          int boxColumn = y - (y % 3);
          for (int i = boxRow; i < (boxRow + 3) && i < size; i++) {
            for (int j = boxColumn; j < (boxColumn + 3) && j < size; j++) {
              if (sudokuBoard[i][j] == checkValue) {
                valid = false;
              }
            }
          }
          // If valid, set the value and keep going until solved
          if (valid) {
              sudokuBoard[x][y] = checkValue;
              if (solve(sudokuBoard)) {
                return true;
              } else {
                sudokuBoard[x][y] = 0;
              }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main( int argc, char *argv[] ) {

  int sudokuBoard[size][size] = { 
    { 0, 0, 0, 3, 0, 0, 0, 5, 0 }, 
    { 2, 0, 1, 4, 7, 5, 3, 9, 0 },
    { 0, 0, 0, 0, 0, 6, 0, 0, 4 }, 
    { 0, 0, 3, 8, 9, 0, 0, 0, 0 },
    { 6, 9, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 6, 0, 0, 4, 9 },
    { 0, 5, 0, 0, 4, 0, 0, 6, 0 },
    { 0, 2, 0, 0, 0, 0, 0, 0, 5 },
    { 3, 0, 7, 0, 0, 0, 9, 0, 8 }
  };

  if (solve(sudokuBoard)) {
    // print if solved
    printf("-----------\n");
    for (int x = 0; x < size; x++) {
      printf("|");
      for (int y = 0; y < size; y++) {
        printf("%d", sudokuBoard[x][y]);
      }
      printf("|");
      printf("\n");
    }
    printf("-----------\n");
    // unsolveable! 
  } else {
    printf("Unsolveable");
  }
  return 0;
}