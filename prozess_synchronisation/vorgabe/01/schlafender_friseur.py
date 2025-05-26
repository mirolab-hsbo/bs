import threading
import time

waiting_room_counter = 0

barber_sleep = False

def barber():
    global waiting_room_counter
    global barber_sleep
    time.sleep(0.2) # initiale Verzögerung (öffnet den Laden)
    while True:
        if not barber_sleep:
            if waiting_room_counter > 0:
                waiting_room_counter -= 1
                print("[Friseur] schneidet Haare ...")
            if waiting_room_counter == 0:
                print("[Friseur] geht schlafen ...")
                barber_sleep = True 
    

def customer(counter):
    global waiting_room_counter
    global barber_sleep
    print(f"\t[Kunde #{counter}] betritt den Saloon.")
    waiting_room_counter += 1
    if waiting_room_counter == 1:
        print(f"\t[Kunde #{counter}] weckt Friseur auf.")
        barber_sleep = False

# Threads starten
threading.Thread(target=barber).start()
for i in range(10):
    threading.Thread(target=customer, args=(i+1,)).start()
    time.sleep(0.5)

