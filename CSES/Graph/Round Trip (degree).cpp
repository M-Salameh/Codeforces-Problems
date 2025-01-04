#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> adj[NN];
int parent[NN];
bool vis[NN];
int degree[NN];

bool yes;
pair<int,int> edge;

void dfs(int src , int father = 0)
{
    if (yes) return;
    if (vis[src])
    {
        yes = true;
        edge.first = src;
        edge.second = father;
        return;
    }

    vis[src] = true;
    degree[src] = 1 + degree[father];
    parent[src] = father;

    for (int& child : adj[src])
    {
        if (child == father) continue;
        dfs(child , src);
    }
}

void dfs2(int src , int father)
{
    if (yes) return;
    parent[src] = father;
    if (src == edge.second)
    {
        yes = true;
        return;
    }
    for (int& child : adj[src])
    {
        if (degree[child] > degree[src])
        {
            dfs2(child , src);
        }
    }
}

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        yes = false;
        if (vis[i]) continue;
        dfs(i , 0);
        if (not yes) continue;
        yes = false;
        dfs2(edge.first , 0);
        vector<int> path;
        int last = edge.second;
        while (last)
        {
            path.push_back(last);
            last = parent[last];
        }
        if (path.size() < 3) continue;
        reverse(all(path));
        path.push_back(path[0]);
        cout << path.size() << endl;
        for (int& node : path) cout << node << " ";
        return;

    }
    cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();
    }

    return 0;
}


