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

const long long inf = 1e18+1;
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m , k;

vector<vector<pair<int, int>>> adj;
int parent[NN];
int vis[NN];

pair<int,int> cycle;

void dfs(int src , int father = 0)
{
    if (cycle.first != 0) return;
    if (vis[src] == 2) return;
    if (vis[src] == 1)
    {
        cycle.first = src;
        cycle.second = father;
        return;
    }
    vis[src] = 1;
    parent[src] = father;

    for (auto&[child , w] : adj[src])
    {
        dfs(child , src);
    }

    vis[src] = 2;
}

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        cycle = {0,0};
        if (vis[i] == 0)
        {
            dfs(i);
        }
        if (cycle.first) break;
    }
    if (cycle.first == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    path.push_back(cycle.first);
    while(cycle.first != cycle.second)
    {
        path.push_back(cycle.second);
        cycle.second = parent[cycle.second];
    }

    path.push_back(cycle.first);

    reverse(all(path));

    cout << path.size() << endl;
    for (int node : path) cout << node << " ";
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
        adj = vector<vector<pair<int, int>>> (n+1);
        for (int i=1 ; i<=m ; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v,1});

        }
        solve();
    }

    auto time_end = clock();
    //cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_Start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

