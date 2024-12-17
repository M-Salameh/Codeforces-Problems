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
const int NN = 1e5+3;
const int MM = 102;
const int mod = 1e9+7;
int tc=1;
int n , m;
int arr[NN];
int dp[NN][MM];


void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        if (arr[i])
        {
            dp[i][arr[i]] += dp[i-1][arr[i]];

			if (arr[i] > 1) dp[i][arr[i]] += dp[i-1][arr[i]-1];

			if (arr[i] < m) dp[i][arr[i]] += dp[i-1][arr[i]+1];

			dp[i][arr[i]] %= mod;

            continue;
        }
        for (int j=1; j<=m ; j++)
        {
            dp[i][j] += dp[i-1][j];

            if (j > 1) dp[i][j] += dp[i-1][j-1];

            if (j < m) dp[i][j] += dp[i-1][j+1];

            dp[i][j] %= mod;
        }

    }
    int ans = 0;
    for (int i=1 ; i<=m ; i++)
    {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        if (arr[1] == 0)
        {
            for (int i=1 ; i<=m ; i++) dp[1][i] = 1;
        }
        dp[1][arr[1]] = 1;
        solve();
    }

    return 0;
}

