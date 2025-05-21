import threading
import multiprocessing

N = 2
counter = 0

def dummy_task(name):
    print(f"Start {name}")
    global counter
    for _ in range(10):
        counter += 1
        print(f"{name}:", counter)
    print(f"End {name}")

if __name__ == '__main__':
    threads = [threading.Thread(target=dummy_task, args=(f"Thread-{i+1}",)) for i in range(N)]
    for t in threads: t.start()
    for t in threads: t.join()

    counter = 0

    processes = [multiprocessing.Process(target=dummy_task, args=(f"Process-{i+1}",)) for i in range(N)]
    for p in processes: p.start()
    for p in processes: p.join()