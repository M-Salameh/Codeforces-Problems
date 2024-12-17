#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;

signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        queue<int> q;
        for (int i=1 ; i<=n; i++) q.push(i);

        bool take = false;

        while (q.size())
        {
            int x = q.front(); q.pop();
            if (take)
            {
                cout << x << " ";
                take = false;
                continue;
            }
            q.push(x);
            take = true;
        }
        cout << endl;
    }

    return 0;
}
