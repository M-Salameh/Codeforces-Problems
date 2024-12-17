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

const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,a,b;
int arr[NN] , pref[NN];

void solve()
{
    int ans = -inf;
    multiset<int> mini;
    for (int i = a ; i<=n ;i++)
    {
        if (i > b) mini.erase(mini.find(pref[i-b-1]));
        mini.insert(pref[i-a]);
        ans = max(ans , pref[i] - *mini.begin());
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> a >> b;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] + arr[i];
        }
        solve();
    }

    return 0;
}

