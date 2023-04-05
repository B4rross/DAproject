#include <iostream>
#include "CPheadquarters.h"

using namespace std;
int main() {
    CPheadquarters CP;
    CP.read_files();
    Graph graph = CP.getLines();
    graph.print();

    // tests stations that don't have Porguguese letters:
    // Lapa, Faria
    // Mafra, Amieira
    // "Morgado", "Arronches"
    // "Bombel","Portalegre"
    // "Morgado","Portalegre"
    // "Morgado","Cuba"
    // "Morgado" "Canha"
    string stationA = "Morgado";
    string stationB = "Canha";

    Vertex* source = graph.findVertex(stationA); // set source vertex
    Vertex* sink = graph.findVertex(stationB); // set sink vertex

    // Check if these stations even exist
    if(source == nullptr || sink == nullptr) {
        std::cerr << "Source or sink vertex not found." << std::endl;
        return 1;
    }


    int maxFlow = graph.edmondsKarp(stationA, stationB);

    if(maxFlow == 0){
        cerr << "Stations are not connected. Try stationB to stationA instead. " << stationB << " -> " << stationA << endl;
    } else {
        cout << "maxFlow:\t" << maxFlow << endl;
    }

    return 1;
}
