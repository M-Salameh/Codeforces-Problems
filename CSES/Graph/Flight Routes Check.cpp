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

bool vis[NN];

vector<int> adj[NN];
vector<int> rev_adj[NN];

void dfs(int node=1)
{
    if (vis[node]) return;
    vis[node] = true;
    for (int child : adj[node])
    {
        dfs(child);
    }
}

void dfs2(int node=1)
{
    if (vis[node]) return;
    vis[node] = true;
    for (int child : rev_adj[node])
        dfs2(child);

}

void solve()
{
    for (int i=1 ; i<=n ; i++) vis[i] = false;
    dfs();
    for (int i=1 ; i<=n ; i++)
    {
        if (not vis[i])
        {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }
    for (int i=1 ; i<=n ; i++) vis[i] = false;
    dfs2();
    for (int i=1 ; i<=n ; i++)
    {
        if (not vis[i])
        {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
