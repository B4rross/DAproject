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
