#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int inf = 8e18;
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
        vector<int> nums;
        for(int i=0 ; i< (1<<n); i++)
        {
            ///cout << "i = " << i << " and : " << (i>>1) << "," << (i^(i>>1)) << endl;
            nums.push_back(i^(i/2));
        }
        for (int val : nums)
        {
            ///cout << "Val = " << val << endl;
            for (int i=n-1 ; i>=0 ; i--)
            {
                if ((val & (1<<i))) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
    }

    return 0;
}
