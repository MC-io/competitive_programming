#include <iostream>

int find(int x, int * A, int n)
{
    int tmp = A[x];
    while(A[tmp] != tmp)
    {
        tmp = A[tmp];
    }
    return tmp;
}

void unite(int a, int b, int * A, int n)
{
    int pa = find(A[b],A,n);
    A[pa] = find(A[a],A,n);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int * A = new int[1000000];
    int n, q;
    while(std::cin >> n >> q)
    {
        for (int i = 0; i < n; i++)
        {
            A[i] = i;
        }

        char op;
        for (int i = 0; i < q; i++)
        {
            int a, b;
            std::cin >> op;
            std::cin >> a >> b;
            if (op == '?')
            {
                if (find(a,A,n) == find(b,A,n))
                {
                    std::cout << "yes\n";
                }
                else std::cout << "no\n";
            }
            else
            {
                unite(a,b,A,n);
            }
        }
    }


    return 0;
}