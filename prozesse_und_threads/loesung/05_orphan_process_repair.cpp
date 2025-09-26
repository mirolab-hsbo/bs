#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        cout << "begin child" << endl;
        sleep(3);
        cout << "PID: " << getpid() << " PPID: " << getppid() << " (parent)" << endl;
        sleep(3);
        cout << "end child" << endl;
    }
    else if (pid > 0)
    {
        int status;
        cout << "PID: " << getpid() << " PPID: " << getppid() << " (child)" << endl;
        cout << "Not waiting for my child!" << endl;
        wait(&status);
    }
    else
    {
        cout << "Fork failed!" << endl;
        return -1;
    }
    return 0;
}