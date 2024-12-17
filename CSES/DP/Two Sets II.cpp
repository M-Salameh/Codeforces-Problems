#include <bits/stdc++.h>
//#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 5e3+2;
const int mod = 1e9+7;
int tc=1;
int n;
int arr[NN];

int dp[NN*NN];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        int tot = n * (n+1);
        tot /= 2;
        if (tot % 2 == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        int s1 = tot/2;

        dp[0] = 1;
        for (int i=1 ; i<=n-1 ; i++)
        {
            for (int j=s1 ; j >= i ; j--)
            {
                dp[j] += dp[j-i];
                dp[j] %= mod;
                if (dp[j] < 0) dp[j] += mod;
            }
        }

        if (n*(n-1)/2 >= s1-n)
        {
            cout << dp[s1] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}


