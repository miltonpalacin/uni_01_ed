#include <iostream>
#include <string>

using namespace std;

template <class T>
struct leaf;

template <class T>
struct branch
{
    branch<T> *nextBranch;
    leaf<T> *sonLeaf;
};

template <class T>
struct leaf
{
    T dadData;
    branch<T> *adjacent;
};

template <class T>
class pureTree
{

public:
    typedef branch<T> *pbranch;
    typedef leaf<T> *pleaf;

private:
    pleaf ptree;
    int sizeTree = 0;

public:
    /* Constructor*/
    pureTree()
    {
        ptree = NULL;
    }

    /* Búsqueda en profundidad */
    pleaf searchLeaf(T data, pleaf plf)
    {
        if (plf)
        {
            if ((*plf).dadData == data)
                return plf;
            pbranch pbr = (*plf).adjacent;
            pleaf plf_aux = NULL;
            while (pbr)
            {
                plf_aux = searchLeaf(data, (*pbr).sonLeaf);
                if (plf_aux)
                    return plf_aux;

                pbr = (*pbr).nextBranch;
            }
        }
        return NULL;
    }

    pleaf searchLeaf(T data)
    {
        return searchLeaf(data, ptree);
    }

    void addRoot(T data)
    {
        if (!ptree)
        {
            pleaf plft_new = new leaf<T>;
            (*plft_new).dadData = data;
            (*plft_new).adjacent = NULL;
            ptree = plft_new;
            sizeTree++;
        }
    }

    void addBrach(T dadData, T sonData)
    {

        pleaf plft_src = searchLeaf(dadData);
        if (!plft_src)
        {
            if (!ptree)
            {
                addRoot(dadData);
                plft_src = ptree;
            }
            else
            {
                cout << "La hoja padre [" << dadData << "] no existe!" << endl;
                return;
            }
        }

        pleaf plft_dst = searchLeaf(sonData);
        if (plft_dst)
        {
            cout << "Ya existe una rama (" << dadData << "," << sonData << ") no existe!" << endl;
            return;
        }

        pbranch pbr_new = new branch<T>;
        (*pbr_new).nextBranch = NULL;

        pleaf plf_new = new leaf<T>;
        (*plf_new).adjacent = NULL;
        (*plf_new).dadData = sonData;
        (*pbr_new).sonLeaf = plf_new;
        sizeTree++;

        pbranch pbr_aux = (*plft_src).adjacent;

        if (pbr_aux)
        {
            while ((*pbr_aux).nextBranch)
                pbr_aux = (*pbr_aux).nextBranch;
            (*pbr_aux).nextBranch = pbr_new;
        }
        else
            (*plft_src).adjacent = pbr_new;
    }

    void print()
    {

        cout << "===========================================" << endl;
        print("", ptree);
        cout << "===========================================" << endl;
    }

    void print(string prefix, pleaf plf)
    {
        if (plf)
        {
            cout << prefix;
            cout << ((!(*plf).adjacent) ? "|----" : "|....");
            cout << (*plf).dadData << endl;

            pbranch pbr = (*plf).adjacent;
            while (pbr)
            {
                print(prefix + "    ", (*pbr).sonLeaf);
                pbr = (*pbr).nextBranch;
            }
        }
    }

    ~pureTree()
    {
        // if (ptree)
        // {
        //     pleaf plf = ptree, pver_tmp = NULL;
        //     pbranch pbrc = NULL, pedg_tmp = NULL;
        //     while (plf)
        //     {
        //         pbrc = (*plf).adjacent;
        //         while (pbrc)
        //         {
        //             pedg_tmp = pbrc;
        //             pbrc = (*pbrc).nextBranch;
        //             delete pedg_tmp;
        //         }
        //         pver_tmp = plf;
        //         plf = (*plf).sonLeaf;
        //         delete pver_tmp;
        //     }
        //     ptree = NULL;
        //     sizeTree = 0;
        // }
    }
};