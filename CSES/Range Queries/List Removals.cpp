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
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n , k;
int arr[NN];
int segt[4*NN];

void build(int node=1 , int l=1 , int r=n)
{
    if (l == r)
    {
        segt[node] = 1;
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = (segt[lc] + segt[rc]);
}


void get(int node , int l , int r , int idx)
{
    if (l > r) return;
    if (l == r)
    {
        cout << arr[r] << " ";
        segt[node] = 0;
        return;
    }

    if (segt[lc] >= idx)
    {
        get (lc , l , mid , idx);
    }
    else get (rc , mid+1 , r , idx-segt[lc]);

    segt[node] = segt[lc] + segt[rc];
}

void solve()
{
    build();
    int idx;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> idx;
        get(1 , 1 , n , idx);
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
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
