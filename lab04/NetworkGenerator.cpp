#include "NetworkGenerator.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

Network NetworkGenerator::generateRandomNetwork(int numRouters, int maxCost,
                                                const string &filename) {
    srand(static_cast<unsigned>(time(nullptr)));

    ofstream file(filename);
    Network network;

    for (int i = 1; i <= numRouters; ++i) {
        string routerId = to_string(i);
        network.addRouter(routerId);

        if (i > 1) {
            string prevRouterId = to_string(i - 1);
            int cost = rand() % maxCost + 1;
            network.addLink(routerId, prevRouterId, cost);
            file << routerId << " " << prevRouterId << " " << cost << endl;
        }
    }

    int additionalLinks = numRouters * (numRouters - 1) / 2 - (numRouters - 1);
    for (int i = 0; i < additionalLinks; ++i) {
        int sourceIndex = rand() % numRouters + 1;
        int destIndex;
        do {
            destIndex = rand() % numRouters + 1;
        } while (destIndex == sourceIndex);

        string source = to_string(sourceIndex);
        string destination = to_string(destIndex);
        int cost = rand() % maxCost + 1;

        network.addLink(source, destination, cost);
        file << source << " " << destination << " " << cost << endl;
    }
    file.close();
    return network;
}
