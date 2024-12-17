#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e9+1;
const int NN = 1e6+3;
const int mod = 1e9+7;
int tc=1;
int n , m;
int arr[NN];
int dp[NN][2];


void solve()
{
    dp[1][0] = dp[1][1] = 1;
    for (int i=2 ; i<NN ; i++)
    {
        dp[i][0] = 4*dp[i-1][0] % mod;
        dp[i][0] += dp[i-1][1] % mod;
        dp[i][1] = 2*dp[i-1][1] % mod;
        dp[i][1] += dp[i-1][0] % mod;
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        solve();
        cin >> n;
        int ans = dp[n][0]%mod + dp[n][1] %mod;
        cout << ans%mod << endl;
    }

    return 0;
}

