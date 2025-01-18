#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
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
int dp[NN][2];

void dfs(int node=1 , int father=0)
{
    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs(child ,node);
    }

    for (int& child : adj[node])
    {
        if (child == father) continue;
        dp[node][0] += max(dp[child][0] , dp[child][1]);
    }

    for (int& child : adj[node])
    {
        if (child == father) continue;
        dp[node][1] = max(dp[node][1] ,
                          1 + dp[child][0] + dp[node][0] - max(dp[child][0] , dp[child][1]));
    }

}

void solve()
{
    dfs();

    cout << max(dp[1][0]  , dp[1][1]) << endl;
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
