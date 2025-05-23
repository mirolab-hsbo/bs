#!/usr/bin/env python3

import socket

HOST = '127.0.0.1'
PORT = 22222

if __name__ == '__main__':

    # Socket öffnen; s. Bemerkung beim Server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # auf den Socket verbinden
        s.connect((HOST, PORT))
        msg = input("Send message to server: ")
        # Nachricht über Socket versenden
        s.sendall(msg.encode())
        # Antwort vom Server erhalten (und danach ausgeben)
        data = s.recv(1024)

    print("Server:", data.decode())
