#include <iostream>
#include <sys/stat.h>  // mkfifo
#include <fcntl.h>     // open
#include <unistd.h>    // read, close
#include <cstring>     // strlen

int main() {
    // Named Pipe öffnen
    const char* fifo_path = "/tmp/my_pipe";
    int fd = open(fifo_path, O_RDONLY); // Read Only

    // aus Named Pipe lesen und Nachricht ausgeben
    char buffer[128];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);

    buffer[bytesRead] = '\0'; // String terminieren
    std::cout << "Nachricht empfangen: " << buffer << std::endl;

    close(fd);
    return 0;
}
