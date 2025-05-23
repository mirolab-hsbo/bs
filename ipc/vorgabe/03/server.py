#!/usr/bin/env python3

import socket

HOST = '127.0.0.1'
PORT = 22222

if __name__ == '__main__':

    # Socket öffnen: AF_INET wird für eine Kombi aus IP und Port benötigt
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Socket an IP und Port binden und lauschen
        s.bind((HOST, PORT))
        s.listen()
        print(f"Server listening on {HOST}:{PORT} ...")
        # Socket nimmt Verbindung entgegen
        conn, addr = s.accept()
        with conn:
            print(f"Got hit by client")
            while True:
                # Socket nimmt Nachricht von Client entgegen
                data = conn.recv(1024)
                if not data:
                    break
                # Nachricht dekodieren und anzeigen
                print("Received:", data.decode())
                # Nachricht zurück an Client senden
                conn.sendall(data) 
