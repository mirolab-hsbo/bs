#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    pid_t pid = fork();
    pid_t pid_2 = fork();

    if (pid == 0)
    {
        if (pid_2 == 0)
        {
            cout << "PID: " << getpid() << " PPID: " << getppid() << " (grandchild)" << endl;
        }
        else if (pid_2 > 0)
        {
            cout << "PID: " << getpid() << " PPID: " << getppid() << " (child)" << endl;
        }
        else
        {
            cout << "Subork failed!" << endl;
            return -1;
        }
    }
    else if (pid > 0)
    {
        cout << "PID: " << getpid() << " PPID: " << getppid() << " (some parent)" << endl;
    }
    else
    {
        cout << "Fork failed!" << endl;
        return -1;
    }

    return 0;
}