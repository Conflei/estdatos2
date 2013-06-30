#include <iostream>

using namespace std;

void print(int pMatrix[][4], int length);

int main () {
  int matrix[][4] = {
    {10, 11, 12, 13},
    {20, 21, 22, 23},
    {30, 31, 32, 33},
    {40, 41, 42, 43}
  };

  print(matrix, 4);
}

void print(int pMatrix[][4], int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      cout << pMatrix[i][j] << " | ";
      if (j == 3) { cout << endl; }
    }
  }
}

