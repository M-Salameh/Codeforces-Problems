#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()
 
using namespace std;
 
const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
 
pair<int,int> arr[NN];
 
void solve()
{
    int res = 0;
    sort(arr+1 , arr+n+1);
    int temp = -1;
    for (int i=1 ;i<=n ; i++)
    {
        if (arr[i].second < temp) continue;
        temp = arr[i].first;
        res++;
    }
    cout << res << endl;
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
            arr[i] = {en , st};
        }
        solve();
    }
 
    return 0;
}
