//
// Created by Pedro on 23/03/2023.
//

#include <fstream>
#include <sstream>
#include "CPheadquarters.h"

using namespace std;

void CPheadquarters::read_files() {

    std::ifstream inputFile1(R"(../network.csv)");
    string line1;
    std::getline(inputFile1, line1); // ignore first line
    while (getline(inputFile1, line1, '\n')) {

        if (!line1.empty() && line1.back() == '\r') { // Check if the last character is '\r'
            line1.pop_back(); // Remove the '\r' character
        }

        string station_A;
        string station_B;
        string temp;
        int capacity;
        string service;

        stringstream inputString(line1);

        getline(inputString, station_A, ',');
        getline(inputString, station_B, ',');
        getline(inputString, temp, ',');
        getline(inputString, service, ',');

        capacity = stoi(temp);
        lines.addVertex(station_A);
        lines.addVertex(station_B);

        lines.addEdge(station_A, station_B, capacity, service);
    }



    std::ifstream inputFile2(R"(../stations.csv)");
    string line2;
    std::getline(inputFile2, line2); // ignore first line

    while (getline(inputFile2, line2, '\n')) {

        if (!line1.empty() && line1.back() == '\r') { // Check if the last character is '\r'
            line1.pop_back(); // Remove the '\r' character
        }

        string nome;
        string distrito;
        string municipality;
        string township;
        string line;

        stringstream inputString(line2);

        getline(inputString, nome, ',');
        getline(inputString, distrito, ',');
        getline(inputString, municipality, ',');
        getline(inputString, township, ',');
        getline(inputString, line, ',');

        Station station(nome, distrito, municipality, township, line);
        stations[nome] = station;

        // print information about the station, to make sure it was imported correctly
        //cout << "station: " << nome << " distrito: " << distrito << " municipality: " << municipality << " township: " << township << " line: " << line << endl;

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
    Vertex *source = lines.findVertex(stationA); // set source vertex
    Vertex *sink = lines.findVertex(stationB); // set sink vertex

    // Check if these stations even exist
    if (source == nullptr || sink == nullptr) {
        std::cerr << "Source or sink vertex not found." << std::endl;
        return 1;
    }
    int maxFlow = lines.edmondsKarp(stationA, stationB);

    if (maxFlow == 0) {
        cerr << "Stations are not connected. Try stationB to stationA instead. " << stationB << " -> " << stationA
             << endl;
    } else {
        cout << "maxFlow:\t" << maxFlow << endl;
    }

    return 1;
}

void CPheadquarters::test() {
    int flow = lines.edmondsKarp(lines.getVertexSet()[324]->getId(), lines.getVertexSet()[507]->getId());
}


/*
 * Determine, from all pairs of stations, which ones (if more than one) require the
 * most amount of trains when taking full advantage of the existing network capacity;
 */
int CPheadquarters::T2_2maxflowAllStations() {
    vector<string> stations;
    int maxFlow = 0;
    auto length = lines.getVertexSet().size();
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            string stationA = lines.getVertexSet()[i]->getId();
            string stationB = lines.getVertexSet()[j]->getId();
            int flow = lines.edmondsKarp(stationA, stationB);
            if (flow == maxFlow) {
                stations.push_back(stationB);
                stations.push_back(stationA);
            } else if (flow > maxFlow) {
                stations.clear();
                stations.push_back(stationB);
                stations.push_back(stationA);
                maxFlow = flow;
            }
        }
    }
    cout << "Pairs of stations with the most flow [" << maxFlow << "]:\n";
    for (int i = 0; i < stations.size(); i = i + 2) {
        cout << "------------------------\n";
        cout << "Source:" << stations[i + 1] << '\n';
        cout << "Target:" << stations[i] << '\n';
        cout << "------------------------\n";
    }
    return 0;
}


int CPheadquarters::T2_3municipality(string municipality) {
    vector<string> desired_stations;
    for (auto p: stations) {
        if (p.second.get_municipality() == municipality) {
            desired_stations.push_back(p.second.get_name());
        }
    }
    vector<string> souces = lines.find_sources(desired_stations);
    vector<string> targets = lines.find_targets(desired_stations);
    return lines.mul_edmondsKarp(souces, targets);
}

int CPheadquarters::T2_3district(string district) {
    vector<string> desired_stations;
    for (auto p: stations) {
        if (p.second.get_district() == district) {
            desired_stations.push_back(p.second.get_name());
        }
    }
    return lines.mul_edmondsKarp(lines.find_sources(desired_stations), lines.find_targets(desired_stations));
}

/*
 * Report the maximum number of trains that can simultaneously arrive at a given station,
 * taking into consideration the entire railway grid
 */
int CPheadquarters::T2_4maxArrive(string destination) {
    Vertex *dest = lines.findVertex(destination);
    int maxFlow = 0;

    // iterate over all vertices to find incoming and outgoing vertices
    for (auto &v: lines.getVertexSet()) {
        if (v != dest) {

            int flow = lines.edmondsKarp(v->getId(), destination);

            // Update the maximum flow if this vertex contributes to a higher maximum
            if (flow > maxFlow) {
                maxFlow = flow;
            }
        }

    }

    cout << endl;
    for (auto &e: dest->getIncoming()) {
        cout << e->getOrig()->getId() << " -> " << e->getDest()->getId() << " : " << e->getWeight() << endl;

    }

    cout << "Max number of trains that can simultaneously arrive at " << destination << ": " << maxFlow << endl;
    return maxFlow;

}


/*
 * Calculate the maximum amount of trains that can simultaneously travel between
 * two specific stations with minimum cost for the company
 * constraints:
 * 1. Minimize cost
 * 2. 'Maintain the same level of service'
 *
 * steps:
 * 1 - find all possible paths between source and destination
 * 2 - define the optimal path
 */
int CPheadquarters::T3_1MinCost(string source, string destination) {
    Vertex *sourceVertex = lines.findVertex(source); // set source vertex
    Vertex *destVertex = lines.findVertex(destination); // set sink vertex
    if (sourceVertex == nullptr || destVertex == nullptr) {
        cerr << "Source or destination vertex not found. Try again" << endl;
        return 1;
    }

    Graph graph = lines;

    std::vector<Vertex *> path;
    std::vector<std::vector<Vertex *>> allPaths;


    graph.findAllPaths(sourceVertex, destVertex, path, allPaths);

    vector<int> maxFlows;
    vector<int> totalCosts;

    cout << "All possible paths between " << source << " and " << destination << ":\n" << endl;
    for (auto path: allPaths) {
        int minWeight = 10;
        int totalCost = 0; // total cost of this path
        for (int i = 0; i + 1 < path.size(); i++) {
            std::cout << path[i]->getId() << " -> ";
            Edge *e = graph.findEdge(path[i], path[i + 1]);
            cout << " (" << e->getWeight() << " trains, " << e->getService() << " service) ";
            if (e->getWeight() < minWeight) {
                minWeight = e->getWeight();
            }

            // according to the problem's specification, the cost of STANDARD service is 2 euros and ALFA PENDULAR is 4
            if (e->getService() == "STANDARD") {
                totalCost += 2;
            } else if (e->getService() == "ALFA PENDULAR") {
                totalCost += 4;
            }
        }
        maxFlows.push_back(minWeight);
        totalCosts.push_back(totalCost);
        cout << " -> " << path[path.size() - 1]->getId() << endl;
        cout << "Max flow for this path: " << minWeight << " trains. ";
        cout << "Total cost: " << totalCost << " euros." << endl;
        std::cout << std::endl;
    }

    // find the path with the minimum cost per train
    int maxTrains = 0;
    int resCost;
    double max_value = 10000;
    for (int i = 0; i < maxFlows.size(); ++i) {
        double costPerTrain = (double) totalCosts[i] / maxFlows[i];
        if (costPerTrain < max_value) {
            max_value = costPerTrain;
            maxTrains = maxFlows[i];
            resCost = totalCosts[i];
        }
    }

    cout << "Max number of trains that can travel between " << source << " and " << destination
         << " with minimum cost"
         << "(" << resCost << " euros): " << maxTrains << " trains\n" << endl;
    return maxTrains;
}

int CPheadquarters::T4_1ReducedConectivity(std::vector<std::string> unwantedEdges, std::string s, std::string t) {
    Graph graph;
    ifstream inputFile1;
    inputFile1.open(R"(../network.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string station_A;
        string station_B;
        string temp;
        int capacity;
        string service;
        bool flag = true;

        stringstream inputString(line1);

        getline(inputString, station_A, ';');
        getline(inputString, station_B, ';');
        getline(inputString, temp, ';');
        capacity = stoi(temp);
        getline(inputString, service, ';');

        graph.addVertex(station_A);
        graph.addVertex(station_B);
        for (int i = 0; i < unwantedEdges.size(); i = i + 2) {
            if(station_A==unwantedEdges[i] && station_B==unwantedEdges[i+1]){
                flag=false;

            }
        }
        if(flag) {
            graph.addEdge(station_A, station_B, capacity, service);
        }
        line1 = "";
    }

    Vertex *source = graph.findVertex(s); // set source vertex
    Vertex *sink = graph.findVertex(t); // set sink vertex

    // Check if these stations even exist
    if (source == nullptr || sink == nullptr) {
        std::cerr << "Source or sink vertex not found." << std::endl;
        return 1;
    }
    int maxFlow = graph.edmondsKarp(s, t);

    if (maxFlow == 0) {
        cerr << "Stations are not connected. Try stationB to stationA instead. " << t << " -> " << s
             << endl;
    }
    cout << "maxFlow:\t" << maxFlow << endl;


    return 1;
}

int CPheadquarters::T4_2Top_K_ReducedConectivity(vector<string> unwantedEdges) {
    Graph graph;
    ifstream inputFile1;
    inputFile1.open(R"(../network.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string station_A;
        string station_B;
        string temp;
        int capacity;
        string service;
        bool flag = true;

        stringstream inputString(line1);

        getline(inputString, station_A, ';');
        getline(inputString, station_B, ';');
        getline(inputString, temp, ';');
        capacity = stoi(temp);
        getline(inputString, service, ';');

        graph.addVertex(station_A);
        graph.addVertex(station_B);
        for (int i = 0; i < unwantedEdges.size(); i = i + 2) {
            if(station_A==unwantedEdges[i] && station_B==unwantedEdges[i+1]){
                flag=false;
                break;
            }
        }
        if(flag) {
            graph.addEdge(station_A, station_B, capacity, service);
        }
        line1 = "";
    }


    vector<pair<int, int>> top_k;
    auto length = lines.getVertexSet().size();
    for (int i = 0; i < length; ++i) {
        string destination = lines.getVertexSet()[i]->getId();
        Vertex *dest = lines.findVertex(destination);

        int maxFlow1 = 0;
        int maxFlow2 = 0;

        for (auto &v: lines.getVertexSet()) {
            if (v != dest) {
                int flow = lines.edmondsKarp(v->getId(), destination);
                if (flow > maxFlow1) {
                    maxFlow1 = flow;
                }
                flow = graph.edmondsKarp(v->getId(), destination);
                if (flow > maxFlow2) {
                    maxFlow2 = flow;
                }
            }
        }

        int diff = maxFlow1 - maxFlow2;
        auto p = pair(i,diff);
        top_k.push_back(p);
        cout << "a";
    }
    std::sort(top_k.begin(), top_k.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    for(int i = 0; i < 10; i++){
        cout << i+1 << "-" << lines.getVertexSet()[top_k[i].first]->getId() << " -> " << top_k[i].second << '\n';
    }
    return 1;
}