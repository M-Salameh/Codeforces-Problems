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
int n , x;
int paper[NN];
int price[NN];
int dp[2][100002];

void solve()
{
    int cur = 1;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=0 ; j<=x ; j++)
        {
            dp[cur][j] = dp[1-cur][j];
            if (price[i] <= j)
            {
                dp[cur][j] = max (dp[cur][j] , paper[i] + dp[1-cur][j-price[i]]);
            }
        }
        cur ^= 1;
    }
    cout << dp[1-cur][x] << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> price[i];
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> paper[i];
        }

        solve();
    }

    return 0;
}

