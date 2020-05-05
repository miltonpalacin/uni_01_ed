#include <iostream>
#include "undirectedGraph.h"

using namespace std;


int main(void)
{

    UndirectedGraph<char> G;

    G.addVertex('A');
    G.addVertex('B');
    G.addVertex('C');
    G.addVertex('D');
    G.addVertex('E');
    G.addVertex('E');

    G.addEdge('A', 'E');
    G.addEdge('A', 'Z');
    G.addEdge('G', 'A');
    G.addEdge('A', 'B');
    G.addEdge('A', 'B');
    G.addEdge('D', 'C');
    G.addEdge('C', 'C');
    G.addEdge('C', 'C');
    G.addEdge('B', 'E');

    G.print();

    G.isConnected();

    cout << "FIN DE PRUEBA" << endl;
    return 0;
}