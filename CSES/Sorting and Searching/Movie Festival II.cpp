#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast32_t

const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,k;
pair<int,int> arr[NN];
int last[NN];

void solve()
{
    int ans = 0;
    multiset<int> last;
    for (int i=1 ; i<=k ; i++) last.insert(ans);

    for (int i=1 ; i<=n ; i++)
    {
        auto it = last.upper_bound(arr[i].second);
        if (it == last.begin()) continue;
        ans++;
        last.erase(--it);
        last.insert(arr[i].first);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        for (int i=1 ; i<=n ; i++)
        {
            int a,b;
            cin >> a >> b;
            arr[i] = {b,a};
        }
        sort(arr+1 , arr+n+1);
        solve();
    }

    return 0;
}

