#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
///#define int long long

const long long inf = 1e9+100100;
const int NN = 2e5+3;
int tc=1;
int n,k;
set<pair<pair<int,int>,int>> arr;
multiset<pair<int,int>> min_heap;
int ans[NN];

void solve()
{
    k=1;

    min_heap.insert({0 , 1});

    for (auto& [pr , idx] : arr)
    {
        int l = pr.first; int r = pr.second;
        int min_r = min_heap.begin() -> first;
        int room = min_heap.begin() -> second;
        if (min_r < l)
        {
            ans[idx] = room;
            min_heap.erase(min_heap.begin());
            min_heap.insert({r , room});
        }
        else
        {
            min_heap.insert({r , ++k});
            ans[idx] = k;
        }
    }
    cout << k << endl;
    for (int i=1 ;i<=n ; i++) cout << ans[i] << ' ';
}

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
            arr.insert({{st , en}, i});
        }
        solve();
    }

    return 0;
}
