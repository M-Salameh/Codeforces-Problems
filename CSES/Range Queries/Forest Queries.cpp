#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , m;
int q;


int arr[NN][NN];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> q ;
        m = n;
        for (int i=1 ; i<=n ;i++)
        {
            char c;
            for (int j=1 ; j<=m ; j++)
            {
                cin >> c;
                arr[i][j] = (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
                if (c == '*') arr[i][j]++;
            }
        }
        while(q--)
        {
            int x1 ,x2 , y1 , y2;
            cin >> x1 >> y1 >> x2 >> y2 ;
            int ans = arr[x2][y2] + arr[x1-1][y1-1];

            ans -= arr[x2][y1-1];
            ans -= arr[x1-1][y2];
            cout << ans << endl;
        }

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
