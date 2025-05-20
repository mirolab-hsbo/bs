#!/usr/bin/env python3

import os

if __name__ == "__main__":
    print("Das ist der Beginn vom Prozess.")
    try:
        os.execl("/bin/ls1", "-la", "./")
    except FileNotFoundError:
        print("Kommando konnte nicht gefunden werden!")

    print("Zwischenausgabe zur Kontrolle.")
    os.execl("/bin/ls", "-la", "./ordern-existiert-nicht")
    print("Das ist der Rest vom Prozess.")


