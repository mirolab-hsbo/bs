#!/usr/bin/env python3

import sys
import os

if __name__ == "__main__":
    limit = 100
    pid = os.fork()
    pid_2 = os.fork()

    if pid == 0:
        if pid_2 == 0:
            print("PID:", os.getpid(), "PPID:", os.getppid(), "(grandchild)")
        elif pid_2 > 0:
            print("PID:", os.getpid(), "PPID:", os.getppid(), "(child)")
        else:
            print("Subfork failed")
            os._exit(-1)
        os._exit(0)
    elif pid > 0:
        print("PID:", os.getpid(), "PPID:", os.getppid(), "(some parent)")
        sys.exit(-1)
    

