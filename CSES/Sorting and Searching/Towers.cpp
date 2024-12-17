#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,m;

multiset<int> arr;

signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        arr.insert(inf);
        for (int i=1,st,en ; i<=n ; i++)
        {
            cin >> st;
            auto lb = arr.upper_bound(st);
            if (*lb == inf)
            {
                arr.insert(st);
                continue;
            }
            arr.erase(lb);
            arr.insert(st);
        }
        cout << arr.size()-1 << endl;
    }

    return 0;
}
