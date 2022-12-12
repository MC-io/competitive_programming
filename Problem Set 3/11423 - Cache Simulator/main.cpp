#include <iostream>
#include <list>
int caches_size[50];
int misses[50];
std::list<int> caches[50];

int add(std::list<int> & cache, int n, int val, int & misses)
{
    bool flag = false;
    for (std::list<int>::iterator it = cache.begin(); it != cache.end(); ++it)
    {
        if (*it == val)
        {
            flag = true;
            cache.erase(it);
            cache.push_front(val);
            break;
        }
    }
    if (!flag && cache.size() < n)
    {
        misses++;
        cache.push_front(val);
    }
    else if (!flag)
    {
        misses++;
        if (!cache.empty())cache.pop_back();
        cache.push_front(val);
    }
}


int main()
{
    int N;
    std::cin >> N;


        for (int i = 0; i < N; i++)
        {
            std::cin >> caches_size[i];
            misses[i] = 0;
            caches[i].clear();
        }

        std::string op;
        std::cin >> op; 

        while(op != "END")
        {
            if (op == "ADDR")
            {
                int val;
                std::cin >> val;
                for (int i = 0; i < N; i++)
                {
                    add(caches[i], caches_size[i], val, misses[i]);
                }
            }
            else if (op == "RANGE")
            {
                int b, y, n;
                std::cin >> b >> y >> n;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < n; j++)
                        add(caches[i], caches_size[i], b + y * j, misses[i]);
                }
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    std::cout << misses[i] << ' ';
                    misses[i] = 0;
                }
                std::cout << '\n';
            }
            std::cin >> op;
        }


    return 0;
}