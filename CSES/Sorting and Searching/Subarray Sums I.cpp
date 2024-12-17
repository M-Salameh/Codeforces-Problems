#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid (l+r)/2
#define int long long
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;


const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,x;
int arr[NN] , pref[NN];

void solve()
{
    int ans = 0;
    for (int i = 1 ; i<=n ; i++)
    {
        auto it = lower_bound(pref+i , pref+n+1 , x+pref[i-1]);
        if (*it - pref[i-1] == x) ans ++;
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] + arr[i];
        }
        solve();
    }

    return 0;
}
