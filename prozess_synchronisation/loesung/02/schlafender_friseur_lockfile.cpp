#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <unistd.h>  // für access()
#include <cstdio>    // für remove()

using namespace std;

const string FILENAME = "friseur.lock";
int waiting_room_counter = 0;
bool barber_sleep = false;

void create_lockfile() {
    while (true) {
        // prüfen, ob Lockfile existiert
        if (access(FILENAME.c_str(), F_OK) != 0) {
            ofstream outfile(FILENAME);
            outfile.close();
            break;
        }
        // sonst: warten (Ausführung blockiert), bis Lockfile frei ist
    }
}

void remove_lockfile() {
    remove(FILENAME.c_str());
}

void barber() {
    this_thread::sleep_for(chrono::milliseconds(200));
    while (true) {
        if (!barber_sleep) {
            if (waiting_room_counter > 0) {
                waiting_room_counter--;
                cout << "[Friseur] schneidet Haare ..." << endl;
            }
            create_lockfile();
            if (waiting_room_counter == 0) {
                cout << "[Friseur] geht schlafen ..." << endl;
                this_thread::sleep_for(chrono::seconds(1)); // Interrupt emulieren
                barber_sleep = true;
            }
            remove_lockfile();
        }
    }
}

void customer(int counter) {
    cout << "\t[Kunde #" << counter << "] betritt den Saloon." << endl;
    waiting_room_counter++;
    if (waiting_room_counter == 1) {
        cout << "\t[Kunde #" << counter << "] weckt Friseur auf." << endl;
        create_lockfile();
        barber_sleep = false;
        remove_lockfile();
    }
}

int main() {
    thread barber_thread(barber);

    for (int i = 0; i < 10; i++) {
        thread customer_thread(customer, i+1);
        customer_thread.join();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    barber_thread.detach();

    return 0;
}
