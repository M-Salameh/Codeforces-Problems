#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()
 
using namespace std;
 
const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,x;
 
pair<int,int> arr[NN];
 
void solve()
{
    sort(arr+1 , arr+n+1);
    string ans = "IMPOSSIBLE";
    arr[n+1] = {inf,inf};
    for (int i=1 ;i<=n ; i++)
    {
        pair<int,int> temp = {x-arr[i].first,0};
        int j = lower_bound(arr+1 , arr+n+2 , temp) - arr;
        int l = arr[i].first;
        int r = arr[j].first;
        if (l + r == x)
        {
            if (arr[j].second == arr[i].second ) continue;
            cout << arr[j].second << " " << arr[i].second << endl;
            return;
        }
    }
    cout << ans << endl;
}
 
 
signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> x;
        for (int i=1,st,en ; i<=n ; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        solve();
    }
 
    return 0;
}
