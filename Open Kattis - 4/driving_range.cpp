#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A(1000000);
int n, m;
class Edge
{
public:
    int a;
    int b;
    int dist;
    Edge(int a, int b, int dist)
    {
        this->a = a;
        this->b = b;
        this->dist = dist;
    }
};

vector<Edge> edges;

struct less_than_key
{
    inline bool operator() (const Edge& struct1, const Edge& struct2)
    {
        return struct1.dist < struct2.dist;
    }
};

int find(int x)
{
    if (x == A[x]) return x;
    return A[x] = find(A[x]);
}

void unite(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    A[pa] = pb;
    A[a] = pb;
}   

int kruskal()
{
    int max_edge = INT32_MIN;

    for (int i = 0; i < edges.size(); i++)
    {
        Edge min = edges[i];
        if (find(min.a) != find(min.b))
        {
            if (max_edge < min.dist) max_edge = min.dist;
            unite(min.a, min.b);
        }

    }
    int x = find(0);
    for (int i = 0; i < n; i++)
    {
        if (x != find(i))
        {
            return -1;
        }
    }
    return max_edge;

}

int main()
{
    while (cin >> n)
    {
        cin >> m;
        edges.clear();
        for (int i = 0; i < n; i++)
        {
            A[i] = i;       
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, dis; cin >> a >> b >> dis;
            edges.push_back(Edge(a,b,dis));
        }

        sort(edges.begin(), edges.end(), less_than_key());
        int res = kruskal();
        if (res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
    return 0;
}