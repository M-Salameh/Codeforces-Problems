#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n,x;
set<int> arr;
multiset<int> ans;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> x >> n;
        ans.insert(x);
        arr.insert(0LL); arr.insert(x);
        for (int i=1 , st=0 , en=0; i<=n ; i++)
        {
            cin >> st;
            auto rb = arr.upper_bound(st);
            int r = *rb;
            int l = *--rb;
            int cur = r - l;

            ans.erase(ans.find(cur));
            ans.insert(r - st);
            ans.insert(st - l);

            arr.insert(st);

            cout << *--ans.end() << " ";
        }
    }

    return 0;
}
