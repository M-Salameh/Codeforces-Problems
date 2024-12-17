#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
int odd , even , x;
set<int> ans;
set<int> ans2;
void solve()
{
    for (int i=1 ; i<=n ; i+=2)
    {
        ans.insert(i);
        ans2.insert(i);
        if (i+1 <= n) ans2.insert(i+1);
    }
    if (odd > even)
    {
        x = odd - even;
        x /= 2;
        if (x&1)
        {
            ans.erase(x);
        }
        else
        {
            int y = 1;
            int c = 2*x - 1;
            ans.erase(y); ans.erase(c);
            ans.insert(x);
        }
    }
    else if (even > odd)
    {
        x = even - odd;
        x /= 2;
        if (x&1)
        {
            int y = 1;
            ans.erase(y);
            ans.insert(x+1);
        }
        else
        {
            ans.insert(x);
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto& i : ans)
    {
        cout << i << " ";
        ans2.erase(i);
    }
    cout << endl;

    cout << ans2.size() << endl;
    for (auto& i : ans2)
    {
        cout << i << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        x = n*(n+1)/2;
        if (x&1 or n<=2)
        {
            cout << "NO" << endl;
            continue;
        }
        odd = (n+1)/2; odd *= odd;
        even = x - odd;
        solve();

    }

    return 0;
}
