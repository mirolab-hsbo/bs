#include <iostream>
using namespace std;

class Rechteck {
private:
    int breite;
    int hoehe;

public:
    Rechteck(int b, int h) : breite(b), hoehe(h) {}

    int flaeche() {
        return breite * hoehe;
    }
};

int main() {
    Rechteck r(4, 5);
    cout << "Fläche: " << r.flaeche() << endl;
    return 0;
}
