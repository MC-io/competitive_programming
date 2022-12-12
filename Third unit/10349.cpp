#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> sweden(40);
vector<vector<int>> bpgraph(40*10);
vector<bool> visited(40*10);
vector<int> match(40*10);

int dfs(int a)
{
    for (auto b : bpgraph[a])
    {   
        if (!visited[b])
        {
            visited[b] = true;
            if (match[b] == -1 || dfs(match[b]))
            {
                match[b] = a;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    int n; cin >> n;
    while(n--)
    {
        bpgraph.clear();
        bpgraph.resize(40*10);
        int h, w; cin >> h >> w;
        int na = 0; // Cuenta numero de lugares de interes
        for (int i = 0; i < h; i++)
        {
            sweden[i] = vector<char>(10);
            for (int j = 0; j < w; j++)
            {
                match[i * w + j] = -1;
                bpgraph[i * w + j].clear();

                cin >> sweden[i][j];
                if (sweden[i][j] == '*')
                {
                    na++;
                    if (i > 0 && sweden[i - 1][j] == '*')
                    {
                        if (i % 2 == 0)
                        {
                            if (j % 2 == 0)
                            {
                                bpgraph[i * w + j].push_back((i -1) * w + j);
                            }
                            else
                            {
                                bpgraph[(i - 1) * w + j].push_back(i * w + j);
                            }
                        }
                        else
                        {
                            if (j % 2 == 0)
                            {
                                bpgraph[(i - 1) * w + j].push_back(i * w + j);
                            }
                            else
                            {
                                bpgraph[i * w + j].push_back((i -1) * w + j);
                            }
                        }
                    }
                    if (j > 0 && sweden[i][j - 1] == '*')
                    {
                        if (i % 2 == 0)
                        {
                            if (j % 2 == 0)
                            {
                                bpgraph[i * w + j].push_back(i * w + j - 1);
                            }
                            else
                            {
                                bpgraph[i * w + j - 1].push_back(i * w + j);
                            }
                        }
                        else
                        {
                            if (j % 2 == 0)
                            {
                                bpgraph[i * w + j - 1].push_back(i * w + j);
                            }
                            else
                            {
                                bpgraph[i * w + j].push_back(i * w + j - 1);
                            }
                        }
                    }
                }
            }
        }

        int ct = 0;
        for (int i = 0; i < h*w; i++)
        {
            for (int j = 0; j < h*w; j++)
            {
                visited[j] = false;
            }
            if (dfs(i)) ct++;
        }
        int residuo = na - (ct * 2);
/*
        for (int i = 0; i < bpgraph.size(); i++)
        {
            if (bpgraph[i].empty()) continue;
            cout << i << " -> ";
            for (auto a: bpgraph[i])
            {
                cout << a << ' ';
            }
            cout << '\n';
        }*/

        cout << ct + residuo << '\n';

    }

    return 0;
}