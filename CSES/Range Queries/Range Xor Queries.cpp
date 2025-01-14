#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n , k;
int arr[NN];
int sparse[NN][26];
int lg[NN];

int merg(int a, int b)
{
    return  (a ^ b);
}

void build()
{
    for (int i=1; i<=n ; i++)
    {
        sparse[i][0] = arr[i];
    }

    for (int mask = 1; mask <= 25 ; mask ++)
    {
        for (int pos=1; pos + (1 << (mask-1)) <= n ; pos++)
        {
            sparse[pos][mask] = merg(sparse[pos][mask-1] , sparse[pos + (1 << (mask-1))][mask-1] );
        }
    }
}


int get(int l , int r)
{
    int ans = 0;
    for (int mask=25 ; mask >= 0 ; mask--)
    {
        if ((1 << mask) & (r-l+1))
        {
            ans = merg (ans , sparse[l][mask]);
            l += (1 << mask);
        }
    }
    return ans;
}

int get2(int l , int r) /// when overlaps does not matter (gcd , min , max , lcm , or , and )
{
    int r2 = lg[r-l+1];

    return merg(sparse[l][r2] , sparse[r - (1<<r2) + 1][r2]);
}


void solve()
{
    build();

    while (k--)
    {
        int l , r;
        cin >> l >> r;
        cout << get(l , r) << endl;

    }

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input.txt" , "r" , stdin);
        cin >> n >> k;

        for (int i=2 ; i<=n ; i++) lg[i] = lg[i/2]+1;

        for (int i=1; i<=n ; i++)
        {
            cin >> arr[i];
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
