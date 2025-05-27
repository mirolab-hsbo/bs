import threading
import time

waiting_room_counter = 0

barber_sleep = False

lock = threading.Lock()

def barber():
    global waiting_room_counter
    global barber_sleep
    time.sleep(0.2) # initiale Verzögerung (öffnet den Laden)
    while True:
        if not barber_sleep:
            if waiting_room_counter > 0:
                waiting_room_counter -= 1
                print("[Friseur] schneidet Haare ...")
            lock.acquire()
            if waiting_room_counter == 0:
                print("[Friseur] geht schlafen ...")
                time.sleep(1) # Interrupt emulieren
                barber_sleep = True 
            lock.release()
    

def customer(counter):
    global waiting_room_counter
    global barber_sleep
    print(f"\t[Kunde #{counter}] betritt den Saloon.")
    waiting_room_counter += 1
    if waiting_room_counter == 1:
        print(f"\t[Kunde #{counter}] weckt Friseur auf.")
        lock.acquire()
        barber_sleep = False
        lock.release()

# Threads starten
threading.Thread(target=barber).start()
for i in range(10):
    threading.Thread(target=customer, args=(i+1,)).start()
    time.sleep(0.5)

