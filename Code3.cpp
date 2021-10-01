#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define loop(i, l, r) for (lli i = l; i < r; i++)
#define rev(i, r, l) for (lli i = r; i >= l; i--)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define inputarray(arr, start, size) \
    loop(i, start, size) { cin >> arr[i]; }
#define printarray(arr, start, size)                \
    loop(i, start, size) { cout << arr[i] << " "; } \
    cout << endl;
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x << endl;
#define pii pair<lli, lli>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define debug(x) cout << #x << " = " << x << endl

int main()
{
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli x;
        vector<lli> v;
        for (lli i = 0; i < n; i++) {
            cin >> x;
            if (i == 0) {
                v.push_back(x);
            }
            else if (x < v.front()) v.insert(v.begin(), x);
            else v.push_back(x);
        }
        printarray(v, 0, n);
    }
    return 0;
}