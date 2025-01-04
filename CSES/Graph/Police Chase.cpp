#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 5e2+1;
const int mod = 1e9+7;
int tc=1;
int n ,m;
int capacity[NN][NN];
int parent[NN];
vector<int> adj[NN];

int Bfs(int src = 1 , int dest = n)
{
    for (int i=1 ; i<=n ; i++) parent[i] = -1;
    parent[src] = 0;
    queue<pair<int,int>> bfs;
    bfs.push({src , inf});
    while (bfs.size())
    {
        auto[node , flow] = bfs.front(); bfs.pop();
        for (int child : adj[node])
        {
            if (capacity[node][child] <= 0) continue;
            if (parent[child] != -1) continue;

            parent[child] = node;
            int new_flow = min (flow , capacity[node][child]);
            if (child == dest)
            {
                return new_flow;
            }
            bfs.push({child , new_flow});
        }
    }
    return 0;

}

int max_flow(int src=1 , int dest=n)
{
    int flow = 0;
    int new_flow = 0;
    while (new_flow = Bfs(src , dest))
    {
        flow += new_flow;
        int cur = dest;
        while (cur != src)
        {
            int par = parent[cur];
            capacity[par][cur] -= new_flow;
            capacity[cur][par] += new_flow;
            cur = par;
        }
    }

    return flow;
}

bool vis[NN];
void dfs(int src=1)
{
    if (vis[src]) return;

    vis[src] = true;

    for (int node : adj[src])
    {
        if (capacity[src][node] > 0) dfs(node);
    }
}

void solve()
{
    int ans = max_flow();
    cout << ans << endl;

    dfs();
    for (int i=1 ; i<=n ; i++)
    {
        if (vis[i])
        {
            for (int j : adj[i])
            {
                if (not vis[j])
                {
                    cout << i << ' ' << j << endl;
                }
            }
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 , u, v , cap; i<=m ; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v]++;
            capacity[v][u]++;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
