#include <iostream>
#include "CPheadquarters.h"

using namespace std;

int main() {
    CPheadquarters CP;
    CP.read_files();

    int n;
    do {
        cout << "T2.1 - Max number of trains between stations\n";
        cout << "T2.2 - Stations that require the Max num of trains among all pairs of stations\n";
        cout << "T2.3 -\n";
        cout << "T2.4 -\n";
        cout << "T3.1 -\n";
        cout << "T4.1 -\n";
        cout << "T4.2 -\n";
        cout << "Insert your option:\n";
        cin >> n;

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

                break;
            }

            case 5: {

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