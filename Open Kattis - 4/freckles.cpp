#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <stdio.h>
#include <algorithm>

#define point pair<double,double>

using namespace std;

vector<point> points(1001);
vector<vector<double>> adj(1001);
vector<int> A(1001);


vector<bool> visited(1001); 

int n;

class Edge
{
public:
    double w;
    int id1;
    int id2;

    Edge(double w,int id1,int id2)
    {
        this->w = w;
        this->id1 = id1;
        this->id2 = id2;
    }

    bool operator <(const Edge &d) const
    {
        return this->w < d.w; 
    }
};

struct less_than_key
{
    inline bool operator() (const Edge& struct1, const Edge& struct2)
    {
        return struct1.w < struct2.w;
    }
};

vector<Edge> edges;

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

double kruskal()
{
    double ink = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        Edge min = edges[i];

        if (find(min.id1) != find(min.id2))
        {
            ink += min.w;
            unite(min.id1, min.id2);
        }

    }
    return ink;

}

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        edges.clear();
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            A[i] = i;
            adj[i].resize(1001);
            adj[i][i] = INT32_MAX;
            double x, y; scanf("%lf%lf", &x, &y);
            points[i] = {x,y};
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                adj[i][j] = sqrt(pow(points[i].first - points[j].first,2) + pow(points[i].second - points[j].second,2));
                adj[j][i] = adj[i][j];

                edges.push_back(Edge(adj[i][j],i,j));
            }
        }

        sort(edges.begin(), edges.end(), less_than_key());
        printf("%.2f\n",kruskal());
        if (T) putchar('\n');
    }

    return 0;
}