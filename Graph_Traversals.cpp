#pragma region STUFF
#include <bits/stdc++.h>
using namespace std;

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
#define FASTIO               \
	ios::sync_with_stdio(0); \
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

void print(const char *m)
{
	cout << m << endl;
}

void print(string &m)
{
	cout << m << endl;
}

#pragma endregion Helpers

class GraphADJ
{
#define UNDIRECTED
#define ONEINDEXED
#define N 20 //Max no. of Nodes
private:
	vector<int> adj[N];
	bool visited[N];
	int V, E;

private:
	void dfsUtil(int s)
	{
		if (visited[s])
			return;
		visited[s] = true;
// process node s
#ifdef ONEINDEXED
		cout << (s + 1) << " ";
#else
		cout << s << " ";
#endif
		for (auto &u : adj[s])
		{
			dfsUtil(u);
		}
	}

	void Print(const vi &v)
	{
		for (auto &x : v)
#ifdef ONEINDEXED
			cout << (x + 1) << " ";
#else
			cout << x << " ";
#endif
		cout << endl;
	}

public:
	GraphADJ()
	{
		print("Empty Graph made");
	}

	GraphADJ(int n, int e) : V(n), E(e)
	{
		print("Graph made");
		// for (int i = 0; i < n; ++i)
		// {
		// 	adj[i].emplace_back(i);
		// }
		for (int i = 0; i < E; ++i)
		{
			int a = read(), b = read();
#ifdef ONEINDEXED
			--a, --b;
#endif
			adj[a].emplace_back(b);
#ifdef UNDIRECTED
			adj[b].emplace_back(a);
#endif
		}
	}

	void dfs(int s)
	{
#ifdef ONEINDEXED
		--s;
#endif

		cout << "DFS: ";
		memset(visited, 0, V * sizeof(bool));
		dfsUtil(s);
	}

	void bfs(int s)
	{
#ifdef ONEINDEXED
		--s;
#endif
		cout << "BFS: ";
		memset(visited, 0, V * sizeof(bool));
		queue<int> q;
		int distance[N];

		visited[s] = true;
		distance[s] = 0;
		q.push(s);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			// process node x
#ifdef ONEINDEXED
			cout << (x + 1) << " ";
#else
			cout << x << " ";
#endif
			for (auto u : adj[x])
			{
				if (visited[u])
					continue;
				visited[u] = true;
				distance[u] = distance[x] + 1;
				q.push(u);
			}
		}
	}

	void Print()
	{
		cout << "\nGraph:\n";
		for (int i = 0; i < V; ++i)
		{
#ifdef ONEINDEXED
			cout << "Node " << (i + 1) << ": ";
#else
			cout << "Node " << i << ": ";
#endif
			Print(adj[i]);
		}
		cout << endl;
	}

	// const vector<int> * operator->() const
	// {
	// 	return adj;
	// }
};

int main()
{
	FASTIO
	int V = read(), E = read();
	GraphADJ a[2] = {GraphADJ(V, E)};

	a[0].Print();
	a[0].bfs(1);
}