#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

int waiting_room_counter = 0;
bool barber_sleep = false;

void barber() {
    // initiale Verzögerung (öffnet den Laden)
    this_thread::sleep_for(chrono::milliseconds(200));

    while (true) {
        if (!barber_sleep) {
            if (waiting_room_counter > 0) {
                waiting_room_counter--;
                cout << "[Friseur] schneidet Haare ..." << endl;
            }
            if (waiting_room_counter == 0) {
                cout << "[Friseur] geht schlafen ..." << endl;
                this_thread::sleep_for(chrono::seconds(1)); // Interrupt emulieren
                barber_sleep = true;
            }
        }
    }
}

void customer(int counter) {
    cout << "\t[Kunde #" << counter << "] betritt den Salon." << endl;
    waiting_room_counter++;
    if (waiting_room_counter == 1) {
        cout << "\t[Kunde #" << counter << "] weckt Friseur auf." << endl;
        barber_sleep = false;
    }
}

int main() {
    thread barber_thread(barber);

    for (int i = 0; i < 10; i++) {
        thread customer_thread(customer, i+1);
        customer_thread.join();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    // (Endlosschleife Friseur -> im echten Fall Signal/Beenden nötig)
    barber_thread.detach();

    return 0;
}
