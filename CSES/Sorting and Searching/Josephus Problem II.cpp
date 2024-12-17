#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,k;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        ordered_set arr;
        for (int i=1 , st=0 , en=0; i<=n ; i++)
        {
            arr.insert(i);
        }
        int idx = 0;
        while (n > 0)
        {
            idx += k;
            idx %= n;
            auto ans = arr.find_by_order(idx);
            cout << *ans << " ";
            arr.erase(ans);
            n--;
        }
    }

    return 0;
}
