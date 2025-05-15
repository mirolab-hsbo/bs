#!/usr/bin/env python3

import sys
import signal
import time

def signal_handler(sig, frame):
    if sig == signal.SIGINT:
        print('\nYou pressed Ctrl+C!')
        sys.exit(0)

if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    for i in range(0,10):
        print("Started complex calculation ...")
        time.sleep(3)
