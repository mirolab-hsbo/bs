#include <iostream>
#include <string>
using namespace std;

int main() {
    int zahl = 42;
    string text = "Hallo Pointer";

    int* pZahl = &zahl;
    string* pText = &text;

    cout << "Wert von zahl: " << zahl << endl;
    cout << "Adresse von zahl: " << pZahl << endl;
    cout << "Wert über pZahl: " << *pZahl << endl;

    cout << "Wert von text: " << text << endl;
    cout << "Adresse von text: " << pText << endl;
    cout << "Wert über pText: " << *pText << endl;

    return 0;
}
