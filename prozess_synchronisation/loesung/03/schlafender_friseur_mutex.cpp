#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <mutex>

using namespace std;

std::mutex mtx;
int waiting_room_counter = 0;
bool barber_sleep = false;

void barber()
{
    this_thread::sleep_for(chrono::milliseconds(200));
    while (true)
    {
        if (!barber_sleep)
        {
            if (waiting_room_counter > 0)
            {
                waiting_room_counter--;
                cout << "[Friseur] schneidet Haare ..." << endl;
            }
            mtx.lock();
            if (waiting_room_counter == 0)
            {
                cout << "[Friseur] geht schlafen ..." << endl;
                this_thread::sleep_for(chrono::seconds(1)); // Interrupt emulieren
                barber_sleep = true;
            }
            mtx.unlock();
        }
    }
}

void customer(int counter)
{
    cout << "\t[Kunde #" << counter << "] betritt den Saloon." << endl;
    waiting_room_counter++;
    if (waiting_room_counter == 1)
    {
        cout << "\t[Kunde #" << counter << "] weckt Friseur auf." << endl;
        mtx.lock();
        barber_sleep = false;
        mtx.unlock();
    }
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
