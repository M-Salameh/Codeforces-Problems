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
const int NN = 2e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m;
int q;
int rooms[NN];
int groups[NN];
int segt[4*NN];


void build(int node , int l , int r)
{
    if (l > r) return;
    if (l == r)
    {
        segt[node] = rooms[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = max (segt[lc] , segt[rc]);
}


void get(int node , int l , int r , int val)
{
    if (l == r)
    {
        segt[node] -= val;
        cout << r << " ";
    }
    else
    {
        if (segt[lc] >= val)
        {
            get(lc , l , mid , val);
        }
        else get(rc , mid+1 , r , val);
        segt[node] = max (segt[lc] , segt[rc]);
    }

}

void solve()
{
    build(1 , 1, n);

    for (int i=1 ; i<=m ; i++)
    {
        if (segt[1] < groups[i]) cout << 0 << " ";
        else get(1 ,1 , n , groups[i]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        //freopen("test_input_tle.txt" , "r" , stdin);
        //freopen("test_output.txt" , "w" , stdout);
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> rooms[i];
        }
        for (int i=1 ; i<=m ; i++) cin >> groups[i];
        solve();
    }

    auto time_end = clock();
    //cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
