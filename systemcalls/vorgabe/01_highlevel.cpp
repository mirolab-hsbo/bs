#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Datei erzeugen und öffnen
    ofstream BeispielDatei("beispiel.txt");

    // in die Datei schreiben
    BeispielDatei << "Hallo, Betriebssystem!" << endl;

    // Datei schließen
    BeispielDatei.close();
}