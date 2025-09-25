#include <iostream>
using namespace std;

int fakultaet(int n) {
    int ergebnis = 1;
    for (int i = 1; i <= n; i++) {
        ergebnis *= i;
    }
    return ergebnis;
}

int main() {
    cout << "5! = " << fakultaet(5) << endl;
    return 0;
}
