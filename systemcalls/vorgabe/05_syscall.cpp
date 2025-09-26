#include <iostream>
#include <unistd.h>      // STDOUT_FILENO
#include <sys/syscall.h> // SYS_open, SYS_write, SYS_close
#include <fcntl.h>       // Flags O_WRONLY, O_CREAT
#include <string.h>      // strlen

int main()
{
    const char *filename = "beispiel.txt";
    const char *msg = "Hallo, Betriebssystem!\n";

    long fd = syscall(SYS_open, ); //TODO

    long written = syscall(SYS_write, ); //TODO

    syscall(SYS_close, ); //TODO

    return 0;
}
