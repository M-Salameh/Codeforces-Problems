#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n , m;

multiset<int> prices;
int ans[NN];

void solve()
{

    for (int i=1 ; i <= m ; i++)
    {
        int x; cin >> x;
        ans[i] = -1;
        if (prices.empty()) continue;

        auto cur = prices.lower_bound(x);

        if (cur == prices.end())
        {
            ans[i] = *--prices.end();
            prices.erase(--prices.end());
            continue;
        }

        if (cur == prices.begin() and *cur>x) continue;

        if (cur == prices.begin())
        {
            ans[i] = x;
            prices.erase(cur);
        }

        else
        {
            if (*cur > x)
            {
                ans[i] = *--cur;
                prices.erase(cur);
            }
            else
            {
                ans[i] = *cur;
                prices.erase(cur);
            }
        }
    }
    for (int i=1 ; i<=m ; i++) cout << ans[i] << endl;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            int x;
            cin >> x;
            prices.insert(x);
        }
        solve();
    }

    return 0;
}
