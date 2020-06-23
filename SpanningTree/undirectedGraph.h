#include <iostream>
#include "vertexList.h"
#include "pureTree.h"

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
    int sizeGraph = 0;

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
        pvertex pver = searchVertex(data);
        if (pver)
        {
            cout << "El vertice [" << data << "] ya fue ingresado!" << endl;
            return;
        }
        pvertex pver_new = new vertex<T>;
        (*pver_new).sourceData = data;
        (*pver_new).adjacent = NULL;
        (*pver_new).nextVertex = NULL;
        sizeGraph++;
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

        if (!pver_dst)
        {
            cout << "El vertice destino [" << targetData << "] no existe!" << endl;
            return;
        }

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

            if (!pver_src)
            {
                cout << "El vertice origen [" << sourceData << "] no existe!" << endl;
                return;
            }

            /* Validar si existe bucles, no es necesario el ingreso de un vertice en el otro sentido */
            if (sourceData == targetData)
                return;

            /********************************/
            /* Ingresando la SEGUNDA ARISTA que corresponde a la segunda al otro sentido */
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

    /* Imprime el grafo no dirigido de acuerdo al orden FIFO*/
    void print()
    {
        if (!pgraph)
            cout << "El grafo esta vacio" << endl;
        else
        {
            pvertex pver = pgraph;
            pedge pedg = NULL;
            cout << "====================== GRAFO ======================" << endl;
            while (pver)
            {
                cout << "[" << (*pver).sourceData << "]"
                     << " \t\t -> { \t";
                pedg = (*pver).adjacent;
                while (pedg)
                {
                    cout << (*pedg).targetData << " \t";
                    pedg = (*pedg).nextEdge;
                }
                cout << " } " << endl;
                pver = (*pver).nextVertex;
            }
            cout << "=====================================================" << endl;
        }
    }

    /****************************************************************************/
    /****************************************************************************/
    /***************************** SPANNING TREE ********************************/
    /****************************************************************************/
    /****************************************************************************/

    /* Verificaremos si a partir de un vértice el grafo es conexo */
    /* Utiliza búsqueda en profundidad */
    bool isConnected()
    {
        if (pgraph)
        {
            pvertex pver = pgraph;
            vertexList<T> vertexs;
            vertexs.addVertex((*pver).sourceData);
            isConnected(pver, &vertexs);
            // cout << "Vertices de grafo inmediato:" << endl;
            // vertexs.print();
            return sizeGraph == vertexs.size();
        }
        return false;
    }

    /* Método recursivo para la búsqueda en profundidad*/
    void isConnected(pvertex pver, vertexList<T> *vertexs)
    {
        if (pver)
        {
            pedge pedg = (*pver).adjacent;
            pvertex pver_tmp = NULL;
            while (pedg)
            {
                pver_tmp = searchVertex((*pedg).targetData);
                if (!(*vertexs).isVertex((*pver_tmp).sourceData))
                {
                    (*vertexs).addVertex((*pver_tmp).sourceData);
                    isConnected(pver_tmp, vertexs);
                }
                pedg = (*pedg).nextEdge;
            }
        }
    }

    /* Generar el arbol recubrimiento con DFS (Depth First Seach)*/
    pureTree<T> spanningTreeDfs(T data)
    {
        pureTree<T> tree;
        if (pgraph)
        {
            pvertex pver = searchVertex(data);
            vertexList<T> vertexs;
            vertexs.addVertex((*pver).sourceData);
            spanningTreeDfs(pver, &vertexs, &tree);
            if (sizeGraph == vertexs.size())
                return tree;
            else
                cout << "El arbol NO es conexo, no se a cubierto todo los vertices!" << endl;
        }
        return tree;
    }

    /* Método reursivo para la generación del arbol con DFS*/
    void spanningTreeDfs(pvertex pver, vertexList<T> *vertexs, pureTree<T> *tree)
    {

        pedge pedg = (*pver).adjacent;
        pvertex pver_tmp = NULL;
        while (pedg)
        {
            pver_tmp = searchVertex((*pedg).targetData);
            if (!(*vertexs).isVertex((*pver_tmp).sourceData))
            {
                /*Agregamos una nueva rama con una nueva hoja al arbol*/
                (*tree).addBrach((*pver).sourceData, (*pver_tmp).sourceData);
                (*vertexs).addVertex((*pver_tmp).sourceData);
                spanningTreeDfs(pver_tmp, vertexs, tree);
            }
            pedg = (*pedg).nextEdge;
        }
    }

    /* Generar el arbol recubrimiento con BFS (Breadth First Seach)*/
    pureTree<T> spanningTreeBfs(T data)
    {
        pureTree<T> tree;
        if (pgraph)
        {
            pvertex pver = searchVertex(data), pver_tmp;
            vertexList<T> vertexs;
            vertexList<T> vertexQueue;
            vertexs.addVertex((*pver).sourceData);
            vertexQueue.addVertex((*pver).sourceData);

            while (!vertexQueue.isEmpy())
            {
                T ver = vertexQueue.getFist();
                pver_tmp = searchVertex(ver);
                spanningTreeBfs(ver, (*pver_tmp).adjacent, &vertexs, &vertexQueue, &tree);
            }

            if (sizeGraph == vertexs.size())
                return tree;
            else
                cout << "El arbol NO es conexo, no se a cubierto todo los vertices!" << endl;
        }
        return tree;
    }

    /* Método reursivo para la generación del arbol con DFS*/
    void spanningTreeBfs(T ver, pedge pedg, vertexList<T> *vertexs, vertexList<T> *vertexQueue, pureTree<T> *tree)
    {
        if (pedg)
        {
            if (!(*vertexs).isVertex((*pedg).targetData))
            {
                (*tree).addBrach(ver, (*pedg).targetData);
                (*vertexs).addVertex((*pedg).targetData);
                (*vertexQueue).addVertex((*pedg).targetData);
            }
            spanningTreeBfs(ver, (*pedg).nextEdge, vertexs, vertexQueue, tree);
        }
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
            sizeGraph = 0;
        }
    }
};