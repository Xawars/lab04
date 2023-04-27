#include "Network.h"
#include <algorithm>

void Network::addRouter(const string &name) {
    routers[name] = Router(name);
}

void Network::removeRouter(const string &name) {
    routers.erase(name);
}

void Network::addLink(const string &from, const string &to, int cost) {
    routers[from].addLink(to, cost);
    routers[to].addLink(from, cost);
}

void Network::removeLink(const string &from, const string &to) {
    routers[from].removeLink(to);
    routers[to].removeLink(from);
}

void Network::updateLinkCost(const string &from, const string &to, int new_cost) {
    routers[from].updateLinkCost(to, new_cost);
    routers[to].updateLinkCost(from, new_cost);
}

void Network::updateAllRoutingTables() {
    for (auto& router : routers) {
        router.second.updateRoutingTable(routers);
    }
}

void Network::printAllRoutingTables() const {
    for (const auto& router : routers) {
        router.second.printRoutingTable();
    }
}

int Network::getCostBetweenRouters(const string &from, const string &to) const {
    auto it = routers.find(from);
    if (it == routers.end()) {
        throw runtime_error("Enrutador no encontrado: " + from);
    }
    const Router &router = it->second;
    auto rtIt = router.routingTable.find(to);
    if (rtIt == router.routingTable.end()) {
        throw runtime_error("Destino no encontrado en la tabla de enrutamiento: " + to);
    }
    return rtIt->second.second;
}

vector<string> Network::getPath(const string &from, const string &to) const {
    vector<string> path;
    string currentNode = to;

    if (routers.count(from) == 0 || routers.count(to) == 0 ||
        routers.at(from).routingTable.count(to) == 0) {
        return path;
    }

    while (currentNode != from) {
        path.push_back(currentNode);
        if (routers.at(from).routingTable.count(currentNode) == 0) {
            break;
        }
        currentNode = routers.at(from).routingTable.at(currentNode).first;
    }

    if (!path.empty() && currentNode == from) {
        path.push_back(from);
        reverse(path.begin(), path.end());
    } else {
        path.clear();
    }

    return path;
}

