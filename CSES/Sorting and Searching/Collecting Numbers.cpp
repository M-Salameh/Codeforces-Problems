#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,x;

int arr[NN];

void solve()
{
    int ans[n+1] = {0};
    ans[n] = 1;
    for (int i=n-1 ; i>=1 ; i--)
    {
        ans[i] = ans[i+1];
        ans[i] += arr[i]>=arr[i+1];
    }
    cout << ans[1] << endl;
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
            cin >> st;
            arr[st] = i;
        }
        solve();
    }

    return 0;
}
