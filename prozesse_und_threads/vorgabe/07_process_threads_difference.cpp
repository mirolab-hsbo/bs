#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

int counter = 0;

void dummy_task(const std::string &name)
{
    std::cout << "Start " << name << std::endl;
    for (int i = 0; i < 10; i++)
    {
        counter += 1;
        std::cout << name << ": " << counter << std::endl;
    }
    std::cout << "End " << name << std::endl;
}

int main()
{
    std::thread thread1(dummy_task, "Thread-1");
    std::thread thread2(dummy_task, "Thread-2");
    thread1.join();
    thread2.join();

    counter = 0;

    pid_t pid = fork();
    if (pid == 0)
    {
        // Kindprozess
        dummy_task("Process-2");
    }
    else if (pid > 1)
    {
        dummy_task("Process-1");
        int status;
        wait(&status);
    }

    return 0;
}
