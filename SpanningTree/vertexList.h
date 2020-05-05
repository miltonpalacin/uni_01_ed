#include <iostream>

using namespace std;

template <class T>
struct nodever
{
    T data;
    nodever *next;
};

template <class T>
class vertexList
{

public:
    typedef nodever<T> *pnodever;

private:
    pnodever pL;
    int sz = 0;

public:
    vertexList()
    {
        pL = NULL;
    }

    /*FIFO*/
    void addVertex(T data)
    {
        if (!isVertex(data))
        {
            pnodever pver = new nodever<T>;
            (*pver).data = data;
            (*pver).next = NULL;
            sz++;
            if (pL)
            {
                pnodever paux = pL;
                while ((*paux).next)
                    paux = (*paux).next;

                (*paux).next = pver;
            }
            else
                pL = pver;
        }
    }

    T getFist()
    {

        if (pL)
        {
            T data = (*pL).data;
            pnodever pver = pL;
            pL = (*pL).next;
            delete (pver);
            return data;
        }
        return T();
    }

    bool isVertex(T data)
    {
        if (pL)
        {
            pnodever pver = pL;
            do
            {
                if ((*pver).data == data)
                    return true;
                pver = (*pver).next;
            } while (pver);
        }
        return false;
    }

    bool remove(T data)
    {
        if (pL)
        {
            pnodever pver = pL, pver_tmp;
            do
            {
                if ((*pver).data == data)
                {
                    if (pver == pL)
                        pL = (*pL).next;
                    else
                        (*pver_tmp).next = (*pver).next;

                    delete (pver);
                    sz++;
                    return true;
                }
                pver_tmp = pver;
                pver = (*pver).next;
            } while (pver);
        }
        return false;
    }

    void clear()
    {
        if (pL)
        {
            pnodever pver = NULL;
            do
            {
                pver = pL;
                pL = (*pL).next;
                delete (pver);
            } while (pL);
        }
        sz = 0;
    }

    void print()
    {
        if (pL)
        {
            pnodever pver = pL;
            do
            {
                cout << (*pver).data << "->";
                pver = (*pver).next;
            } while (pver);

            cout << "FIN" << endl;
        }
    }

    int size()
    {
        return sz;
    }

    ~vertexList()
    {
        clear();
    }
};