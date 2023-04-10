// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>


#include "VertexEdge.h"

class Graph {
public:
    ~Graph();

    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const std::string &id) const;

    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const std::string &id);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const std::string &sourc, const std::string &dest, int w, std::string service);

    bool addBidirectionalEdge(const std::string &sourc, const std::string &dest, int w, std::string service);

    [[nodiscard]] int getNumVertex() const;

    [[nodiscard]] std::vector<Vertex *> getVertexSet() const;

    void print() const;

    int edmondsKarp(const std::string &s, const std::string &t);

    std::vector<std::string> getSources();

    std::vector<std::string> getTargets();

    int mul_edmondsKarp(std::vector<std::string> souces, std::vector<std::string> targets);

    std::vector<std::string> find_sources(std::vector<std::string> desired_stations);

    std::vector<std::string> find_targets(std::vector<std::string> desired_stations);

    void findAllPaths(Vertex *source, Vertex *destination, std::vector<Vertex *> &path,
                      std::vector<std::vector<Vertex *>> &allPaths);

    Edge *findEdge(Vertex *source, Vertex *destination);

protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double **distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const std::string &id) const;


    void updateFlow(Vertex *s, Vertex *t, int bottleneck);

    int findMinResidual(Vertex *s, Vertex *t);

    bool findAugmentingPath(const std::string &s, const std::string &t);

    void testAndVisit(std::queue<Vertex *> &q, Edge *e, Vertex *w, double residual);

    bool isIn(std::string n, std::vector<std::string> vec);

    void deleteVertex(std::string name);
};

void deleteMatrix(int **m, int n);

void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */