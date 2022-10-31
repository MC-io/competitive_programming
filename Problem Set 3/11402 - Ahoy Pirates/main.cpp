#include <iostream>

int max_tree(int * seg_tree, int n, int from, int to)
{
    from += n;
    to += n;

    int max = INT32_MIN;

    while (from < to)
    {
        if ((from & 1) == 1)
        {
            max = std::max(max,seg_tree[from]);
            from++;
        }
        if ((to & 1) == 1)
        {
            to--;
            max = std::max(max, seg_tree[to]);
        }
        from /= 2;
        to /= 2;
    }

    return max;
}


int main()
{
    int n;
    int * arr = new int[n];

    int * seg_tree = new int[n*2];

    for (int i = 0; i < n; i++)
    {
        seg_tree[i + n] = arr[i];
    }
    for (int i = n - 1; i > 0 ; i --)
    {
        seg_tree[i] = std::max(seg_tree[2*i], seg_tree[2*i+1]);
    }
    
    return 0;
}