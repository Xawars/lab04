#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Network; // Forward declaration

class Router {
public:
    Router() = default;
    Router(const string &name);
    void addLink(const string &dest, int cost);
    void removeLink(const string &dest);
    void updateLinkCost(const string &dest, int new_cost);
    void printRoutingTable() const;

private:
    string name;
    map<string, int> links;
    map<string, pair<string, int>> routingTable;

    friend class Network; // Friend declaration

    void calculateShortestPaths(const map<string, Router> &routers);
    void updateRoutingTable(const map<string, Router> &routers);
};

#endif // ROUTER_H
