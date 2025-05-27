import threading
import time

# startet bei 0, da noch kein Kunde bei Ladenöffnung anwesend
semaphore = threading.Semaphore(0)

def barber():
    time.sleep(0.2) # initiale Verzögerung (öffnet den Laden)
    while True:
        semaphore.acquire()
        print("[Friseur] schneidet Haare ...")
    

def customer(counter):
    print(f"\t[Kunde #{counter}] betritt den Saloon.")
    print(f"\t[Kunde #{counter}] informiert Friseur.")
    semaphore.release()

# Threads starten
threading.Thread(target=barber).start()
for i in range(10):
    threading.Thread(target=customer, args=(i+1,)).start()
    time.sleep(0.5)

