// #include <bits/stdc++.h>
// using namespace std;

// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void traverse(vector<int> adj[], int v)
// {
//     for (int i = 0; i < v; i++)
//     {
//         cout << i << ": ";
//         for (auto u : adj[i])
//         {
//             cout << u << " ";
//         }

//         cout << endl;
//     }
// }

// void s_path(vector<int> adj[], int v, int s)
// {
//     int dist[v];
//     for (int i = 0; i < v; i++)
//         dist[i] = INT_MAX;

//     bool visited[v];
//     visited[s] = true;

//     dist[s] = 0;
//     queue<int> q;
//     q.push(s);

//     while (q.empty() == false)
//     {
//         int u = q.front();
//         q.pop();

//         for (auto a : adj[u])
//         {
//             if (visited[a] == false)
//             {
//                 dist[a] = dist[u] + 1;
//                 visited[a] = true;
//                 q.push(a);
//             }
//         }
//     }

//     for (int i = 0; i < v; i++)
//         cout << dist[i] << " ";
// }

// int main()
// {
//     int v = 4;
//     vector<int> adj[v];
//     addEdge(adj, 0, 1);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 2, 3);
//     addEdge(adj, 3, 0);
//     addEdge(adj, 1, 3);

//     //traverse(adj, v);
//     s_path(adj, v, 0);
// }

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void traverse(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        sort(adj[i].begin(), adj[i].end());

        for (auto u : adj[i])
        {
            cout << u << " ";
        }

        cout << endl;
    }
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    traverse(adj, v);
}