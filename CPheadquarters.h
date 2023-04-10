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
    /**
    * Reads the files network.csv and stations.csv and stores the information in the Graph and unordered_map
    */
    void read_files();

    /**
     * Returns the Graph object
     * @return Graph
     */
    Graph getLines() const;

    /**
     * Calculates the maximum number of trains that can simultaneously travel between
     * two specific stations.
     * Takes any valid source and destination stations as input
     * @param stationA
     * @param stationB
     * @return maxFlow
     */
    int T2_1maxflow(string station_A, string station_B);

    /**
     * Determines from all pairs of stations, which ones (if more than one) require the
     * most amount of trains when taking full advantage of the existing network capacity.
     * Print to the terminal all pairs of stations that require the most amount of trains (if more than one).
     * Count the time it takes to run the algorithm and print it to the terminal.
     * @see this function uses Graph::edmondsKarp() function
     * @return maxFlow
     */
    int T2_2maxflowAllStations();

    /**
     * Indicates where management should assign larger budgets for the purchasing and
     * maintenance of trains.
     * Reports the top-k municipalities and districts, regarding their transportation needs
     * @param municipality
     * @return maximum flow in the given municipality
     */
    int T2_3municipality(string municipality);

    int T2_3district(string district);

    /**
     * Reports the maximum number of trains that can simultaneously arrive at a given station,
     * taking into consideration the entire railway grid
     * @param destination
     * @return maximum flow in a given station
     * @note we consider the source station as the station that does not have any incoming edges
     */
    int T2_4maxArrive(string destination);

    /**
     * Calculates the maximum amount of trains that can simultaneously travel between
     * two specific stations with minimum cost for the company
     * steps:
     * *1 - find all possible paths between source and destination
     * *2 - define the optimal path, that is, has minimum cost per train
     * @param source
     * @param destination
     * @return maximum flow between two specific stations
     */
    int T3_1MinCost(string source, string destination);

    /**
     * Calculates the maximum number of trains that can simultaneously travel between
     * two specific stations in a network of reduced connectivity.
     * Reduced connectivity is a subgraph of the original railway network.
     * Takes any valid source and destination stations as input.
     * @note it allows a user to remove edges from the railway network.
     * @param unwantedEdges
     * @param s
     * @param t
     * @return maximum flow between two specific stations
     */
    int T4_1ReducedConectivity(vector<string> unwantedEdges, string s, string t);

    /**
     * Provides a report on the stations that are the most affected by each segment failure,
     * i.e., the top-k most affected stations for each segment to be considered
     * @param unwantedEdges
     * @return top-k most affected stations for each segment to be considered
     */
    int T4_2Top_K_ReducedConectivity(vector<string> unwantedEdges);

    void test();



};


#endif //DAPROJECT_CPHEADQUARTERS_H
