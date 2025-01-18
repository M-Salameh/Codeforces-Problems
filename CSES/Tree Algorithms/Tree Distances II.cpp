#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n;
vector<int> adj[NN];
int ans[NN];
int ans2[NN];
int sub[NN];

void dfs(int node=1 , int father=0)
{
    sub[node] = 1;
    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs(child ,node);
        sub[node] += sub[child];
        ans[node] += ans[child] + (sub[child]);
    }
}

void dfs2(int node=1 , int par = 0)
{
    if (par != 0)
    {
        ans2[node] = ans2[par] + n - sub[node];
        ans2[node] += ans[par] - ans[node] - sub[node];
    }
    for (int& child : adj[node])
    {
        if (child == par) continue;
        dfs2(child , node);
    }
}

void solve()
{
    dfs();

    dfs2();

    for (int i=1; i<=n ; i++) cout << ans2[i]+ans[i] << " "; cout << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        //freopen("test_input.txt" , "r" , stdin);
        //freopen("test_output.txt" , "w" , stdout);
        cin >> n;
        for (int i=2 , u , v ; i<=n ; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
