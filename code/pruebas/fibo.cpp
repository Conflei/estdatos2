#include <iostream>

using namespace std;
int fibo(int f);

main() {
    int entrada;
    cin >> entrada;
    cout << "fibonacci de " << entrada << ": " << fibo(entrada) << endl;
}

int fibo(int f) {
    if (f < 2) {
      return f;
    } else {
      return fibo(f-1) + fibo(f-2);
    }
}
