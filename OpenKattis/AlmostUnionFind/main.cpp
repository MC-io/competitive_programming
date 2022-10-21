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

void move(int a, int b, int * A, int n)
{
    A[a] = b;
}

void unite(int a, int b, int * A, int n)
{
    int pa = find(A[b],A,n);
    A[pa] = find(A[a],A,n);
}
int main()
{
    int * A = new int[100000];
    int n, q;
    while(std::cin >> n >> q)
    {
        for (int i = 0; i <= n; i++)
        {
            A[i] = i;
        }

        int op;
        for (int i = 0; i < q; i++)
        {
            int a, b;
            std::cin >> op;
            if (op == 1)
            {
                std::cin >> a >> b;
                if (find(a,A,n) == find(b,A,n)) continue;
                unite(a,b,A,n);
            }
            else if (op == 2)
            {
                std::cin >> a >> b;
                move(a,b,A,n);
            }
            else
            {
                std::cin >> a;
                int p = find(a,A,n);
                int sum = 0, c = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (find(i,A,n) == p)
                    {
                        std::cout << i << '-';
                        sum += i;
                        c++;
                    }
                }
                std::cout << c << ' ' << sum << '\n';
            }
        }
    }


    return 0;
}