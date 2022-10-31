#include <iostream>
#include <vector>

class Dims
{
public:
    int w;
    int h;
    Dims()
    {
        this->w = this->h = 0;
    } 

    Dims(int w, int h) 
    {
        this->w = w;
        this->h = h;
    }
};

struct Wgreater
{
    bool operator()( const Dims& lx, const Dims& rx ) const {
        return lx.w < rx.w;
    }
};

struct Hgreater
{
    bool operator()( const Dims& lx, const Dims& rx ) const {
        return lx.h < rx.h && lx.w < rx.w;
    }
};

int main()
{
    int T; std::cin >> T;
    int n;
    std::vector<int> roots;
    roots.push_back(0);
    Dims * dolls = new Dims[n];
    int * parent = new int[n];
    std::vector<int> * sons = new std::vector<int>[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> dolls->w >> dolls->h;
    }

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < roots.size(); k++)
        {
            int t = roots[k];
            if (dolls[t].h < dolls[i].h && dolls[t].w < dolls[i].w)
            {
                roots[k] = i;
                sons[i].push_back(t);
                break;
            }
            while(sons[t].size() != 0)
            {
                bool flag = false;
                for (int j = 0; j < sons[t].size(); j++)
                {
                    // se va arriba
                    if (dolls[sons[t][j]].h < dolls[i].h && dolls[sons[t][j]].w < dolls[i].w)
                    {
                        std::vector<int> tmp = sons[i];
                        sons[i] = sons[t];
                        sons[t] = sons[i];
                    }
                    else if (dolls[sons[t][j]].h > dolls[i].h && dolls[sons[t][j]].w > dolls[i].w)
                    {
                        flag = true;
                        t = sons[t][j];
                        break;
                    }
                }
                if (!flag)
                {
                    sons[t].push_back(i);
                    break;
                }
            }
            if (sons[t].size() == 0) sons[t].push_back(i);
        }
    }







    return 0;
}   