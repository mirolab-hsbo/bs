#include <iostream>
#include <unistd.h> // write, close
#include <fcntl.h>  // open
#include <cstring>  // strlen

int main()
{
    // Flags: O_CREAT (create if not exist), O_WRONLY (write only)
    int fd = open("beispiel.txt", O_WRONLY | O_CREAT, 0644);

    const char *text = "Hallo, Betriebssystem!\n";

    // write schreibt Bytes!
    ssize_t written = write(fd, text, strlen(text));

    close(fd);

    return 0;
}