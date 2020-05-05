#include <iostream>

using namespace std;

/* Tipo de dato genérico para cada vértice*/
//template <class dtype>

/* Estructura para cada arista */
template <class T>
struct edge
{
    T targetData;
    edge<T> *nextEdge;
};

/* Estructura para cada vértice */
template <class T>
struct vertex
{
    T sourceData;
    edge<T> *adjacent;
    vertex<T> *nextVertex;
};

/* Tipo de dato de abstracto (TDA) que representa a un grafo no dirigido *
 * usando listas adyacentes                                              */
template <class T>
class UndirectedGraph
{

public:
    typedef edge<T> *pedge;
    typedef vertex<T> *pvertex;

private:
    pvertex pgraph;
    // bool recorreCamino(pvertice, pvertice, camino *, camino *);
    // bool isEdgeIn(pvertex sourceVertex, T targetEdge)
    // {
    // }

public:
    /* Constructor*/
    UndirectedGraph()
    {
        pgraph = NULL;
    }

    /* Bucar el vértice del dato */
    pvertex searchVertex(T data)
    {
        if (pgraph)
        {
            pvertex pver = pgraph;
            while (pver)
            {
                if ((*pver).sourceData == data)
                    return pver;
                pver = (*pver).nextVertex;
            }
        }
        return NULL;
    }

    /* Los vertices se inserta de forma FIFO (cola), con el objetivo de mejorar la visualización */
    void addVertex(T data)
    {
        pvertex pver_new = new vertex<T>;
        (*pver_new).sourceData = data;
        (*pver_new).adjacent = NULL;
        if (!pgraph)
            pgraph = pver_new;
        else
        {
            pvertex ptmp = pgraph;
            while ((*ptmp).nextVertex) // Esto es una validación simplificada
                ptmp = (*ptmp).nextVertex;

            (*ptmp).nextVertex = pver_new;
        }
    }

    /* Las aristas se inserta de forma FIFO (cola), con el objetivo de mejorar la visualización. *
    * IMPORTANTE: El TDA grafo no dirigido establece que debe exisitir una realacion biyetiva    *
    *             entre el vértice origen y destino, por esa razón se ingresa dos aristas        *
    * Valida si existe la arista, en caso exista, imprime un mensaje                             */
    void addEdge(T sourceData, T targetData)
    {
        pvertex pver_dst = searchVertex(targetData);
        if (pver_dst)
        {
            if (pgraph)
            {
                /********************************/
                /* Ingresando la PRIMERA ARISTA */
                pedge pedg_new = new edge<T>, pedg_aux;
                (*pedg_new).targetData = targetData;
                (*pedg_new).nextEdge = NULL;
                pvertex pver_src = pgraph;
                bool isEdge = false;
                while (pver_src)
                {
                    if ((*pver_src).sourceData == sourceData)
                    {
                        pedg_aux = (*pver_src).adjacent;
                        if (pedg_aux == NULL)
                            (*pver_src).adjacent = pedg_new;
                        else
                        {
                            pedge pedg_tmp = pedg_aux;
                            do
                            {
                                pedg_aux = pedg_tmp;
                                if ((*pedg_aux).targetData == targetData)
                                {
                                    isEdge = true;
                                    cout << "La arista {" << sourceData << "," << targetData << "} ya existe!" << endl;
                                    return;
                                }
                                pedg_tmp = (*pedg_tmp).nextEdge;
                            } while (pedg_tmp);
                            (*pedg_aux).nextEdge = pedg_new;
                        }

                        break;
                    }
                    pver_src = (*pver_src).nextVertex;
                }

                /********************************/
                /* Ingresando la SEGUNDA ARISTA  */
                pedg_new = new edge<T>;
                (*pedg_new).targetData = sourceData;
                (*pedg_new).nextEdge = NULL;

                pedg_aux = (*pver_dst).adjacent;
                if (pedg_aux == NULL)
                    (*pver_dst).adjacent = pedg_new;
                else
                {
                    while ((*pedg_aux).nextEdge)
                        pedg_aux = (*pedg_aux).nextEdge;
                    (*pedg_aux).nextEdge = pedg_new;
                }
            }
        }
    }

    /* Imprime el grafo no dirigido de acuerdo al orden FIFO*/
    void print()
    {
        if (!pgraph)
            cout << "El grafo esta vacio" << endl;
        else
        {
            pvertex pver = pgraph;
            pedge pedg = NULL;
            while (pver)
            {
                cout << "[" << (*pver).sourceData << "]" << "\t\t";
                pedg = (*pver).adjacent;
                while (pedg)
                {
                    cout << (*pedg).targetData << "\t";
                    pedg = (*pedg).nextEdge;
                }
                cout << endl;
                pver = (*pver).nextVertex;
            }
        }
    }

    /****************************************************************************/
    /****************************************************************************/
    /***************************** SPANNING TREE ********************************/
    /****************************************************************************/
    /****************************************************************************/

    /* Verificaremos si a partir de un vértice el grafo es conexo */
    /* Utilizamo búsqueda en profundidad (DFG)*/
    bool isConnected()
    {
        return true;
    }

    /****************************************************************************/
    /****************************************************************************/
    /***************************** SPANNING TREE ********************************/
    /****************************************************************************/
    /****************************************************************************/

    /* Destructor del grafo no dirigido*/
    ~UndirectedGraph()
    {
        if (pgraph)
        {
            pvertex pver = pgraph, pver_tmp = NULL;
            pedge pedg = NULL, pedg_tmp = NULL;
            while (pver)
            {
                pedg = (*pver).adjacent;
                while (pedg)
                {
                    pedg_tmp = pedg;
                    pedg = (*pedg).nextEdge;
                    delete pedg_tmp;
                }
                pver_tmp = pver;
                pver = (*pver).nextVertex;
                delete pver_tmp;
            }
            pgraph = NULL;
        }
    }
};

// int main()
// {
//     grafo g;
//     g.insertarVertice('A');
//     g.insertarVertice('B');
//     g.insertarVertice('C');
//     g.insertarVertice('D');
//     g.insertarVertice('E');
//     g.insertarArista('A', 'C');
//     g.insertarArista('C', 'A');
//     g.insertarArista('A', 'D');
//     g.insertarArista('B', 'C');
//     //g.insertarArista('E', 'A');
//     g.insertarArista('E', 'B');
//     //g.insertarArista('E', 'D');

//     g.imprimirGrafo();
//     cout << "Buscar un camino" << endl;
//     g.caminoDosPuntos('E', 'D');
//     return 0;
// }
