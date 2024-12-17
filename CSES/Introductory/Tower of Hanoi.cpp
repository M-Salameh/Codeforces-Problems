#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
vector<pair<int,int>> ans;

void solve(int disk = n, int src=1 , int aux = 2 , int dest = 3)
{
    if (disk==1)
    {
        ans.push_back({src , dest});
        return;
    }
    solve(disk-1 , src , dest , aux);
    ans.push_back({src , dest});
    solve(disk-1 , aux , src , dest);
    return;
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        solve();

        cout << ans.size() << endl;
        for (auto&[src , dest] : ans)
        {
            cout << src << " " << dest << endl;
        }
    }

    return 0;
}
