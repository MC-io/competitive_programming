#include <iostream>

int sum(int * bit_arr, int idx)
{
    if (idx == 1) return 0;
    int res = 0;
    while (idx)
    {
        res += bit_arr[idx];
        idx -= idx & -idx;
    }
    return res;
}


void add(int * bit_arr, int n, int idx, int val)
{
    while(idx < n)
    {
        bit_arr[idx] += val;
        idx += idx & -(idx);
        if (idx == 0) break;
    }
}

int main()
{
    int n, q;
    while (std::cin >> n >> q)
    {
        int * bit_arr = new int [n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            bit_arr[i] = 0;
        }
        char op;
        for (int i = 0; i < q; i++)
        {
            std::cin >> op;
            if (op == '?')
            {
                int idx;
                std::cin >> idx;
                std::cout << sum(bit_arr,idx + 1) << '\n';
            }
            else
            {
                int idx, val;
                std::cin >> idx >> val;
                add(bit_arr,n + 2, idx + 1, val);
            }
        }
    }

}