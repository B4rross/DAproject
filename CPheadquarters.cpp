//
// Created by Pedro on 23/03/2023.
//

#include <fstream>
#include <sstream>
#include "CPheadquarters.h"
#include <chrono>
#include <set>

using namespace std;

void CPheadquarters::read_network(string path){
    std::ifstream inputFile1(path);
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
}

void CPheadquarters::read_stations(string path){
    std::ifstream inputFile2(R"(../stations.csv)");
    string line2;
    std::getline(inputFile2, line2); // ignore first line

    while (getline(inputFile2, line2, '\n')) {

        if (!line2.empty() && line2.back() == '\r') { // Check if the last character is '\r'
            line2.pop_back(); // Remove the '\r' character
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

void CPheadquarters::read_files() {

    //--------------------------------------------Read network.csv--------------------------------------------
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


    //--------------------------------------------Read stations.csv--------------------------------------------
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


int CPheadquarters::T2_1maxflow(string stationA, string stationB) {
    Vertex *source = lines.findVertex(stationA); // set source vertex
    Vertex *sink = lines.findVertex(stationB); // set sink vertex

    // Check if these stations even exist
    if (source == nullptr || sink == nullptr) {
        std::cerr << "Source or sink vertex not found." << std::endl;
        return 0;
    }
    int maxFlow = lines.edmondsKarp(stationA, stationB);

    if (maxFlow == 0) {
        cerr << "Stations are not connected. Try stationB to stationA instead. " << stationB << " -> " << stationA
             << endl;
    } else {
        cout << "maxFlow:\t" << maxFlow << endl;
    }

    return maxFlow;
}


int CPheadquarters::T2_2maxflowAllStations() {
    vector<string> stations;
    int maxFlow = 0;
    auto length = lines.getVertexSet().size();
    // Start the timer
    auto start_time = std::chrono::high_resolution_clock::now();
    cout << "Calculating max flow for all pairs of stations..." << endl;
    cout << "Please stand by..." << endl;
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
    // End the timer
    auto end_time = std::chrono::high_resolution_clock::now();

    // Compute the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Print the duration
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;

    cout << "Pairs of stations with the most flow [" << maxFlow << "]:\n";
    for (int i = 0; i < stations.size(); i = i + 2) {
        cout << "------------------------\n";
        cout << "Source: " << stations[i + 1] << '\n';
        cout << "Target: " << stations[i] << '\n';
        cout << "------------------------\n";
    }
    return maxFlow;
}


void CPheadquarters::T2_3municipality() {
    vector<pair<string , int>> top_k;
    set<string> sett;
    for (auto m : stations) {
        sett.insert(m.second.get_district());
    }
    for (auto m : sett) {
        vector<string> desired_stations;
        for (auto p: stations) {
            if (p.second.get_municipality() == m) {
                desired_stations.push_back(p.second.get_name());
            }
        }


        vector<string> souces = lines.find_sources(desired_stations);
        vector<string> targets = lines.find_targets(desired_stations);
        int diff=lines.mul_edmondsKarp(souces, targets);
        auto p = pair(m, diff);
        top_k.push_back(p);
    }
    std::sort(top_k.begin(), top_k.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "-" << top_k[i].first << " -> " << top_k[i].second << '\n';
    }
}

void CPheadquarters::T2_3district() {
    vector<pair<string , int>> top_k;
    set<string> sett;
    for (auto m : stations) {
        sett.insert(m.second.get_district());
    }
    for (auto m : sett) {
        vector<string> desired_stations;
        for (auto p: stations) {
            if (p.second.get_district() == m) {
                desired_stations.push_back(p.second.get_name());
            }
        }
        vector<string> souces = lines.find_sources(desired_stations);
        vector<string> targets = lines.find_targets(desired_stations);
        int diff=lines.mul_edmondsKarp(souces, targets);
        auto p = pair(m, diff);
        top_k.push_back(p);
    }
    std::sort(top_k.begin(), top_k.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "-" << top_k[i].first << " -> " << top_k[i].second << '\n';
    }
}


int CPheadquarters::T2_4maxArrive(string destination) {
    int maxFlow = 0;
    vector<string> org = lines.getSources();
    vector<string> targ = lines.getTargets();
    auto v = lines.findVertex(destination);
    lines.mul_edmondsKarp(org,targ);
    for(auto e : v->getIncoming()){
        maxFlow+=e->getFlow();
    }
    cout << "Max Flow: " << maxFlow << '\n';
    return maxFlow;
}



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
        bool flag=true;

        stringstream inputString(line1);

        getline(inputString, station_A, ',');
        getline(inputString, station_B, ',');
        getline(inputString, temp, ',');
        getline(inputString, service, ',');

        capacity = stoi(temp);
        graph.addVertex(station_A);
        graph.addVertex(station_B);

        for (int i = 0; i < unwantedEdges.size(); i = i + 2) {
                if(station_A==unwantedEdges[i] && station_B==unwantedEdges[i+1]){
                    flag=false;
                }
        }
        if (flag) {
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
        bool flag=true;

        stringstream inputString(line1);

        getline(inputString, station_A, ',');
        getline(inputString, station_B, ',');
        getline(inputString, temp, ',');
        getline(inputString, service, ',');

        capacity = stoi(temp);
        graph.addVertex(station_A);
        graph.addVertex(station_B);

        for (int i = 0; i < unwantedEdges.size(); i = i + 2) {
            if (station_A == unwantedEdges[i] && station_B == unwantedEdges[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            graph.addEdge(station_A, station_B, capacity, service);
        }
        line1 = "";
    }
    vector<string> org = lines.getSources();
    vector<string> targ = lines.getTargets();

    lines.mul_edmondsKarp(org,targ);
    graph.mul_edmondsKarp(org,targ);
    vector<pair<int, int>> top_k;

    auto length = lines.getVertexSet().size();
    for (int i = 0; i < length; ++i) {
        string destination = lines.getVertexSet()[i]->getId();
        auto v1 = lines.findVertex(destination);
        auto v2 = graph.findVertex(destination);
        int maxFlow1 = 0;
        int maxFlow2 = 0;
        for(auto e : v1->getIncoming()){
            maxFlow1+=e->getFlow();
        }
        for(auto e : v2->getIncoming()){
            maxFlow2+=e->getFlow();
        }
        int diff = maxFlow1 - maxFlow2;
        auto p = pair(i, diff);
        top_k.push_back(p);
    }
    std::sort(top_k.begin(), top_k.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "-" << lines.getVertexSet()[top_k[i].first]->getId() << " -> " << top_k[i].second << '\n';
    }
    return 1;
}