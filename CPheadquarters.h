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
    unordered_map<string,Station> stations;
public:
    void read_files();

    Graph getLines() const;
    int T2_1maxflow(string station_A, string station_B);
};


#endif //DAPROJECT_CPHEADQUARTERS_H
