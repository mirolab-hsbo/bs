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
        print("begin child")
        for i in range(0, limit):
            print("Child:", i)
        print("end child")
        os._exit(0)
    else:
        print("begin parent")
        for j in range(0, limit):
            print("Parent:", j)
        print("end parent")
        sys.exit(0)
        
