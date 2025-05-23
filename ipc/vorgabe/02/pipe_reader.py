#!/usr/bin/env python3

if __name__ == '__main__':

    fifo_path = '/tmp/my_pipe'

    with open(fifo_path, 'r') as fifo:
        print("Nachricht empfangen:", fifo.read())
