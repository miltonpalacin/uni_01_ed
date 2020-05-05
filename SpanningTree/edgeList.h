#include <iostream>

using namespace std;

template <class T>
struct edge
{
    T sourceData;
    T targetData;
    edge *next;
};

template <class T>
class edgeList
{

public:
    typedef edge<T> *pedge;

private:
    pedge pL;

public:
    edgeList()
    {
        pL = NULL;
    }

    /*LIFO*/
    void addEdge(T sourceData, T targetData)
    {
        pedge pedg = new pedge<T>;
        (*pedg).sourceData = sourceData;
        (*pedg).targetData = targetData;
        (*pedg).next = pL;
        pL = pedg;
    }

    bool isEdge(T sourceData, T targetData)
    {
        if (pL)
        {
            pvertex pver = pL;
            do
            {
                if (((*p).dato == dato && (*p).dato_extra == dato_extra) || ((*p).dato == dato_extra && (*p).dato_extra == dato))
                if ((*pver).data == data)
                    return true;
                pver = pver->sig;
            } while (pver);
        }
        return false;
    }

    bool existeCamino(char dato, char dato_extra)
    {
        if (pL)
        {
            pcamino p = pL;
            do
            {
                if (((*p).dato == dato && (*p).dato_extra == dato_extra) || ((*p).dato == dato_extra && (*p).dato_extra == dato))
                    return true;
                p = p->sig;
            } while (p != NULL);
        }
        return false;
    }

    void retrocederTodo()
    {
        pcamino p = pL;
        pL = NULL;
        if (p != NULL)
        {
            pL = p->sig;
            delete p;
            p = pL;
        }
    }
    void imprimir()
    {
        if (pL)
        {
            pcamino p = pL;
            do
            {
                cout << (*p).dato << "->";
                p = p->sig;
            } while (p != NULL);

            cout << "FIN" << endl;
        }
    }
    ~camino()
    {
        retrocederTodo();
    }
};