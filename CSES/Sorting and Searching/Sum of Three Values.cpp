#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mid (l+r)/2

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,x;
pair<int,int> arr[NN];

void solve()
{
    sort(arr+1 , arr+n+1);
    string imp = "IMPOSSIBLE";
    arr[n+1] = {inf,inf};
    for (int i=1 ;i<=n ; i++)
    {
        int y = x-arr[i].first;

        int l = 1 , r = n;
        while (l != r)
        {
            if (l != i and r != i and arr[l].first + arr[r].first == y)
            {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << endl;
                return;
            }
            if (arr[l].first + arr[r].first < y) l++;
            else r--;
        }
    }
    cout << imp << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].first; arr[i].second = i;
        }
        solve();
    }

    return 0;
}
