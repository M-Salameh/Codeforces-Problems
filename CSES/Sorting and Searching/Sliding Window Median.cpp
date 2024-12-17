#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,k;
int arr[NN];

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
        }
        ordered_set ms;
        for (int i=1 ; i <= k ; i++) ms.insert(arr[i]);
        cout << *ms.find_by_order((k-1)/2) << " ";
        for (int i=k+1 ; i<=n ; i++)
        {
            ms.erase(ms.lower_bound(arr[i-k]-1));
            ms.insert(arr[i]);
            cout << *ms.find_by_order((k-1)/2) << " ";
        }
    }

    return 0;
}
