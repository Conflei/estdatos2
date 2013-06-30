#include <iostream>

using namespace std;

void test(int []);
void test2(int (*test)[4][4]);

int main ()
{
  //int leo[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  int matriz[4][4] = {
    {1, 2, 3, 4},
    {11, 3, 5, 7},
    {10, 4, 7, 10},
    {12, 5, 10, 15}
  };
  int (*ptero)[4][4];
  ptero = &matriz;
  test2(ptero);

  //ptero = &leo
  //ptero = leo;
  //cout << (*(ptero+2)) << "\t" << leo[2] << endl;
  //*ptero = 10;
  //ptero++;
  //cout << *ptero << "\t" << leo[0] << endl;
  //ptero = leo;
  //for (int i = 0; i< 10; i++) {
   // cout << *(ptero+i) << "\t| " << leo[i] << endl;
  //}
  //test(ptero);
  //test(leo);
}

/*void test(int test[]) {
  cout << test[2] << endl;
}*/

void test2(int (*test)[4][4]) {
  cout << *test[1][1] << endl;  
}

