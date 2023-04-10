#include <iostream>
#include "CPheadquarters.h"

using namespace std;

int main() {
    CPheadquarters CP;
    CP.read_files();
    CP.getLines().print();
    int n;
    cout << "\n-------------- An Analysis Tool for Railway Network Management --------------\n" << endl;
    do {
        cout << "1 - T2.1 Max number of trains between stations\n";
        cout << "2 - T2.2 Stations that require the Max num of trains among all pairs of stations\n";
        cout << "3 - T2.3 Indicate where management should assign larger budgets for the purchasing and maintenance of trains\n";
        cout << "4 - T2.4 Max number of trains that can simultaneously arrive at a given station\n";
        cout << "5 - T3.1 Max number of trains that can simultaneously travel with minimum cost\n";
        cout << "6 - T4.1 Max number of trains between stations in a network of reduced connectivity\n";
        cout << "7 - T4.2 Top-10 most affectd stations in a network of reduced connectivity\n";
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
                cin.ignore();
                string c;
                cout << "Enter municipality: " << endl;
                cout << "For example, PENAFIEL: ";
                getline(cin, c);
                cout << "The maximum flow in Municipality " << c << " is " << CP.T2_3municipality(c) << endl;
                cout << endl;
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
                cin.ignore();
                string a, b;
                cout << R"(Example: "Entroncamento" "Lisboa Oriente")" << endl;
                cout << "Enter station A: ";
                getline(cin, a);
                cout << endl;
                cout << "Enter station B: ";
                getline(cin, b);

                if (a.empty() || b.empty()) {
                    cerr << "Error: Station names cannot be empty." << endl;
                    break;
                }

                CP.T3_1MinCost(a, b);
                break;
            }

            case 6: {
                cin.ignore();
                vector<string> unwantedEdges;
                string edgesource;
                string edgetarget;
                string b;
                string a;
                cout << "Enter station A: ";
                getline(cin, a);
                cout << "Enter station B: ";
                getline(cin, b);
                cout << '\n';
                cout << "List unwanted edges. Start by typing the edge source an then the edge destine. Type '.' to end listing: \n";
                while (1){
                    cout << "Enter edge source or '.' to finish: ";
                    getline(cin, edgesource);
                    if(edgesource==".") break;
                    unwantedEdges.push_back(edgesource);
                    cout << "Enter edge target: ";
                    getline(cin, edgetarget);
                    unwantedEdges.push_back(edgetarget);
                }
                CP.T4_1ReducedConectivity(unwantedEdges,a,b);
                break;
            }

            case 7: {
                cin.ignore();
                vector<string> unwantedEdges;
                string edgesource;
                string edgetarget;
                cout << "List unwanted edges. Start by typing the edge source an then the edge destine. Type '.' to end listing: \n";
                while (1){
                    cout << "Enter edge source or '.' to finish: ";
                    getline(cin, edgesource);
                    if(edgesource==".") break;
                    unwantedEdges.push_back(edgesource);
                    cout << "Enter edge target: ";
                    getline(cin, edgetarget);
                    unwantedEdges.push_back(edgetarget);
                }
                CP.T4_2Top_K_ReducedConectivity(unwantedEdges);

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