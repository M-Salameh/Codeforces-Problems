#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;

multiset<pair<int,int>> arr;

void solve()
{
    int ans = 0 , cur = 0;
    for (auto& [x , val] : arr)
    {
        cur += val;
        ans = max (ans , cur);
    }
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i=1,st,en ; i<=n ; i++)
        {
            cin >> st >> en;
            arr.insert({st , +1});
            arr.insert({en , -1});
        }
        solve();
    }

    return 0;
}
