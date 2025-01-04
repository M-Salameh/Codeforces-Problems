#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
///#define int long long
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const long long inf = 2e16+1;
const int NN = 2e5+1;
const int mod = 1e9+7;
const int MM = 1e3+1;
int tc=1;
int n , m;
vector<pair<int,int>> adj[NN];
vector<int> dist;
bool vis[NN];

void disjkstra()
{
    dist = vector<int> (n+1 , inf);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0,1});
    while(pq.size())
    {
        auto[cost , node] = pq.top();
        pq.pop();
        cost = -cost;
        if (vis[node]) continue;
        vis[node] = true;
        for (auto&[child,w] : adj[node])
        {
            int new_dist = dist[node] + w;
            if (dist[child] > new_dist)
            {
                dist[child] = new_dist;
                pq.push({-new_dist, child});
            }
        }
    }
}

void solve()
{
    disjkstra();
    for (int i=1 ; i<=n ; i++)
    {
        cout << dist[i] << " ";
    }
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
            adj[u].push_back({v,w});
        }
        solve();
    }

    return 0;
}


