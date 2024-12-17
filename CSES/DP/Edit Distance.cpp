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
const int NN = 5000+2;
const int mod = 1e9+7;
int tc=1;
int n , m;
int arr[NN];
string a,b;
int dp[NN][NN];

int solve(int i=n , int j=m)
{
    if (i == 0) return j;
    if (j == 0) return i;

    int& ret = dp[i][j];
    if (ret + 1)
    {
        return ret;
    }
    if (a[i] == b[j])
    {
        return dp[i][j] = solve(i-1 , j-1);
    }
    int add = solve(i-1 , j);
    int rem = solve(i , j-1);
    int del = solve(i-1 , j-1);
    return ret = 1 + min({add , rem , del});
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> a;
        cin >> b;
        n = a.size();
        m = b.size();
        a = "@" + a;
        b = "@" + b;
        memset(dp , -1 , sizeof dp);
        cout << solve() << endl;

    }

    return 0;
}
/*
TWXFUABGBNLTBFNSUVQW
GPNJILFXJUIZPLTVUIB

LOVE
MOVIE
*/
