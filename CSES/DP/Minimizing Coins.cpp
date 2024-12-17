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

const int_fast64_t inf = 1e18+1;
const int NN = 2e6+3;
const int mod = 1e9+7;
int tc=1;
int n , x;
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
        cin >> n >> x;
        vector<int> coins;
        for (int i=1 ; i<=n ; i++)
        {
            int c; cin >> c;
            coins.push_back(c);
            dp[coins.back()] = 1;
        }
        sort(all(coins));
        for (int i=1 ; i<=x ; i++)
        {
            if (dp[i] == 1) continue;
            dp[i] = inf;
            for (int coin : coins)
            {
                if (coin > i) break;
                dp[i] = min (dp[i] , 1 + dp[i-coin]);
            }
        }
        int ans = (dp[x] == inf ? -1 : dp[x]);
        cout << ans << endl;
    }

    return 0;
}

