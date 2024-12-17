#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
int m, k;
multiset<int> arr , brr;

void solve()
{
    int ans = 0;
    for (auto ap : arr)
    {
        int temp = ap - k;
        auto cur  = brr.lower_bound(temp);
        if (*cur == inf) break;
        if (*cur > ap + k) continue;
        ans++;
        brr.erase(cur);
    }
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> k;
        for (int i=1 ; i<=n ; i++)
        {
            int x;
            cin >> x;
            arr.insert(x);
        }
        for (int i=1 ; i<=m ; i++)
        {
            int x;
            cin >> x;
            brr.insert(x);
        }
        brr.insert(inf);
        solve();

    }

    return 0;
}
