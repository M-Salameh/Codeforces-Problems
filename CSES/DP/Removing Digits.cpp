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


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        int x = n;
        int ans = 0;
        while (x > 0)
        {
            int temp = x;
            int maxi = 0;
            while (temp > 0)
            {
                maxi = max (maxi , temp%10);
                temp /= 10;
            }
            x -= maxi;
            ans ++;
        }
        cout << ans << endl;
    }

    return 0;
}

