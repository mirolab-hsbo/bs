#!/usr/bin/env python3

import sys
import os
import time

if __name__ == "__main__":
    limit = 100
    pid = os.fork()

    if pid < 0:
        print("Fork failed")
        sys.exit(-1)
    elif pid == 0:
        print("begin child")
        time.sleep(3)
        print("PID:", os.getpid(), "PPID:", os.getppid(), "(child)")
        time.sleep(3)
        print("end child")
        os._exit(0)
    else:
        print("begin parent")
        print("PID:", os.getpid(), "PPID:", os.getppid(), "(parent)")
        print("Waiting for child process ...")
        os.wait()
        print("end parent")
        sys.exit(0)
    

