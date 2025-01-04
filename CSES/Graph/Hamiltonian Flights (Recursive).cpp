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
const int NN = 21;
const int mod = 1e9+7;
int tc=1;
int n ,m;
vector<int> adj[NN];
int dp[1 << NN][NN];
int tot;

void add (int& a , int& b)
{
    a %= mod; if (a<0) a+=mod;
    b %= mod; if (b<0) b+=mod;
    a = a + b;
    a %= mod;
    if (a < 0) a += mod;

}

int dfs(int node = 0 , int mask = 1)
{
    int& ret = dp[mask][node];
    if (ret + 1) return ret;

    if (node == n-1)
    {
        return ret = (mask == tot);
    }
    ret = 0;
    for (int child : adj[node])
    {
        if (mask & (1 << child) ) continue;
        int temp = dfs(child , mask | (1 << child));
        add (ret , temp);
    }
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 , u, v; i<=m ; i++)
        {
            cin >> u >> v;
            adj[--u].push_back(--v);
        }
        tot = (1 << n) -1;
        for (int i=0 ; i<=n ; i++)
        {
            for (int mask = 0 ; mask<=(1<<n) ; mask++) dp[mask][i] = -1;
        }
        int ans = dfs();
        cout << ans << endl;
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
