#!/usr/bin/env python3

import sys
import os
import time

if __name__ == "__main__":
    pid = os.fork()

    if pid < 0:
        print("Fork failed")
        sys.exit(-1)
    elif pid == 0:
        print("begin child")
        print("end child")
        sys.exit(0) # Wichtig! Mit os._exit(0) führt Zombie-Prozess-Erzeugung nicht (wird verhindert)
    else:
        print("begin parent")
        time.sleep(3)
        print("Parent continues after sleep ...")
        print("end parent")
        sys.exit(0)
    

