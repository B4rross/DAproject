// By: Gonçalo Leão

#include <climits>
#include <queue>
#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const std::string  &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const std::string  &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const std::string  &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const std::string  &sourc, const std::string  &dest, int w, std::string  service) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w, service);

    return true;
}

bool Graph::addBidirectionalEdge(const std::string  &sourc, const std::string  &dest, int w, std::string  service) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w, service);
    auto e2 = v2->addEdge(v1, w, service);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}




void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}



/*
 *  print graph content
 */
void Graph::print() const {
    std::cout << "---------------- Graph----------------\n";
    std::cout << "Number of vertices: " << vertexSet.size() << std::endl;
    std::cout << "Vertices:\n";
    for (const auto &vertex : vertexSet) {
        std::cout << vertex->getId() << " ";
    }
    std::cout << "\nEdges:\n";
    for (const auto &vertex : vertexSet) {
        for (const auto &edge : vertex->getAdj()) {
            std::cout << vertex->getId() << " -> " << edge->getDest()->getId() << " (weight: " << edge->getWeight()
                      << ", service: " << edge->getService() << ")\n";
        }
    }
}

// --------------------------------- Edmonds-Karp ---------------------------------

void Graph::testAndVisit(std::queue<Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (!w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

bool Graph::findAugmentingPath(const std::string &s, const std::string &t) {
    Vertex *source = findVertex(s);
    Vertex *target = findVertex(t);
    if (source == nullptr || target == nullptr) {
        return false;
    }
    for (auto v : vertexSet) {
        v->setVisited(false);
        v->setPath(nullptr);
    }
    source->setVisited(true);
    std::queue<Vertex*> q;
    q.push(source);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto e : v->getAdj()) {
            auto w = e->getDest();
            double residual = e->getWeight() - e->getFlow();
            testAndVisit(q, e, w, residual);
        }
        for (auto e : v->getIncoming()) {
            auto w = e->getDest();
            double residual = e->getFlow();
            testAndVisit(q, e->getReverse(), w, residual);
        }
        if (target->isVisited()) {
            return true;
        }
    }
    return false;
}

int Graph::findMinResidual(Vertex *s, Vertex *t) {
    double minResidual = INT_MAX;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            minResidual = std::min(minResidual, e->getWeight() - e->getFlow());
            v = e->getOrig();
        } else {
            minResidual = std::min(minResidual, e->getFlow());
            v = e->getDest();
        }
    }
    return minResidual;
}

void Graph::updateFlow(Vertex *s, Vertex *t, int bottleneck) {
    for (auto v = t; v != s;){
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + bottleneck);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - bottleneck);
            v = e->getDest();
        }
    }
}

int Graph::edmondsKarp(const std::string &s, const std::string &t) {
    for(auto e :vertexSet){
        for(auto i: e->getAdj()){
            i->setFlow(0);
        }
    }
    int maxFlow = 0;
    while (findAugmentingPath(s, t)) {
        int bottleneck = findMinResidual(findVertex(s), findVertex(t));
        updateFlow(findVertex(s), findVertex(t), bottleneck);
        maxFlow += bottleneck;
    }
    return maxFlow;
}

