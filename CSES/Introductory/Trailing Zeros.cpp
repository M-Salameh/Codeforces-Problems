#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int inf = 8e18;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n;

int power(int a , int x)
{
    if (x == 0) return 1;
    if (x == 1) return a%mod;

    int y = power(a, x/2) % mod;
    int res = (y * y) % mod;
    if (res < 0) res += mod;
    if (x&1)
    {
        res *= a;
        res %= mod;
        if (res < 0) res += mod;
    }
    return res;
}




signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        int ans = 0;
        while (n > 0)
        {
            ans += (n/5);
            n /= 5;
        }
        cout << ans << endl;
    }

    return 0;
}
