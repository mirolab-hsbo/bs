#include <sys/stat.h>  // mkfifo
#include <fcntl.h>     // open
#include <unistd.h>    // write, close
#include <cstring>     // strlen

int main()
{
    // Named Pipe anlegen und öffnen
    const char *fifo_path = "/tmp/my_pipe";
    mkfifo(fifo_path, 0666);
    int fd = open(fifo_path, O_WRONLY); // Write Only

    // Nachricht in Named Pipe schreiben
    const char *message = "Daten des schreibenden Prozesses.\n";
    write(fd, message, strlen(message));

    close(fd);
    return 0;
}
