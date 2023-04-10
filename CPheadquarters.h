//
// Created by Pedro on 23/03/2023.
//

#ifndef DAPROJECT_CPHEADQUARTERS_H
#define DAPROJECT_CPHEADQUARTERS_H


#include "Graph.h"
#include "Station.h"

using namespace std;

class CPheadquarters {
    Graph lines;
    unordered_map<string, Station> stations;
public:
    void read_files();

    Graph getLines() const;

    int T2_1maxflow(string station_A, string station_B);

    int T2_2maxflowAllStations();

    int T2_3municipality(string municipality);

    int T2_3district(string district);

    int T2_4maxArrive(string destination);

    int T3_1MinCost(string source, string destination);

    int T4_1ReducedConectivity(vector<string> unwantedEdges, string s, string t);

    void test();



};


#endif //DAPROJECT_CPHEADQUARTERS_H
