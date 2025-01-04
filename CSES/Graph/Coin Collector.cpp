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
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n , m;
vector<int> adj[NN], rev_adj[NN] , scc[NN];
bool vis[NN];
vector<int> dfs_order , rev_dfs_order;
int sum[NN];

void dfs(int src)
{
    if (vis[src]) return;
    vis[src] = true;

    for (int node : adj[src]) dfs(node);

    dfs_order.push_back(src);

}

int comp_sum[NN];
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
    rev_dfs_order.push_back(src);
}

int dp[NN];

void DP (int src)
{
    if (vis[src]) return;

    vis[src] = true;
    ///cout << "src = " << src << endl;
    dp[src] = comp_sum[src];

    for (int comp : scc[src])
    {
        DP(comp);
        ///cout << "from comp " << src << " to comp " << comp << endl;
        dp[src] = max (dp[src] , comp_sum[src] + dp[comp]);
    }
}

void get_ans(int max_id)
{
    /**for (int i=1 ; i<= max_id ; i++)
    {
        cout << "comp " << i << " has sum of " << comp_sum[i] << endl;
    }*/
    for (int i=1 ; i<=max_id ; i++) vis[i] = false;

    int ans = 0;

    for (int i=1 ; i<=max_id ; i++)
    {
        if (not vis[i])
        {
            DP(i);
        }
        ans = max(ans , dp[i]);
    }

    cout << ans << endl;

}


void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        if (not vis[i]) dfs(i);
    }

    for (int i=1 ; i<=n ; i++) vis[i] = false;

    reverse(all(dfs_order));

    int id = 0;
    for (int node : dfs_order)
    {
        if (not vis[node])
        {
            rev_dfs_order.clear();

            rev_dfs(node , ++id);
            for (int v : rev_dfs_order)
            {
                comp_sum[id] += sum[v];
            }
        }
    }
    for (int node = 1 ; node<=n ; node++)
    {
        for (int child : adj[node])
        {
            int id1 = comp_id[node];
            int id2 = comp_id[child];
            if (id1 != id2)
            {
                scc[id1].push_back(id2);
            }
        }
    }

    get_ans(id);

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
        for (int i=1 ; i<=n ; i++) cin >> sum[i];

        int u,v;
        for (int i=1 ; i<=m ; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
