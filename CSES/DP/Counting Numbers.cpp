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
const int NN = 2e5+5;
const int mod = 1e9+7;
int tc=1;
int n , m;
int dp[20];


int solve(int x)
{
    if (x <= 0) return x+1;

    string num = to_string(x);

    int ans = 0;

    for (int i=0 ; i<num.size() ; i++) ans += dp[i];

    int last = 0;
    for (int i=0 ; i<num.size() ; i++)
    {
        int dig = num[i] - '0';
        int rem = num.size() - i - 1;
        int can_take = dig - (last < dig);
        if (dig)
        {
            ans += can_take * dp[rem];
        }
        if (last == dig)
        {
            return ans;
        }
        last = dig;
    }
    return ans+1;

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        memset(dp , 0 , sizeof dp);
        dp[0] = 1;

        for (int i=1 , temp=1 ; i<=18 ; i++)
        {
            temp *= 9;
            dp[i] = temp;
        }

        cout << solve(m) - solve(n-1) << endl;
    }

    return 0;
}


