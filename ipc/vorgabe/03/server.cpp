#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char str[100];
    int listener, connection;
 
    struct sockaddr_in serverAddress;
 
    // Socket öffnen: AF_INET wird für eine Kombi aus IP(v4) und (TCP-)Port benötigt
    listener = socket(AF_INET, SOCK_STREAM, 0);
 
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htons(INADDR_ANY); // auf alle verfügbaren Netzwerkinterfaces lauschen
    serverAddress.sin_port = htons(22222); // Festlegung des Ports
 
    // Socket an IP und Port binden und lauschen
    bind(listener, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    listen(listener, 10);

    // Abruf der IP-Adresse, auf der der Server lauscht
    char* ip = inet_ntoa(serverAddress.sin_addr);
    std::cout << "Server listening on " << ip << std::endl;

    // Socket nimmt Verbindung entgegen
    connection = accept(listener, (struct sockaddr*) NULL, NULL);
 
    while(1)
    {
        std::cout << "Got hit by client" << std::endl;
        // Puffer mit Nullen überschreiben
        bzero( str, 100);
 
        // Socket nimmt Nachricht von Client entgegen
        read(connection,str,100);
 
        std::cout << "Echoing: " << str << std::endl;
 
        // Socket schreibt Nachricht an Client
        write(connection, str, strlen(str)+1);
    }
}
