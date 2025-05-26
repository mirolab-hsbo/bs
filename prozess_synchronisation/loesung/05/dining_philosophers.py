import threading
import time
import random

N = 5  # Anzahl der Philosophen

# Jeder Philosoph hat eine linke und rechte Gabel (Lock)
forks = [threading.Lock() for _ in range(N)]

def philosopher(philosopher_id):
    left = forks[philosopher_id]
    right = forks[(philosopher_id + 1) % N]

    while True:
        print(f"Philosoph {philosopher_id} denkt...")
        time.sleep(random.uniform(0.5, 1.5))

        # Deadlock vermeiden durch asymmetrisches Greifen
        first, second = (left, right) if philosopher_id % 2 == 0 else (right, left)

        print(f"Philosoph {philosopher_id} versucht zu essen...")
        with first:
            with second:
                print(f"🍝 Philosoph {philosopher_id} isst.")
                time.sleep(random.uniform(0.5, 1.0))
        print(f"Philosoph {philosopher_id} legt die Gabeln weg.")

# Starte alle Philosophen-Threads
for i in range(N):
    threading.Thread(target=philosopher, args=(i,), daemon=True).start()

# Hauptthread läuft, damit die Philosophen nicht enden
time.sleep(15)
