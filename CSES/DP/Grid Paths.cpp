#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast32_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e18+1;
const int NN = 1e3+3;
const int mod = 1e9+7;
int tc=1;
int n;
int arr[NN][NN];
int dp[NN][NN];

void solve()
{
    for (int i= n ; i>=1 ; i--)
    {
        for (int j=n ; j>=1 ; j--)
        {
            if (arr[i][j] == 0) continue;

            if (arr[i+1][j]) dp[i][j] = dp[i+1][j]%mod;

            if (arr[i][j+1]) dp[i][j] += dp[i][j+1]%mod;

            dp[i][j] %= mod;
        }
    }
    cout << dp[1][1]%mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n ;
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=n ; j++)
            {
                char c;
                cin >> c;
                arr[i][j] = (c == '.' ? 1 : 0);
            }
        }
        dp[n][n] = arr[n][n];
        solve();
    }

    return 0;
}

