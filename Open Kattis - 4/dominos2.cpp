#include <iostream>
#include <vector>

std::vector<int> A(100001);
std::vector<int> arreglo_en_Caso_De_ciclos_nombre_provisional(100001);

int find(int x, int n)
{
    int tmp = A[x];
    while(A[tmp] != tmp)
    {
        tmp = A[tmp];
    }
    return tmp;
}

void unite(int a, int b, int n)
{
    int pa = find(A[b],n);
    A[pa] = find(A[a],n);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int T;
    int n, m;
    std::cin >> T;
    while(T--)
    {
        std::cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            A[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;
            if (find(a,n) == find(b,n))
            {
                continue;
            }
            else
            {
                unite(a,b,n);
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (A[i] == i)
            {
                count++;
            }
        }
        std::cout << count << '\n';
    }


    return 0;
}