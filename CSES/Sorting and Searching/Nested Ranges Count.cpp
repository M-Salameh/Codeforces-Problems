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
set<pair<int,pair<int,int>>> arr , als;

int ans[NN];

void solve()
{
    ordered_set ls ,rs;

    for (pair<int,pair<int,int>> pr : arr)
    {
        int en = pr.first;
        int st = -pr.second.first;
        int idx = pr.second.second;
        int lb = ls.order_of_key(st);
        ans[idx] = (ls.size() - lb);
        ls.insert(st);
    }

    for (int i=1 ; i<=n ; i++) cout << ans[i] << ' '; cout << endl;

    for (pair<int,pair<int,int>> pr : als)
    {
        int st = pr.first;
        int en = -pr.second.first;
        int idx = pr.second.second;
        int lb = rs.order_of_key(en);
        ans[idx] = (rs.size() - lb);
        rs.insert(en);
    }

    for (int i=1 ; i<=n ; i++) cout << ans[i] << ' '; cout << endl;
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
            arr.insert({en , {-st,i}});
            als.insert({st , {-en,i}});
        }
        solve();

    }

    return 0;
}
