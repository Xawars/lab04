#include "Router.h"
#include <queue>
#include <limits>
#include <functional>

Router::Router(const string &name) : name(name) {}

void Router::addLink(const string &dest, int cost) {
    links[dest] = cost;
}

void Router::removeLink(const string &dest) {
    links.erase(dest);
}

void Router::updateLinkCost(const string &dest, int new_cost) {
    links[dest] = new_cost;
}

void Router::printRoutingTable() const {
    cout << "Tabla de enrutamiento del router " << name << ":" << endl;
    for (const auto &entry : routingTable) {
        cout << name << " -> " << entry.first << " via " <<
            entry.second.first << ": " << entry.second.second << endl;
    }
}

void Router::updateRoutingTable(const map<string, Router> &routers) {
    calculateShortestPaths(routers);
}

void Router::calculateShortestPaths(const map<string, Router>& routers) {
    routingTable.clear();
    map<string, int> dist;
    map<string, string> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>> pq;

    for (const auto &router : routers) {
        dist[router.first] = numeric_limits<int>::max();
        prev[router.first] = "";
    }
    dist[name] = 0;
    pq.push({0, name});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        string currentNode = pq.top().second;
        pq.pop();

        if (currentCost <= dist[currentNode]) {
            const auto &neighborRouter = routers.at(currentNode);
            for (const auto &neighborLink : neighborRouter.links) {
                int newCost = currentCost + neighborLink.second;
                if (newCost < dist[neighborLink.first]) {
                    dist[neighborLink.first] = newCost;
                    prev[neighborLink.first] = currentNode;
                    pq.push({newCost, neighborLink.first});
                }
            }
        }
    }

    for (const auto &node : dist) {
        routingTable[node.first] = {prev[node.first], node.second};
    }
}
