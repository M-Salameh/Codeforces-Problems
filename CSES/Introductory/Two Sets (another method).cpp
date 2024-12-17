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
vector<int> ans1 , ans2;

void solve()
{
    x /= 2;
    while (n > 0)
    {
        if (x >= n)
        {
            ans1.push_back(n);
            x -= n;
            n--;
            continue;
        }
        ans2.push_back(n);
        n--;
    }
    cout << "YES" << endl;
    cout << ans1.size() << endl;
    for (int& v : ans1) cout << v << " "; cout << endl;
    cout << ans2.size() << endl;
    for (int& v : ans2) cout << v << " "; cout << endl;

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
