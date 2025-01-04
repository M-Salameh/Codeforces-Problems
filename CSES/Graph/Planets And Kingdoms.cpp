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
const int NN = 1e5+1;
const int MM = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , m;

struct edge
{
    int from=0 , to=0 , w=0;

    bool operator < (edge const& other)
    {
        return w < other.w;
    }
};

int vis[NN];
int ans[NN];

vector<int> adj[NN];
vector<int> rev_adj[NN];
vector<int> dfs_order;
vector<int> rev_dfs_order;

void dfs(int node)
{
    if (vis[node]) return;
    vis[node] = true;
    for (int child : adj[node])
    {
        dfs(child);
    }
    dfs_order.push_back(node);
}

void dfs2(int node)
{
    if (vis[node]) return;

    vis[node] = true;

    for (int child : rev_adj[node])
    {
        dfs2(child);
    }

    rev_dfs_order.push_back(node);
}

void solve()
{
    for (int i=1 ; i<=n ; i++) vis[i] = false;
    for (int i=1 ; i<=n ; i++)
    {
        if (not vis[i])
        {
           dfs(i);
        }
    }
    reverse(all(dfs_order));

    for (int i=1 ; i<=n ; i++) vis[i] = false;
    int id = 0;
    for (int i : dfs_order)
    {
        if (not vis[i])
        {
            rev_dfs_order.clear();
            dfs2(i);
            id++;
            for (int node : rev_dfs_order)
            {
                ans[node] = id;
            }
        }
    }
    cout << id << endl;
    for (int i=1 ; i<=n ; i++) cout << ans[i] << " "; cout << endl;
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
        for (int i=1 , u , v ; i<=m ; i++)
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
/**
7 9
1 2
2 3
3 1
3 4
4 5
5 4
6 7
6 3
7 6

6 8
1 2
3 6
6 3
2 3
3 1
3 4
4 5
5 4


*/
