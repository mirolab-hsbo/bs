#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "Das ist der Beginn vom Prozess." << endl;
    execl("/bin/lsexistiertnicht", "-la", 0); // fehlerhafter Pfad
    cout << "Das ist der Rest vom Prozess." << endl;
    exit(0);
}