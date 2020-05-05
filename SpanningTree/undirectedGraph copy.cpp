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

    G.addEdge('A', 'E');
    G.addEdge('A', 'B');
    G.addEdge('A', 'B');
    G.addEdge('D', 'C');

    G.print();

    return 0;
}