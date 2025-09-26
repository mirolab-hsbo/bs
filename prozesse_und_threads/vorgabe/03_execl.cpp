#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "Das ist der Beginn vom Prozess." << endl;
    execl("/bin/ls", "-la", 0);
    cout << "Das ist der Rest vom Prozess." << endl;
    exit(0);
}