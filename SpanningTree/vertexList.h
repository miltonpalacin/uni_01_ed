#include <iostream>

using namespace std;

template <class T>
struct vertex
{
    T data;
    vertex *next;
};

template <class T>
class vertexList
{

public:
    typedef vertex<T> *pvertex;

private:
    pvertex pL;

public:
    vertexList()
    {
        pL = NULL;
    }

    /*LIFO*/
    void addVertex(T data)
    {
        pvertex pver = new vertex<T>;
        (*pver).data = data;
        (*pver).next = pL;
        pL = pver;
    }

    bool isVertex(T data)
    {
        if (pL)
        {
            pvertex pver = pL;
            do
            {
                if ((*pver).data == data)
                    return true;
                pver = pver->sig;
            } while (pver);
        }
        return false;
    }

    bool remove(T data)
    {
        if (pL)
        {
            pvertex pver = pL, pver_tmp;
            do
            {
                if ((*pver).data == data)
                {
                    if (pver == pL)
                        pL = (*pL).next;
                    else
                        (*pver_tmp).next = (*pver).next;

                    delete (pver);

                    return true;
                }
                pver_tmp = pver;
                pver = (*pver)sig;
            } while (pver);
        }
        return false;
    }

    void clear()
    {
        if (pL)
        {
            pvertex pver = NULL;
            do
            {
                pver = pL;
                pL = (*pL).next;
                delete (pver);
            } while (pL);
        }
    }

    void print()
    {
        if (pL)
        {
            pvertex pver = pL;
            do
            {
                cout << (*pver).data << "->";
                pver = (*pver).next;
            } while (pver);

            cout << "FIN" << endl;
        }
    }

    ~vertexList()
    {
        clear();
    }
};