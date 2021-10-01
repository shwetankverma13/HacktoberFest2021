#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    int k;
    cin >> k;

    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    priority_queue<int> p;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cnt < k)
            {
                p.push(mat[i][j]);
                cnt++;
            }
            else
            {
                if (p.top() > mat[i][j])
                {
                    p.pop();
                    p.push(mat[i][j]);
                }
            }
        }
    }

    cout << "Kth smallest element in this matrix is " << endl
         << p.top() << '\n';
}