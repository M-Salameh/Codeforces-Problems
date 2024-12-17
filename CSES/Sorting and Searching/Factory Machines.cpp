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
int n,t;
int arr[NN];

bool check(int x)
{
    int sum = 0;
    for (int i=1 ; i <= n ; i++)
    {
        sum += x/arr[i];
        if (sum >= t)
        {
            return true;
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> t;
        for (int i=1 , st=0 , en=0; i<=n ; i++)
        {
            cin >> arr[i];
        }

        sort(arr+1 , arr+n+1);

        int l = 1; int r = arr[n]*t+1;
        int ans = -1;

        while (l <= r)
        {
            if (check (mid))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
