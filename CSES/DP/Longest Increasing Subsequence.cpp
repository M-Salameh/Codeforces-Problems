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
const int NN = 2e5+2;
const int mod = 1e9+7;
int tc=1;
int n;
int arr[NN];

int dp[NN];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        vector<int> ans;
        ans.push_back(arr[1]);

        for (int i=2 ; i<=n ; i++)
        {
            if (arr[i] > ans.back())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                int temp = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[temp] = arr[i];
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}


