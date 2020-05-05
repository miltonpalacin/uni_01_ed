#include <iostream>
#include <string>

using namespace std;

template <class T>
struct branch
{
    T sonData;
    branch<T> *nextBranch;
};

template <class T>
struct leaf
{
    T dadData;
    branch<T> *adjacent;
    leaf<T> *nextLeaf;
};

template <class T>
class tree
{

public:
    typedef branch<T> *pbranch;
    typedef leaf<T> *pleaf;

private:
    pleaf ptree;
    int sizeTree = 0;

public:
    /* Constructor*/
    tree()
    {
        ptree = NULL;
    }

    pleaf searchLeaf(T data)
    {
        if (ptree)
        {
            pleaf plf = ptree;
            while (plf)
            {
                if ((*plf).dadData == data)
                    return plf;
                plf = (*plf).nextLeaf;
            }
        }
        return NULL;
    }

    void addLeaf(T data)
    {
        pleaf plft_new = new leaf<T>;
        (*plft_new).dadData = data;
        (*plft_new).adjacent = NULL;
        (*plft_new).nextLeaf = NULL;
        sizeTree++;
        if (!ptree)
            ptree = plft_new;
        else
        {
            pleaf ptmp = ptree;
            while ((*ptmp).nextLeaf) // Esto es una validación simplificada
                ptmp = (*ptmp).nextLeaf;
            (*ptmp).nextLeaf = plft_new;
        }
    }

    void addBrach(T dadData, T sonData)
    {

        pleaf plft_dst = searchLeaf(sonData);

        if (!plft_dst)
        {
            cout << "La hoja hijo [" << sonData << "] no existe!" << endl;
            return;
        }

        if (ptree)
        {
            pbranch pbr_new = new branch<T>, pbr_aux;
            (*pbr_new).sonData = sonData;
            (*pbr_new).nextBranch = NULL;
            pleaf plft_src = ptree;
            bool isEdge = false;
            while (plft_src)
            {
                if ((*plft_src).dadData == dadData)
                {
                    pbr_aux = (*plft_src).adjacent;
                    if (pbr_aux == NULL)
                        (*plft_src).adjacent = pbr_new;
                    else
                    {
                        pbranch pedg_tmp = pbr_aux;
                        do
                        {
                            pbr_aux = pedg_tmp;
                            if ((*pbr_aux).sonData == sonData)
                            {
                                isEdge = true;
                                cout << "La rama {" << dadData << "," << sonData << "} ya existe!" << endl;
                                return;
                            }
                            pedg_tmp = (*pedg_tmp).nextBranch;
                        } while (pedg_tmp);
                        (*pbr_aux).nextBranch = pbr_new;
                    }
                    break;
                }
                plft_src = (*plft_src).nextLeaf;
            }

            if (!plft_src)
            {
                cout << "La hoja padre [" << dadData << "] no existe!" << endl;
                return;
            }
        }
    }

    void print()
    {
        print("", ptree);
    }

    void print(string prefix, pleaf plf)
    {
        if (plf)
        {
            cout << prefix;
            cout << (((*plf).nextLeaf) ? "├──" : "└──");
            cout << (*plf).dadData << endl;

            pbranch pbr = (*plf).adjacent;
            pleaf plf_aux = NULL;
            while (pbr)
            {
                plf_aux = searchLeaf((*pbr).sonData);
                print(prefix + (((*plf).nextLeaf) ? "│   " : "    "), plf_aux);
                pbr = (*pbr).nextBranch;
            }
        }
    }

    ~tree()
    {
        if (ptree)
        {
            pleaf plf = ptree, pver_tmp = NULL;
            pbranch pbrc = NULL, pedg_tmp = NULL;
            while (plf)
            {
                pbrc = (*plf).adjacent;
                while (pbrc)
                {
                    pedg_tmp = pbrc;
                    pbrc = (*pbrc).nextBranch;
                    delete pedg_tmp;
                }
                pver_tmp = plf;
                plf = (*plf).nextLeaf;
                delete pver_tmp;
            }
            ptree = NULL;
            sizeTree = 0;
        }
    }
};