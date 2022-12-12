#include <iostream>
#include <vector>
using namespace std;
int lcs(string X, string Y,int m,int n)
{
    vector<vector<int>> L(m + 1);
    for (int i = 0; i < m + 1; i++)
    {
        L[i] = vector<int>(n + 1);
    }
  
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
  
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
  
    return L[m][n];
}
int main()
{
    string str1, str2;
    while(cin >> str1)
    {
        cin >> str2;
        cout << lcs(str1,str2,str1.size(),str2.size()) << '\n';
    }
    
}