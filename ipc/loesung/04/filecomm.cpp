#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file_stream;
    string line;
    string filename = "shared_file.txt";

    char choice;

    while (choice != 'q'){
        cout << "Want do you want to do?" << endl;
        cout << "w) Write to file" << endl;
        cout << "r) Read from file" << endl;
        cout << "q) Quit" << endl;
        cin >> choice;
        if (choice == 'w'){
            file_stream.open(filename, fstream::out);
            cout << "Please enter a message: ";
            cin.ignore();
            getline(cin, line);
            file_stream << line << "\n";
            file_stream.close();
        }
        if (choice == 'r'){
            file_stream.open(filename);
            while(getline(file_stream, line)){
                cout << line << endl;
            }
            file_stream.close();
        }
    }

	return 0;
}
