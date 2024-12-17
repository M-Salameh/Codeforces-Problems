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

const int_fast64_t inf = 2e9+1;
const int NN = 5000+2;
const int mod = 1e9+7;
int tc=1;
int n , m;
int arr[NN];



signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        vector<vector<int>> dp (n+1 , vector<int> (m+1 , inf));
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=m ; j++)
            {
                if (i == j)
                {
                    dp[i][j] = 0;
                    continue;
                }
                int& ret = dp[i][j];
                for (int k=1 ; k<=j ; k++)
                {
                    ret = min ({ret , 1 + dp[i][k] + dp[i][j-k]});
                }
                for (int k=1 ; k<=i ; k++)
                {
                    ret = min ({ret , 1 + dp[k][j] + dp[i-k][j]});
                }
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}

