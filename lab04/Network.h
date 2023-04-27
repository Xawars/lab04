#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <map>
#include <vector>
#include "Router.h"

using namespace std;

class Network {
public:
    void addRouter(const string &name);
    void removeRouter(const string &name);
    void addLink(const string &from, const string &to, int cost);
    void removeLink(const string &from, const string &to);
    void updateLinkCost(const string &from, const string &to, int new_cost);
    void updateAllRoutingTables();
    void printAllRoutingTables() const;

    int getCostBetweenRouters(const string &from, const string &to) const;

    vector<string> getPath(const string &from, const string &to) const;

private:
    map<string, Router> routers;
};


#endif // NETWORK_H
