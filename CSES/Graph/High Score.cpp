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

const long long inf = 2e12+1;
const int NN = 3e3;
const int mod = 1e9+7;
const int MM = 1e4+1;
int tc=1;
int n , m;
struct edge
{
    int src , dest , w;
};
edge edgs[MM];
vector<int> dp;
set<int> sus;
short vis[NN];
vector<int> adj[NN];


void bellman_ford()
{
    dp = vector<int> (n+1 , inf);
    dp[1] = 0;

    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            edge e = edgs[j];

            if (dp[e.src] == inf) continue;

            if (dp[e.dest] > dp[e.src]+e.w)
            {
                dp[e.dest] = e.w + dp[e.src];
            }
        }
    }

    for (int i=1 ; i<=m ; i++)
    {
        edge e = edgs[i];
        if (dp[e.src] == inf) continue;

        int temp = dp[e.dest];
        dp[e.dest] = min(dp[e.dest] , dp[e.src] + e.w);

        if (temp != dp[e.dest]) sus.insert(e.dest);
    }

}

vector<int> path;

void dfs(int src=n , int father = 0)
{
    if (vis[src]) return;

    vis[src] = true;

    path.push_back(src);

    for (int& node : adj[src])
    {
        if (node == father) continue;
        dfs(node , src);
    }
}

void solve()
{
    bellman_ford();

    int ans = (dp[n] == -inf ? -1 : -dp[n]);

    if (sus.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    dfs();

    for (int node : path)
    {
        if (sus.find(node) != sus.end())
        {
            ///cout << node << " in sus " << endl;
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
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
            int u, v , w;
            cin >> u >> v >> w;
            edgs[i] = {u , v , -w};
            adj[v].push_back(u);
        }
        solve();
    }

    return 0;
}

/**
5 7
1 2 3
2 4 100
5 2 -1
3 5 7
1 3 -2
4 1 4
1 5 4

4 5
1 2 1
2 3 1
3 4 1
3 1 -5
4 1 1

4 5
1 2 1
2 3 1
3 2 1
2 4 1
1 4 1
*/
