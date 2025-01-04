#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const long long inf = 1e18+1;
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m , k;

vector<vector<int>> adj;
int parent[NN];
int dist[NN];
int degree[NN];

void solve()
{
    queue<int> bfs;
    for (int i=1 ; i<=n ; i++)
    {
        dist[i] = 0;
        if (degree[i] == 0)
        {
            bfs.push(i);
        }
    }
    dist[1] = 1;

    while (bfs.size())
    {
        int node = bfs.front();
        bfs.pop();
        ///cout << "in node : " << node << endl;
        for (int& child : adj[node])
        {
            int temp = dist[node] + 1;

            degree[child]--;

            if (degree[child] == 0)
            {
                ///cout << "inserting child : " << child << endl;
                bfs.push(child);
            }

            if (temp > dist[child] and dist[node]>0)
            {
                ///cout << "updating child : " << child << " : " << dist[child] << " -> " << temp << endl;
                dist[child] = temp;
                parent[child] = node;
            }
        }
    }

    if (dist[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    stack<int> path;
    int x = n;
    while (x)
    {
        path.push(x);
        x = parent[x];
    }
    cout << path.size() << endl;
    while (path.size())
    {
        cout << path.top() << " ";
        path.pop();
    }

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_Start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        adj = vector<vector<int>> (n+1);
        for (int i=1 ; i<=m ; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            degree[v]++;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_Start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

/**
10 10
2 6
1 2
4 6
5 6
2 5
7 8
6 10
1 10
3 5
4 9
*/
