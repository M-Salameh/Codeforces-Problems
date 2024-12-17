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
 
}
 
 
signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        int ans = -inf;
        for (int i=1,st,en ; i<=n ; i++)
        {
            cin >> arr[i];
            ans = max (ans , arr[i]);
        }
        for (int i=1 ; i<=n ; i++)
        {
            int temp = 0;
            while(temp + arr[i] >= 0 and i<=n)
            {
                temp += arr[i];
                ans = max (ans , temp);
                i++;
            }
        }
        cout << ans << endl;
        ///solve();
    }
 
    return 0;
}