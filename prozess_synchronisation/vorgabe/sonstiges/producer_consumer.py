import threading
import time

buffer_counter = 0
MAX_SIZE = 5

producer_sleep = False
consumer_sleep = False

def producer():
    global buffer_counter
    global producer_sleep
    global consumer_sleep
    while True:
        if not producer_sleep:
            if buffer_counter == MAX_SIZE:
                producer_sleep = True
            else:
                buffer_counter += 1
                print(f"[Producer] Counter:", buffer_counter)
                time.sleep(0.2) # Zeit der Verarbeitung emulieren
                if buffer_counter == 1:
                    consumer_sleep = False

def consumer():
    global buffer_counter
    global producer_sleep
    global consumer_sleep
    while True:
        if not consumer_sleep:
            if buffer_counter == 0:
                time.sleep(2) # Interrupt emulieren
                consumer_sleep = True 
            else:            
                buffer_counter -= 1
                print(f"    [Consumer] Counter:", buffer_counter)
                time.sleep(0.2) # Zeit der Verarbeitung emulieren
                if buffer_counter == MAX_SIZE-1:
                    producer_sleep = False

# Threads starten
threading.Thread(target=producer).start()
threading.Thread(target=consumer).start()



