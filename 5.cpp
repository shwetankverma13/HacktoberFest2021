//ASSASSIN'S TEMPLATE

#include <bits/stdc++.h>
using namespace std;

void ans()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    auto x = upper_bound(v.begin(), v.end(), 0);
    int pos = x - v.begin();

    cout << pos;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t = 1;
    //cin>>t;

    while (t--)
    {
        ans();
    }

    return 0;
}