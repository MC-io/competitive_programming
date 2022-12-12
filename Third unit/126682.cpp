#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> table(100);
vector<bool> visited(100*100);
vector<int> match(100*100);
vector<vector<int>> bpgraph(100*100);


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

class Line
{
public:
    int start;
    int end;
    int k;

    Line(int start, int end, int k)
    {
        this->start = start;
        this->end = end;
        this->k = k;

    }
};

vector<Line> rows;
vector<Line> cols;

int main()
{
    int N;
    while (cin >> N)
    {
        rows.clear();
        cols.clear();
        for (int i = 0; i < N; i++)
        {
            table[i] = vector<char>(100);
            for (int j = 0; j < N; j++)
            {
                cin >> table[i][j]; 
                bpgraph[i * N + j].clear();
                match[i * N + j] = -1;
            }
        }
        for (int i = 0; i < N; i++)
        {
            int size = 0;
            int start = 0;
            int end = -1;
            for (int j = 0; j < N; j++)
            {
                if (table[i][j] == 'X' || j == N - 1)
                {
                    if (j == N -1 && table[i][j] != 'X')
                    {
                        end++;
                        size++;
                    }
                    if (size > 0) rows.push_back(Line(start, end, i));
                    start = j + 1;
                    end = j;
                    size = 0;
                }
                else
                {
                    size++;
                    end++;
                }
            }
        }


        for (int i = 0; i < N; i++)
        {
            int size = 0;
            int start = 0;
            int end = -1;
            for (int j = 0; j < N; j++)
            {
                if (table[j][i] == 'X' || j == N - 1)
                {
                    if (j == N -1 && table[j][i] != 'X')
                    {
                        end++;
                        size++;
                    }
                    if (size > 0) cols.push_back(Line(start, end, i));
                    start = j + 1;
                    end = j;
                    size = 0;
                }
                else
                {
                    size++;
                    end++;
                }
            }
        }
        for (auto a: rows)
        {
            for (auto b: cols)
            {
                if ((a.k >= b.start && a.k <= b.end) && (b.k >= a.start && b.k <= a.end))
                {
                    bpgraph[(a.k * N) + a.start].push_back(b.k * N + b.start);
                }
            }
        }/*
        for (auto a: rows)
        {
            cout << a.k << ' ' << a.start << '\n';
        }
        
        for (auto a: cols)
        {
            cout << a.start << ' ' << a.k << '\n';
        }
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
        int ct = 0;
        for (int i = 0; i < N*N; i++)
        {
            for (int j = 0; j < N*N; j++)
            {
                visited[j] = false;
            }
            if (dfs(i)) ct++;
        }
        cout << ct << '\n';
    }
    return 0;
}