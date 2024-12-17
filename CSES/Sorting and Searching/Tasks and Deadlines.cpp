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
int n;
pair<int,int> arr[NN];


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i=1 , st=0 , en=0; i<=n ; i++)
        {
            cin >> st >> en;
            arr[i] = {st , en};
        }
        sort(arr+1 , arr+n+1);
        int ans = 0 , sum = 0;
        for (int i=1 ; i<=n ; i++)
        {
            sum += arr[i].first;
            ans += arr[i].second - sum;
        }
        cout << ans << endl;

    }

    return 0;
}
