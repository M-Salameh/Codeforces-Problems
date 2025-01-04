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

const int_fast64_t inf = 1e15+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n , m;
vector<int> adj[NN], rev_adj[NN];
bool vis[NN];
vector<int> dfs_order , rev_dfs_order;

void dfs(int src)
{
    if (vis[src]) return;
    vis[src] = true;

    for (int node : adj[src]) dfs(node);

    dfs_order.push_back(src);

}

int comp_id[NN];

void rev_dfs(int src , int& id)
{
    if (vis[src]) return;

    vis[src] = true;

    comp_id[src] = id;

    for (int node : rev_adj[src])
    {
        rev_dfs(node , id);
    }

}

void solve()
{
    for (int i=1 ; i<=2*m ; i++)
    {
        if (not vis[i]) dfs(i);
    }

    for (int i=1 ; i<=2*m ; i++) vis[i] = false;

    reverse(all(dfs_order));

    int id = 0;
    for (int node : dfs_order)
    {
        if (not vis[node]) rev_dfs(node , ++id);
    }
    vector<char> ans;

    for (int i=1 ; i<=m ; i++)
    {
        if (comp_id[i] == comp_id[2*m-i+1])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        ans.push_back(comp_id[i]>comp_id[2*m-i+1] ? '+' : '-');
    }

    for (char c : ans) cout << c << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        int u,v;
        char x,y;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> x >> u >> y >> v;
            if (x == '-') u = 2*m - u + 1;
            if (y == '-') v = 2*m - v + 1;

            adj[2*m-u+1].push_back(v);
            adj[2*m-v+1].push_back(u);

            rev_adj[u].push_back(2*m-v+1);
            rev_adj[v].push_back(2*m-u+1);

        }

        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
