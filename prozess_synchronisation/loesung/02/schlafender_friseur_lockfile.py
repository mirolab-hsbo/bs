import threading
import time
import os

FILENAME = "friseur.lock"
waiting_room_counter = 0

barber_sleep = False

def create_lockfile():
    while True:
        if not os.path.exists(FILENAME):
            with open(FILENAME, "w") as outfile:
                pass
            break 
        # else: es wird gewartet (Ausführung blockiert), bis Lockfile frei ist

def remove_lockfile():
    os.remove(FILENAME)

def barber():
    global waiting_room_counter
    global barber_sleep
    time.sleep(0.2) # initiale Verzögerung (öffnet den Laden)
    while True:
        if not barber_sleep:
            if waiting_room_counter > 0:
                waiting_room_counter -= 1
                print("[Friseur] schneidet Haare ...")
            create_lockfile()
            if waiting_room_counter == 0:
                print("[Friseur] geht schlafen ...")
                time.sleep(1) # Interrupt emulieren
                barber_sleep = True 
            remove_lockfile()
    

def customer(counter):
    global waiting_room_counter
    global barber_sleep
    print(f"\t[Kunde #{counter}] betritt den Saloon.")
    waiting_room_counter += 1
    if waiting_room_counter == 1:
        print(f"\t[Kunde #{counter}] weckt Friseur auf.")
        create_lockfile()
        barber_sleep = False
        remove_lockfile()

# Threads starten
threading.Thread(target=barber).start()
for i in range(10):
    threading.Thread(target=customer, args=(i+1,)).start()
    time.sleep(0.5)

