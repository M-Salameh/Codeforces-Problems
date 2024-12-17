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
map<int,int> freq;
int ans , sum;


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        ans =  sum = 0;
        freq[0] = 1;
        for (int i = 1 , st; i <= n; i++)
        {
            cin >> st;
            sum += st;
            ans += freq[sum - x];
            freq[sum]++;
        }
        cout << ans << endl;
    }

    return 0;
}
