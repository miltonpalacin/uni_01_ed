#include <iostream>

using namespace std;

template <class T>
struct nodeedg
{
    T sourceData;
    T targetData;
    nodeedg *next;
};

template <class T>
class edgeList
{

public:
    typedef nodeedg<T> *pedgeedg;

private:
    pedgeedg pL;
    int sz = 0;

public:
    edgeList()
    {
        pL = NULL;
    }

    /*LIFO*/
    void addEdge(T sourceData, T targetData)
    {
        if (!isEdge(sourceData, targetData))
        {
            pedgeedg pedg = new nodeedg<T>;
            (*pedg).sourceData = sourceData;
            (*pedg).targetData = targetData;
            sz++;
            if (pL)
            {
                pedgeedg paux = pL;
                while ((*paux).next)
                    paux = (*paux).next;
                (*paux).next = pver;
            }
            else
                pL = pedg;
        }
    }

    bool isEdge(T sourceData, T targetData)
    {
        if (pL)
        {
            pedgeedg pedg = pL;
            do
            {
                if (((*pedg).sourceData == sourceData && (*pedg).targetData == targetData) || ((*pedg).sourceData == targetData && (*pedg).targetData == sourceData))
                    return true;
                pedg = (*pedg).next;
            } while (pedg);
        }
        return false;
    }

    bool remove(T sourceData, T targetData)
    {
        if (pL)
        {
            pedgeedg pedg = pL, pedg_tmp;
            do
            {
                if (((*pedg).sourceData == sourceData && (*pedg).targetData == targetData) || ((*pedg).sourceData == targetData && (*pedg).targetData == sourceData))
                {
                    if (pedg == pL)
                        pL = (*pL).next;
                    else
                        (*pedg_tmp).next = (*pedg).next;

                    delete (pedg);
                    sz--;
                    return true;
                }
                pedg_tmp = pedg;
                pedg = (*pedg).next;
            } while (pedg);
        }
        return false;
    }

    void clear()
    {
        if (pL)
        {
            pedgeedg pedg = NULL;
            do
            {
                pedg = pL;
                pL = (*pL).next;
                delete (pedg);
            } while (pL);
        }
        sz = 0;
    }

    void print()
    {
        if (pL)
        {
            pedgeedg pedg = pL;
            do
            {
                cout << "{" << (*pedg).sourceData << "," << (*pedg).targetData << "}"
                     << "->";
                pedg = (*pedg).next;
            } while (pedg);

            cout << "FIN" << endl;
        }
    }

    int size()
    {
        return sz;
    }

    ~edgeList()
    {
        clear();
    }
};