#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
int arr[25];


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        int ans = 0;
        int sum = 0;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            ans += arr[i];
        }
        sum = ans;
        for (int i=1 ; i < (1LL<< n) ; i++)
        {
            int temp = 0;
            for (int j=0; j<n ; j++)
            {
                if (i & (1LL << j))
                {
                    temp += arr[j+1];
                }
            }
            ans = min (ans , abs (2*temp - sum));
        }
        cout << ans << endl;
    }

    return 0;
}
