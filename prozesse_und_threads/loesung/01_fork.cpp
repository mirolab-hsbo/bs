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
        cout << "begin child" << endl;
        for (int i = 0; i < limit; i++)
        {
            cout << "Child: " << i << endl;
        }
        cout << "end child" << endl;
    }
    else if (pid > 0)
    {
        cout << "begin parent" << endl;
        for (int j = 0; j < limit; j++)
        {
            cout << "Parent: " << j << endl;
        }
        cout << "end parent" << endl;
    }
    else
    {
        cout << "Fork failed!" << endl;
        return -1;
    }
    return 0;
}