#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,m;

int arr[NN];
map<int,int> pos,freq;

void solve()
{
    int ans = 0;
    int p1=1,p2=1;
    while (p1<=p2 and p2<=n)
    {
        if (freq[arr[p2]] == 0)
        {
            freq[arr[p2]]++;
            ans = max (ans , p2-p1+1);
            pos[arr[p2]] = p2;
        }
        else
        {
            for (int i=p1 ; i<=pos[arr[p2]] ; i++)
            {
                freq[arr[i]] = 0;
            }
            p1 = pos[arr[p2]]+1;
            ans = max (ans , p2-p1+1);
            pos[arr[p2]] = p2;
            freq[arr[p1]]=1;
            freq[arr[p2]] = 1;
        }
        p2++;
    }
    cout << ans << endl;
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
            arr[i] = st;
        }
        solve();
    }

    return 0;
}
