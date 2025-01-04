#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
///#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const long long inf = 1e18+1;
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj , int src)
{
    vector<int> dist(n+1 , inf);
    vector<bool> vis (n+1 , false);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;

    pq.push({0 , src});
    while (pq.size())
    {
        auto[cost , node] = pq.top() ; pq.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (auto[child , w] : adj[node])
        {
            int new_dist = dist[node] + w;
            if (new_dist < dist[child])
            {
                dist[child] = new_dist;
                pq.push({-new_dist , child});
            }
        }
    }
    return dist;
}


vector<vector<pair<int,int>>> adj;
vector<vector<pair<int,int>>> rev_adj;

void solve()
{
    vector<int> dist = dijkstra(adj , 1);
    vector<int> rev_dist = dijkstra(rev_adj , n);

    int ans = inf;

    for (int node=1 ; node<=n ; node++)
    {
        if (dist[node] == inf) continue;

        for (auto[child , w] : adj[node])
        {
            if (rev_dist[child] == inf) continue;
            int temp = dist[node] + rev_dist[child] + (w/2);
            ans = min (ans , temp);
        }
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///auto time_Start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        adj = vector<vector<pair<int, int>>> (n+1);
        rev_adj = vector<vector<pair<int, int>>> (n+1);
        for (int i=1 ; i<=m ; i++)
        {
            int u, v , w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            rev_adj[v].push_back({u,w});

        }
        solve();
    }

    ///auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_Start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
