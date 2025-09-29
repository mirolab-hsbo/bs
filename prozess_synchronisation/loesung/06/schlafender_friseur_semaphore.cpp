#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

class Semaphore
{
    mutex mtx;
    condition_variable cv;
    int count;

public:
    Semaphore(int c) : count(c) {}

    void acquire()
    {
        unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]
                { return count > 0; }); // warten, bis verfügbar
        --count;
    }

    void release()
    {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }
};

// startet bei 0, da noch kein Kunde bei Ladenöffnung anwesend
Semaphore sem(0);

void barber()
{
    this_thread::sleep_for(chrono::milliseconds(200));
    while (true)
    {
        cout << "[Friseur] schneidet Haare ..." << endl;
        sem.acquire();
    }
}

void customer(int counter)
{
    cout << "\t[Kunde #" << counter << "] betritt den Saloon." << endl;
    cout << "\t[Kunde #" << counter << "] informiert den Friseur." << endl;
    sem.release();
}

int main()
{
    thread barber_thread(barber);

    for (int i = 0; i < 10; i++)
    {
        thread customer_thread(customer, i + 1);
        customer_thread.join();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    barber_thread.detach();

    return 0;
}
