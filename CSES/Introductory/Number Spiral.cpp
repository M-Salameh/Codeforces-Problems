#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
int arr[NN];

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        int x , y;
        cin >> x >> y;
        int z = max(x,y);
        z = z*z - (z-1);
        if (x == y)
        {
            cout << z << endl;
            continue;
        }
        if (x > y)
        {
            if (x%2 == 0)
            {
                z += (x-y);
            }
            else z -= (x-y);
            cout << z << endl;
            continue;
        }
        if (y%2 == 0)
        {
            z -= (y-x);
        }
        else z += (y-x);
        cout << z << endl;
    }

    return 0;
}
