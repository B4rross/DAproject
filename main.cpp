#include <iostream>
#include "CPheadquarters.h"

using namespace std;
int main() {
    CPheadquarters CP;
    CP.read_files();
    Graph graph = CP.getLines();
    graph.print();

    // tests stations: Lapa, Faria
    // Mafra, Amieira
    // "Morgado", "Arronches"
    // "Bombel","Portalegre"
    // "Morgado","Portalegre"
    // "Morgado","Cuba"
    string source = "Morgado";
    string sink = "Gata";
    int maxFlow = graph.edmondsKarp(source, sink);
    if(maxFlow == 0){
        cerr << "Stations are not connected. Try " << sink << " -> " << source << " instead" << endl;
    } else {
        cout << "maxFlow:\t" << maxFlow << endl;
    }

    return 1;
}
