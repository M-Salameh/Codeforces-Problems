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

map<int,vector<pair<int,int>>> pos;

bool check(pair<int,int>&p1 , pair<int,int>& p2)
{
    return p1.first != p2.first
            and
            p1.first != p2.second
            and
            p1.second != p2.first
            and
            p1.second != p2.second;
}


void solve()
{
    string imp = "IMPOSSIBLE";
    arr[n+1] = {inf,inf};
    for (auto& [sum , locs1] : pos)
    {
        int y = x-sum;

        if (pos.find(y) == pos.end()) continue;

        vector<pair<int,int>>& locs2 = pos[y];

        for (pair<int,int>& p1 : locs1)
        {
            for (pair<int,int>& p2 : locs2)
            {
                if (check(p1,p2))
                {
                    cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second;
                    cout << endl;
                    return;
                }
            }
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
        sort(arr+1 , arr+n+1);
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=i+1 ; j<=n ; j++)
            {
                pos[arr[i].first + arr[j].first].push_back({arr[i].second , arr[j].second});
            }
        }
        solve();
    }

    return 0;
}
