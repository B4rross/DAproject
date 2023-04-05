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

int CPheadquarters::T2_2maxflowAllStations() {
    // Get all possible flows
    vector<pair<pair<string, string>, int>> flows;
    auto length = lines.getVertexSet().size();
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (i != 324 && j != 507) {
                if (i != 501 && j != 506) {
                    string stationA = lines.getVertexSet()[i]->getId();
                    string stationB = lines.getVertexSet()[j]->getId();
                    int flow = lines.edmondsKarp(stationA, stationB);
                    flows.push_back(make_pair(make_pair(stationA, stationB), flow));
                }
            }
        }
    }

    // Sort flows by flow in descending order
    sort(flows.begin(), flows.end(), [](const pair<pair<string, string>, int>& a, const pair<pair<string, string>, int>& b) {
        return a.second > b.second;
    });

    cout << "Top 10 stations by required trains:\n";
    for (int i = 0; i < 10 && i < flows.size(); i++) {
        cout << flows[i].first.first << " - " << flows[i].first.second << " : " << flows[i].second << " trains\n";
    }

    int maxFlow = flows[0].second;
    return maxFlow;
}
