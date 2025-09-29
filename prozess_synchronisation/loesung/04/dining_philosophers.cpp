#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

const int N = 5;        // Anzahl der Philosophen
vector<mutex> forks(N); // jede Gabel ist ein Mutex

// Zufallszahlengenerator für Wartezeiten
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> think_time(0.5, 1.5);
uniform_real_distribution<> eat_time(0.5, 1.0);

void philosopher(int philosopher_id)
{
    while (true)
    {
        cout << "Philosoph " << philosopher_id << " denkt..." << endl;
        this_thread::sleep_for(chrono::duration<double>(think_time(gen)));
        cout << "Philosoph " << philosopher_id << " versucht zu essen..." << endl;

        // Gabeln aufnehmen
        mutex &left = forks[philosopher_id-1];
        mutex &right = forks[(philosopher_id) % N];

        left.lock();
        cout << "Philosoph " << philosopher_id << " nimmt erste Gabel auf ..." << endl;
        this_thread::sleep_for(chrono::seconds(1)); // NEU!
        right.lock();

        // Essen
        cout << "\tPhilosoph " << philosopher_id << " isst." << endl;
        this_thread::sleep_for(chrono::duration<double>(eat_time(gen)));

        // Gabeln zurücklegen
        right.unlock();
        left.unlock();
        cout << "Philosoph " << philosopher_id << " legt die Gabeln weg." << endl;
    }
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        thread philosopher_thread(philosopher, i + 1);
        // nur der letzte Thread wird "behalten"; sonst laufen Threads Scheduling-bedingt nicht gleichzeitig, sondern nur der erste Thread
        if (i < 4)
        {
            philosopher_thread.detach();
        }
        else
        {
            philosopher_thread.join();
        }
    }

    return 0;
}
