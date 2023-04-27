#include "Network.h"

void testA() {
    Network network;

    network.addRouter("A");
    network.addRouter("B");
    network.addRouter("C");
    network.addRouter("D");

    network.addLink("A", "B", 4);
    network.addLink("B", "D", 1);
    network.addLink("D", "C", 2);
    network.addLink("A", "C", 10);

    network.updateAllRoutingTables();
    network.printAllRoutingTables();
}

void testB() {
    Network network;

    // Enrutadores
    network.addRouter("A");
    network.addRouter("B");
    network.addRouter("C");
    network.addRouter("D");

    // Enlaces
    network.addLink("A", "B", 4);
    network.addLink("B", "D", 1);
    network.addLink("D", "C", 2);
    network.addLink("A", "C", 10);

    // Actualizar tablas de enrutamiento
    network.updateAllRoutingTables();
    network.printAllRoutingTables();

    // Cambiar la topología de la red y actualizar las tablas de enrutamiento
    network.removeLink("A", "C");
    network.updateAllRoutingTables();
    network.printAllRoutingTables();

    // Agregar un nuevo enrutador y actualizar la topología
    network.addRouter("E");
    network.addLink("E", "A", 5);
    network.updateAllRoutingTables();
    network.printAllRoutingTables();
}

void testC() {
    Network network;

    network.addRouter("A");
    network.addRouter("B");
    network.addRouter("C");
    network.addRouter("D");

    network.addLink("A", "B", 4);
    network.addLink("B", "D", 1);
    network.addLink("D", "C", 2);
    network.addLink("A", "C", 10);

    network.updateAllRoutingTables();

    try {
        int cost = network.getCostBetweenRouters("A", "C");
        cout << "Coste de envío de un paquete de A a C: " << cost << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void testD() {
    Network network;

    network.addRouter("A");
    network.addRouter("B");
    network.addRouter("C");
    network.addRouter("D");

    network.addLink("A", "B", 4);
    network.addLink("B", "D", 1);
    network.addLink("D", "C", 2);
    network.addLink("A", "C", 10);

    network.updateAllRoutingTables();

    vector<string> path = network.getPath("A", "C");
    cout << "Ruta de A a C: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}
