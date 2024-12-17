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

const int_fast64_t inf = 2e12+1;
const int NN = 21;
const int mod = 1e9+7;
int tc=1;
int n , k;

pair<int,int> dp[1 << NN];
int arr[NN];

void solve()
{

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        for (int i=0 ;i<n ; i++)
        {
            cin >> arr[i];
        }

        dp[0] = {1,0};

        for (int mask=1 ; mask < (1<<n) ; mask++)
        {
            dp[mask] = {n+5 , 0};
            for (int i=0 ; i<n ; i++)
            {
                if (not (mask & (1<<i))) continue;
                int others = mask ^ (1<<i);
                auto [times , weight] = dp[others];
                if (arr[i] + weight <= k)
                {
                    dp[mask] = min (dp[mask] ,
                                        { times , arr[i]+weight }
                                  );
                }
                else
                {
                    dp[mask] = min (dp[mask] ,
                                        { times+1 , arr[i] }
                                 );
                }

            }

        }
        cout << dp[(1<<n)-1].first << endl;
    }
    return 0;
}


