#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    int limit = 100;
    int counter = 0;
    pid_t pid = fork();

    if (pid == 0)
    {
        cout << "begin" << endl; // TODO: child or parent?
        for (int i = 0; i < limit; i++)
        {
            // TODO: child or parent?
        }
        cout << "end" << endl; // TODO: child or parent?
    }
    else if (pid > 0)
    {
        cout << "begin parent" << endl; // TODO: child or parent?
        for (int j = 0; j < limit; j++)
        {
            // TODO: child or parent?
        }
        cout << "end" << endl; // TODO: child or parent?
    }
    else
    {
        cout << "Fork failed!" << endl;
        return -1;
    }
    return 0;
}