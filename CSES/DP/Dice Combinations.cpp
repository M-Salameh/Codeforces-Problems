#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e18+1;
const int NN = 2e6+3;
const int mod = 1e9+7;
int tc=1;
int n;
int dp[NN];

void solve()
{

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n ;
        dp[0] = 1;
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j <= min (i,6) ; j++)
            {
                dp[i] += dp[i-j] % mod;
                dp[i] %= mod;
                dp[i] += mod;
                dp[i] %= mod;
            }
        }
        cout << dp[n] << endl;
    }

    return 0;
}

