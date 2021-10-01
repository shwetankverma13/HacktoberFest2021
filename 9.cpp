#include <bits/stdc++.h>
using namespace std;

void ans()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    sort(arr, arr + n);

    int l = 0, h = n - 1;
    while (l < h)
    {
        if (arr[l] + arr[h] == sum)
        {
            cout << arr[l] << " " << arr[h] << endl;
            return;
        }

        else if (arr[l] + arr[h] < sum)
            l++;

        else
            h--;
    }

    cout << "NO PAIRS AVAILABLE!";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t = 1;
    //cin >> t;

    while (t--)
    {
        ans();
    }

    return 0;
}