#include <iostream>
#include <vector>

int main()
{
    long long N, Q;
    std::vector<std::vector<int>> sets;
    while(std::cin >> N)
    {
        std::cin >> Q;
        for (int i = 0; i < N; i++)
        {
            std::vector<int> v;
            v.push_back(i);
            sets.push_back(v);
        }

        for (int i = 0; i < Q; i++)
        {
            int a, b;
            char op;
            std::vector<int> tmp;
            std::vector<int> tmp2;

            std::cin >> op >> a >> b;

            if (op == '=')
            {
                bool s_flag = false;
                // buscando a
                for (int j = 0; j < sets.size(); j++)
                {
                    // Revisando cada set
                    for (int k = 0; k < sets[j].size(); k++)
                    {
                        if (sets[j][k] == a)
                        {
                            tmp = sets[j];
                            sets.erase(sets.begin() + j);
                            s_flag = true;
                            break;
                        }
                    }
                    if (s_flag) break; 
                }
                s_flag = false; 
                // buscando b
                for (int j = 0; j < sets.size(); j++)
                {
                    // Revisando cada set
                    for (int k = 0; k < sets[j].size(); k++)
                    {
                        if (sets[j][k] == b)
                        {
                            tmp2 = sets[j];
                            sets.erase(sets.begin() + j);
                            s_flag = true;
                            break;
                        }

                    }
                    if (s_flag) break;
                }
                std::vector<int> new_set;
                new_set.reserve(tmp.size() + tmp2.size());
                new_set.insert(new_set.end(), tmp.begin(), tmp.end());
                new_set.insert(new_set.end(), tmp2.begin(), tmp2.end());
                sets.push_back(new_set);
            }
            else
            {
                bool flag = false;
                for (int j = 0; j < sets.size(); j++)
                {
                    bool flaga = false, flagb = false;

                    // Revisando cada set
                    for (int k = 0; k < sets[j].size(); k++)
                    {
                        if (sets[j][k] == a)
                        {
                            flaga = true;
                        }
                        else if (sets[j][k] == b)
                        {
                            flagb = true;
                        }

                    }
                    if (flaga && flagb)
                    {
                        std::cout << "yes\n";
                        flag = true;
                        break;
                    }
                }
                if (!flag) std::cout << "no\n";

            }
        }
    }
    return 0;
}