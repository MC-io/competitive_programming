#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A(100);
vector<int> B(100);
vector<vector<int>> C(200);
vector<bool> visited(200);
vector<int> match(200);

int ct;

int dfs(int a)
{
    for (auto b : C[a])
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
    int T; cin >> T;
    ct = 0;
    for (int t = 0; t < T; t++)
    {
        ct = 0;
        A.resize(100);
        B.resize(100);
        match.resize(200);
        visited.resize(200);
        C.clear();
        C.resize(200);

        int n, m; 
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i]; 
        } 
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> B[i]; 
        }
        //sort(A.begin(), A.end());
        //sort(B.begin(), B.end());

        for (int i = 0; i < m; i++)
        {
            match[i] = -1;
            visited[i] = false;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[j] == 0 && B[i] != 0) continue;
                else if (B[i] == 0 || B[i] % A[j] == 0)
                {
                    C[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[j] = false;
            }
            if (dfs(i)) ct++;
        }
        cout << "Case " << t + 1 << ": " << ct << '\n';
        ct = 0;
    }


    return 0;
}