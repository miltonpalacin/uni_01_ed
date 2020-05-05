#include <iostream>
#include "undirectedGraph.h"
//#include "pureTree.h"

using namespace std;

int main(void)
{
    try
    {
        UndirectedGraph<int> G;

        G.addVertex(1);
        G.addVertex(2);
        G.addVertex(3);
        G.addVertex(4);
        G.addVertex(5);
        G.addVertex(6);
        G.addVertex(7);
        G.addVertex(8);
        G.addVertex(9);
        G.addVertex(10);
        G.addVertex(11);
        G.addVertex(12);
        G.addVertex(13);
        G.addVertex(14);

        G.addEdge(1, 1);
        G.addEdge(1, 2);
        G.addEdge(1, 3);
        G.addEdge(1, 7);
        G.addEdge(2, 4);
        G.addEdge(3, 5);
        G.addEdge(3, 7);
        G.addEdge(3, 4);
        G.addEdge(4, 8);
        G.addEdge(5, 6);
        G.addEdge(6, 7);
        G.addEdge(7, 11);
        G.addEdge(6, 11);
        G.addEdge(5, 10);
        G.addEdge(5, 9);
        G.addEdge(5, 8);
        G.addEdge(8, 9);
        G.addEdge(10, 12);
        G.addEdge(11, 13);
        G.addEdge(12, 9);
        G.addEdge(12, 13);
        G.addEdge(12, 14);
        G.addEdge(13, 14);
        G.addEdge(9, 14);

        G.addVertex(15);
        G.addVertex(16);
        G.addEdge(15, 16);

        cout << "FIN DE PRUEBA" << endl;

        G.print();

        if (G.isConnected())
            cout << "El grafo SI es conexo!" << endl;
        else
            cout << "El grafo NO es conexo!" << endl;

        int ver = 1;
        pureTree<int> tree1 = G.spanningTreeDfs(ver);
        cout << "ARBOL DE RECUBRIMIENTO EN PROFUNDIDAD DESDE EL VÉRTICE [" << ver << "]" << endl;
        tree1.print();

        pureTree<int> tree2 = G.spanningTreeBfs(ver);
        cout << "ARBOL DE RECUBRIMIENTO EN AMPLITUD DESDE EL VÉRTICE [" << ver << "]" << endl;
        tree2.print();

        cout << "FIN DE PRUEBA" << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

int main3(void)
{
    try
    {
        UndirectedGraph<int> G;

        G.addVertex(1);
        G.addVertex(2);
        G.addVertex(3);
        G.addVertex(4);
        G.addVertex(5);
        G.addVertex(6);
        G.addVertex(7);
        G.addVertex(8);
        G.addVertex(9);
        G.addVertex(10);
        G.addVertex(11);
        G.addVertex(12);
        G.addVertex(13);
        G.addVertex(14);

        G.addEdge(1, 1);
        G.addEdge(1, 2);
        G.addEdge(1, 3);
        G.addEdge(1, 7);
        G.addEdge(2, 4);
        G.addEdge(3, 5);
        G.addEdge(3, 7);
        G.addEdge(3, 4);
        G.addEdge(4, 8);
        G.addEdge(5, 6);
        G.addEdge(6, 7);
        G.addEdge(7, 11);
        G.addEdge(6, 11);
        G.addEdge(5, 10);
        G.addEdge(5, 9);
        G.addEdge(5, 8);
        G.addEdge(8, 9);
        G.addEdge(10, 12);
        G.addEdge(11, 13);
        G.addEdge(12, 9);
        G.addEdge(12, 13);
        G.addEdge(12, 14);
        G.addEdge(13, 14);
        G.addEdge(9, 14);

        G.addVertex(15);
        G.addVertex(16);
        G.addEdge(15, 16);

        cout << "FIN DE PRUEBA" << endl;

        G.print();

        if (G.isConnected())
            cout << "El grafo SI es conexo!" << endl;
        else
            cout << "El grafo NO es conexo!" << endl;

        int ver = 1;
        pureTree<int> tree1 = G.spanningTreeDfs(ver);
        cout << "ARBOL DE RECUBRIMIENTO EN PROFUNDIDAD DESDE EL VÉRTICE [" << ver << "]" << endl;
        tree1.print();

        pureTree<int> tree2 = G.spanningTreeBfs(ver);
        cout << "ARBOL DE RECUBRIMIENTO EN AMPLITUD DESDE EL VÉRTICE [" << ver << "]" << endl;
        tree2.print();

        cout << "FIN DE PRUEBA" << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

//UndirectedGraph<char> G;

// G.addVertex('A');
// G.addVertex('B');
// G.addVertex('C');
// G.addVertex('D');
// G.addVertex('E');
// G.addVertex('E');

// G.addEdge('A', 'E');
// G.addEdge('A', 'Z');
// G.addEdge('G', 'A');
// G.addEdge('A', 'B');
// G.addEdge('A', 'B');
// G.addEdge('D', 'C');
// G.addEdge('C', 'C');
// G.addEdge('C', 'C');
// G.addEdge('B', 'E');

// G.addVertex('A');
// G.addVertex('B');
// G.addVertex('C');
// G.addVertex('D');
// G.addVertex('E');
// G.addVertex('F');
// G.addVertex('G');
// G.addEdge('A', 'B');
// G.addEdge('A', 'C');
// G.addEdge('A', 'D');
// G.addEdge('B', 'C');
// G.addEdge('B', 'F');
// G.addEdge('C', 'D');
// G.addEdge('C', 'E');
// G.addEdge('C', 'F');
// G.addEdge('D', 'E');
// G.addEdge('D', 'F');
// G.addEdge('E', 'F');

// tree<string> tre;
// tre.addLeaf("Abuelo");
// tre.addLeaf("Tio01");
// tre.addLeaf("Tio02");
// tre.addLeaf("papa");
// tre.addLeaf("Tio03");
// tre.addLeaf("Tio04");
// tre.addBrach("A","B");
// pureTree<string> tre;
// // tre.addRoot("Abuelo");
// tre.addBrach("Tatarabuelo","Abuelo");
// tre.addBrach("Abuelo","Tio01");
// tre.addBrach("Abuelo","Tio02");
// tre.addBrach("Tio02","Primo01");
// tre.addBrach("Abuelo","Tio03");
// tre.addBrach("Abuelo","Papa");
// tre.addBrach("Abuelo","Tio04");
// tre.addBrach("Abuelo","Tio05");
// tre.addBrach("Abuelo","Tio06");
// tre.addBrach("Papa","Yo");
// tre.addBrach("Yo","MiHija");
// tre.addBrach("MiHija","SuHija");
// tre.addBrach("Papa","Hermana");
// tre.addLeaf("papa");
// tre.addLeaf("Tio03");
// tre.addLeaf("Tio04");
// tre.addBrach("A", "B");
// tre.print();