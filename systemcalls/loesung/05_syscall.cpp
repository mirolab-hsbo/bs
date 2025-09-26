#include <iostream>
#include <unistd.h>      // STDOUT_FILENO
#include <sys/syscall.h> // SYS_open, SYS_write, SYS_close
#include <fcntl.h>       // Flags O_WRONLY, O_CREAT
#include <string.h>      // strlen

int main()
{
    const char *filename = "beispiel.txt";
    const char *msg = "Hallo, Betriebssystem!\n";

    long fd = syscall(SYS_open, filename, O_WRONLY | O_CREAT, 0644);

    long written = syscall(SYS_write, fd, msg, strlen(msg));

    syscall(SYS_close, fd);

    return 0;
}
