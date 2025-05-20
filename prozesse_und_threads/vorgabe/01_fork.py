#!/usr/bin/env python3

import sys
import os

if __name__ == "__main__":
    limit = 100
    pid = os.fork()
    if pid < 0:
        print("Fork failed")
        sys.exit(-1)
    elif pid == 0:
        print("begin") # TODO Info: Child oder Parent?
        for i in range(0, limit):
            pass # TODO Ausgabe: Eltern-oder Kindprozess mit counter
        print("end") # TODO Info: Child oder Parent?
        os._exit(0)
    else:
        print("begin") # TODO Info: Child oder Parent?
        for j in range(0, limit):
            pass # TODO Ausgabe: Eltern-oder Kindprozess mit counter
        print("end") # TODO Info: Child oder Parent?
        sys.exit(0)
        
