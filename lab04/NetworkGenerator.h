#ifndef NETWORKGENERATOR_H
#define NETWORKGENERATOR_H

#include <string>
#include "Network.h"

class NetworkGenerator
{
public:
    static Network generateRandomNetwork(int numRouters, int maxCost,
                                         const string &filename);
};

#endif // NETWORKGENERATOR_H
