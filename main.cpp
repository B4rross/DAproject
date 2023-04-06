#include <iostream>
#include "CPheadquarters.h"

using namespace std;
int main() {
    CPheadquarters CP;
    CP.read_files();

    int n;
    do {
        std::cout << "T2.1 - Max number of trains between stations\n";
        std::cout << "T2.2 - Stations that require the Max num of trains among all pairs of stations\n";
        std::cout << "T2.3 -\n";
        std::cout << "T2.4 -\n";
        std::cout << "T3.1 -\n";
        std::cout << "T4.1 -\n";
        std::cout << "T4.2 -\n";
        std::cout << "Insert your option:\n";
        std::cin >> n;

        switch (n) {
            case 1: {
                std::cin.ignore(); // ignore newline character left in the input stream
                std::string a, b;
                std::cout << "Enter station A: ";
                std::getline(std::cin, a);

                std::cout << "Enter station B: ";
                std::getline(std::cin, b);

                if (a.empty() || b.empty()) {
                    std::cerr << "Error: Station names cannot be empty." << std::endl;
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
                std::cout << "Exiting program..." << std::endl;
                break;
            }

            default: {
                std::cerr << "Error: Invalid option selected." << std::endl;
                break;
            }
        }
    } while (n != 8);

}