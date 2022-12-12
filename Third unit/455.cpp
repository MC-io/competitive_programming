#include <iostream>
#include <string>

using namespace std;
int main()
{
    int N; cin >> N;

    while(N--)
    {
        string word; cin >> word;
        int k = 1;
        bool flag2 = true;
        while(k <= word.size() / 2)
        {
            if (word.size() % k != 0)
            {
                k++;
                continue;
            }
            string substr = word.substr(0,k);
            bool flag = true;
            for (int i = 0; i < word.size(); i += k)
            {
                if (substr != word.substr(i,k))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << k << '\n';
                if (N > 0) cout << '\n';
                flag2 = false;
                break;
            }

            k++;
        }
        if (flag2)
        {
            cout << word.size() << '\n';
            if (N > 0) cout << '\n';
        }
    }   

    return 0;
}