//
// Created by Pedro on 23/03/2023.
//

#include <fstream>
#include <sstream>
#include "CPheadquarters.h"

using namespace std;

void CPheadquarters::read_files() {
    ifstream inputFile1;
    ifstream inputFile2;
    inputFile1.open(R"(../network.csv)");
    inputFile2.open(R"(../stations.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string station_A;
        string station_B;
        string temp;
        int capacity;
        string service;

        stringstream inputString(line1);

        getline(inputString, station_A, ';');
        getline(inputString, station_B, ';');
        getline(inputString, temp, ';');
        capacity=stoi(temp);
        getline(inputString, service, ';');

        lines.addVertex(station_A);
        lines.addVertex(station_B);
        lines.addEdge(station_A,station_B,capacity,service);

        line1 = "";
    }

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile2, line1)) {
        string nome;
        string distrito;
        string municipality;
        string township;
        string line;

        stringstream inputString(line1);

        getline(inputString, nome, ',');
        getline(inputString, distrito, ',');
        getline(inputString, municipality, ',');
        getline(inputString, township, ',');
        getline(inputString, line, ',');

        Station station(nome,distrito,municipality,township,line);
        stations[nome]=station;

        line1 = "";
    }

}

Graph CPheadquarters::getLines() const {
    return this->lines;
}

/*
 * Calculate the maximum number of trains that can simultaneously travel between
 * two specific stations. Note that your implementation should take any valid source and destination
 * stations as input
 */
int CPheadquarters::T2_1maxflow(string stationA, string stationB) {
    Vertex* source = lines.findVertex(stationA); // set source vertex
    Vertex* sink = lines.findVertex(stationB); // set sink vertex

    // Check if these stations even exist
    if(source == nullptr || sink == nullptr) {
        std::cerr << "Source or sink vertex not found." << std::endl;
        return 1;
    }
    int maxFlow = lines.edmondsKarp(stationA, stationB);

    if(maxFlow == 0){
        cerr << "Stations are not connected. Try stationB to stationA instead. " << stationB << " -> " << stationA << endl;
    } else {
        cout << "maxFlow:\t" << maxFlow << endl;
    }

    return 1;
}
void CPheadquarters::test(){
    int flow = lines.edmondsKarp(lines.getVertexSet()[324]->getId(), lines.getVertexSet()[507]->getId());
}


/*
 * Determine, from all pairs of stations, which ones (if more than one) require the
 * most amount of trains when taking full advantage of the existing network capacity;
 */
int CPheadquarters::T2_2maxflowAllStations() {
    vector<string> stations;
    int maxFlow=0;
    auto length = lines.getVertexSet().size();
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            string stationA = lines.getVertexSet()[i]->getId();
            string stationB = lines.getVertexSet()[j]->getId();
            if(stationA=="Trofa" && stationB=="Espinho"){
                cout<<"stop";
            }
            int flow = lines.edmondsKarp(stationA, stationB);
            cout <<"edmunddone"<< '\n';
            if(flow == maxFlow){
                stations.push_back(stationB);
                stations.push_back(stationA);
            }
            else if(flow > maxFlow){
                stations.clear();
                stations.push_back(stationB);
                stations.push_back(stationA);
                maxFlow=flow;
            }
        }
    }
    cout<<"Pairs of stations with the most flow ["<<maxFlow<<"]:\n";
    for (int i = 0; i < stations.size(); i=i+2) {
        cout<<"------------------------\n";
        cout<<"Source:"<<stations[i+1]<<'\n';
        cout<<"Target:"<<stations[i]<<'\n';
        cout<<"------------------------\n";
    }
    return 0;
}

/*
 * Report the maximum number of trains that can simultaneously arrive at a given station,
 * taking into consideration the entire railway grid
 */
int CPheadquarters::T2_4maxArrive(string destination) {
    Vertex * dest = lines.findVertex(destination);
    int maxFlow = 0;

    // iterate over all vertices to find incoming and outgoing vertices
    for (auto & v : lines.getVertexSet()) {
        if(v != dest){

            int flow = lines.edmondsKarp(v->getId(), destination);

            // Update the maximum flow if this vertex contributes to a higher maximum
            if (flow > maxFlow) {
                maxFlow = flow;
            }
        }
    }

    cout << "Max number of trains that can simultaneously arrive at " << destination << ": " << maxFlow << endl;
    return maxFlow;
}
