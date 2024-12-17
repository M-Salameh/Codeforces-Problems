#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
int x;
multiset<int> arr;


void solve()
{
    int ans = 0;
    while (arr.size())
    {
        auto temp = arr.begin(); int wi = *temp;
        if (wi >= x)
        {
            ans ++;
            arr.erase(temp);
            break;
        }
        arr.erase(temp);
        if (arr.empty())
        {
            ans ++;
            break;
        }
        auto cur = arr.lower_bound(x-wi);
        ans++;
        if (cur == arr.begin() and *cur+wi>x)
        {
            break;
        }
        if (cur == arr.begin()) arr.erase(cur);
        else
        {
            arr.erase(--cur);
        }
    }
    ans += arr.size();
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        for (int i=1 ; i<=n ; i++)
        {
            int c;
            cin >> c;
            arr.insert(c);
        }
        solve();

    }

    return 0;
}
