#include <iostream>
#include <vector>

using namespace std;

vector<int> A(1000);
vector<int> B(1000);
int main()
{
    int T; cin >> T;

    while(T--)
    {
        int fst = 0;
        int N;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> A[i] >> B[i];
            if (i == 0) fst = A[i];         
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    if (A[i] == A[j])
                    {

                    }
                    else if (A[i] == B[j])
                    {}
                }
            }
        }
    }


    return 0;
}