#!/usr/bin/env python3

import os

if __name__ == '__main__':

    fifo_path = '/tmp/my_pipe'

    # Named Pipe anlegen (einmalig)
    if not os.path.exists(fifo_path):
        os.mkfifo(fifo_path)

    with open(fifo_path, 'w') as fifo:
        # blockiert, bis Pipe durch lesenden Prozess geöffnet wird
        fifo.write("Daten des schreibenden Prozesses.\n")

