#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,m;

int pos[NN],arr[NN];


void solve()
{
    int invs = 1;
    pos[n+1] = inf;
    for (int i=1 ; i<=n ; i++)
    {
        invs += pos[i]>pos[i+1];
    }
    ///cout << "invs = " << invs << endl;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        set<pair<int,int>> pairs;
        pairs.insert({arr[a],arr[a]+1});
        pairs.insert({arr[b],arr[b]+1});
        pairs.insert({arr[a]-1,arr[a]});
        pairs.insert({arr[b]-1,arr[b]});
        for (auto& [i,j] : pairs)
        {
            invs -= pos[i]>pos[j];
        }
        swap(arr[a] , arr[b]);
        pos[arr[a]] = a , pos[arr[b]] = b;

        for (auto& [i,j] : pairs)
        {
            invs += pos[i]>pos[j];
        }

        cout << invs << endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1,st,en ; i<=n ; i++)
        {
            cin >> st;
            arr[i] = st;
            pos[st] = i;
        }
        solve();
    }

    return 0;
}
