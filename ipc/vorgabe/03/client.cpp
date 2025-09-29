#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd;
    char sendText[100];
    char recieveText[100];
    struct sockaddr_in serverAddress;

    // Socket öffnen; s. Bemerkungen beim Server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(22222);

    // Umwandlung der IP-Adresse in binäre Form (für Server-Adresse; Gegenoperation für inet_ntoa)
    inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr));

    // auf den Socket verbinden
    connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1)
    {
        // Puffer mit Nullen überschreiben
        bzero(sendText, 100);
        bzero(recieveText, 100);

        // Nachrichtenzeile von Terminaleingabe lesen
        std::cout << "client: ";
        std::string input;
        std::getline(std::cin, input);
        strncpy(sendText, input.c_str(), sizeof(sendText));

        // Nachricht über Socket senden
        write(sockfd, sendText, strlen(sendText) + 1);

        // Nachricht über Socket erhalten und ausgeben
        read(sockfd, recieveText, 100);
        std::cout << "server: " << recieveText << std::endl;
    }
}
