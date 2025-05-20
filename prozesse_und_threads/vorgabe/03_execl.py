#!/usr/bin/env python3

import os

if __name__ == "__main__":
    print("Das ist der Beginn vom Prozess.")
    os.execl("/bin/ls", "-la", "./")
    print("Das ist der Rest vom Prozess.")
    