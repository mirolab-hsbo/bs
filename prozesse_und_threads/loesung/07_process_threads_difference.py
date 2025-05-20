import threading
import multiprocessing

N = 2
sum = 0

def dummy_task(name):
    print(f"Start {name}")
    global sum
    for _ in range(10):
        sum += 1
        print(f"{name}:", sum)
    print(f"End {name}")

if __name__ == '__main__':
    threads = [threading.Thread(target=dummy_task, args=(f"Thread-{i+1}",)) for i in range(N)]
    for t in threads: t.start()
    for t in threads: t.join()

    sum = 0

    processes = [multiprocessing.Process(target=dummy_task, args=(f"Process-{i+1}",)) for i in range(N)]
    for p in processes: p.start()
    for p in processes: p.join()