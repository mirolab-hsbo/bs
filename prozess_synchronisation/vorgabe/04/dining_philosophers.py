import threading
import time
import random

N = 5  # Anzahl der Philosophen

# Jeder Philosoph hat eine linke und rechte Gabel (Lock)
forks = [threading.Lock() for _ in range(N)]

def philosopher(philosopher_id):

    while True:
        print(f"Philosoph {philosopher_id} denkt...")
        time.sleep(random.uniform(0.5, 1.5))

        print(f"Philosoph {philosopher_id} versucht zu essen...")

        left = forks[philosopher_id]
        left.acquire()
        print(f"Philosoph {philosopher_id} nimmt erste Gabel auf ...")       
        right = forks[(philosopher_id + 1) % N]
        right.acquire()
        print(f"\tPhilosoph {philosopher_id} isst.")
        time.sleep(random.uniform(0.5, 1.0))
        right.release()
        left.release()
        print(f"Philosoph {philosopher_id} legt die Gabeln weg.")

# Starte alle Philosophen-Threads
for i in range(N):
    threading.Thread(target=philosopher, args=(i,)).start()
