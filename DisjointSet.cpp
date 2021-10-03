#pragma region STUFF
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

#define FOR(i, start, end, inc) for (##i = start;##i < end;##i += inc)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = (a).begin(); it != (a).end(); it++)
#define PI 3.14159f
#define FASTIO                    \
	std::ios::sync_with_stdio(0); \
	cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1'000'000'007;
const int N = 3e5;
#pragma endregion STUFF

#pragma region Helpers
inline int read()
{
	int res = 0, f_f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f_f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) - '0' + ch, ch = getchar();
	return res * f_f;
}
template <class T>
void print(const T &v)
{
	for (auto &x : v)
		cout << x << " ";
	cout << endl;
}

#pragma endregion Helpers

#define N 20
#define M int(1e4 + 5)
// vi adj[N];
//tuple<int, int, int> edges[M];

int parent[N + 1] = {0};
int rank[N + 1] = {0};

void make_set(int v)
{
	parent[v] = v;
	//rank as size of tree
	// rank[v] = 1;

	//rank as depth of tree
	// rank[v] = 0;
}

void Init(int n)
{
	for (int i = 1; i <= n; ++i)
		make_set(i);
}

int find_set(int v)
{
	//Recursive
	// if (v == parent[v])
	// 	return v;
	// return find_set(parent[v]);

	//Iterative
	// while(v != parent[v])
	// 	v = parent[v];
	// return v;

	//Recursive + path compression
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
	// a = find_set(a);
	// b = find_set(b);
	// if (a != b)
	// 	parent[b] = a;

	//Optimization by rank as size
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
	    if (rank[a] < rank[b])
	        std::swap(a, b);
	    parent[b] = a;
	    rank[a] += rank[b];
	}

	//Optimization by rank as depth of tree
	// a = find_set(a);
	// b = find_set(b);
	// if (a != b) {
	//     if (rank[a] < rank[b])
	//         std::swap(a, b);
	//     parent[b] = a;
	//     if (rank[a] == rank[b])
	//         rank[a]++;
	// }
}

void disjoint()
{
	int n = read(), ops = read();
	Init(n);
	for (int i = 0; i < ops; ++i)
	{
		int a = read(), b = read();
		union_sets(a, b);
	}
	//std::sort(parent + 1, parent + n + 1);
	// int setC = 1;
	// for (int i = 1; i <= n;)
	// {
	// 	cout << "\nSet " << setC << ": " << i;
	// 	++setC;
	// 	++i;
	// 	while (i <= n && parent[i] == parent[i - 1])
	// 		cout << " " << i, ++i;
	// }
	for(int i=1; i<=n; ++i)
	{
		cout << i << ": " << find_set(i) << endl;
	}
}

void paintingSubarrays()
{
	int L = read();
	vi ans(L + 1, 0);
	Init(L + 3);
	int m = read();
	//print(parent);
	while (m--)
	{
		//CP-Algo Approach
		// int l = read(), r = read(), c = read();
		// for (int v = find_set(l); v <= r; v = find_set(v))
		// {
		// 	ans[v] = c;
		// 	parent[v] = v + 1;
		// }

		//My Approach
		int l = read(), r = read(), c = read();
		int tmp = find_set(r + 1);
		if (parent[r] != tmp)
		{
			parent[r] = tmp;
			ans[r] = c;
		}
		// for (int v = find_set(l); v >= l && v <= r; v = find_set(v + 1))
		// {
		// 	ans[v] = c;
		// 	parent[v] = parent[r];
		// }
		// for (int v = find_set(r-1); v >= l && v <= r; v = find_set(v - 1))
		// {
		// 	ans[v] = c;
		// 	parent[v] = parent[r];
		// }
	}

	print(ans);
}


int main()
{
	FASTIO;
	paintingSubarrays();
	// disjoint();
}
