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

int dp[1001][1 << 10];
int arr[NN];

int add (int a , int b)
{
    a%=mod;
    if (a < 0) a += mod;

    b%=mod;
    if (b < 0) b += mod ;

    a = a+b;
    a %= mod;

    if (a < 0) a += mod;
    return a;
}

void solve(int col , int idx , int cur_mask , int new_mask)
{
    if (idx == n)
    {
        dp[col+1][new_mask] = add(dp[col+1][new_mask] , dp[col][cur_mask]);
        return;
    }

    if (cur_mask & (1 << idx))
    {
        solve(col , idx+1  , cur_mask , new_mask);
    }

    else
    {
        solve(col , idx+1 , cur_mask , new_mask | (1 << idx));
        if (idx+1 < n and (not (cur_mask & (1 << (idx+1))) ))
        {
            solve(col , idx+2 , cur_mask , new_mask);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        memset(dp , 0 , sizeof dp);
        dp[0][0] = 1;
        for (int i=0 ; i<m ; i++)
        {
            for (int mask = 0 ; mask < (1<<n) ; mask++)
            {
                solve(i , 0 , mask , 0);
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}


