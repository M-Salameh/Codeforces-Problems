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
int n,k;
int sum;
int arr[NN];

bool check(int x)
{
    int parts = 0;
    int pref = 0;
    for (int i=1 ; i<=n ; i++)
    {
        if (arr[i] > x) return false;

        if (pref + arr[i] > x)
        {
            pref = 0;
            parts++;
        }
        pref += arr[i];
    }
    return (parts + (pref > 0)) <= k;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        for (int i = 1 , st; i <= n; i++)
        {
           cin >> arr[i];
           sum += arr[i];
        }
        int l = 1;
        int r = sum;
        int ans = *max_element(arr+1 ,arr+n+1);
        while (l <= r)
        {
            ///cout << "l = " << l << " , r= " << r << endl;
            if (check(mid))
            {
                ///cout <<"checked for x = " << mid << endl;
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
