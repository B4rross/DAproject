#include <iostream>
#include "CPheadquarters.h"

using namespace std;

int main() {
    CPheadquarters CP;
    CP.read_files();
    int n;
    do {
        cout << "1 - T2.1 Max number of trains between stations\n";
        cout << "2 - T2.2 Stations that require the Max num of trains among all pairs of stations\n";
        cout << "3 - T2.3\n";
        cout << "4 - T2.4 Max number of trains that can simultaneously arrive at a given station\n";
        cout << "5 - T3.1\n";
        cout << "6 - T4.1\n";
        cout << "7 - T4.2\n";
        cout << "8 - Exit\n";


        bool validInput = false;

        while (!validInput) {
            cout << "Insert your option:\n";
            cin >> n;

            if (cin.fail() || n < 1 || n > 8) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            } else {
                validInput = true;
            }
        }

        switch (n) {
            case 1: {
                cin.ignore(); // ignore newline character left in the input stream
                string a, b;
                cout << "Enter station A: ";
                getline(cin, a);

                cout << "Enter station B: ";
                getline(cin, b);

                if (a.empty() || b.empty()) {
                    cerr << "Error: Station names cannot be empty." << endl;
                    break;
                }

                // call function to calculate max flow between stations A and B
                CP.T2_1maxflow(a, b);
                break;
            }

            case 2: {
                CP.T2_2maxflowAllStations();
                break;
            }

            case 3: {
                CP.test();
                break;
            }

            case 4: {
                cin.ignore();
                string destination;
                cout << "Enter destination: ";
                getline(cin, destination);
                CP.T2_4maxArrive(destination);
                break;
            }

            case 5: {
                CP.T3_1MinCost("Morgado","Cuba");
                break;
            }

            case 6: {

                break;
            }

            case 7: {

                break;
            }

            case 8: {
                cout << "Exiting program..." << endl;
                break;
            }

            default: {
                cerr << "Error: Invalid option selected." << endl;
                break;
            }
        }
    } while (n != 8);

    return 0;
}