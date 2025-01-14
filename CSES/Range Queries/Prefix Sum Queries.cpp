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
int n , q;
int arr[NN];
struct snode
{
    int sum;
    int pref;
    int ans;
    void sett(int x)
    {
        sum = pref = ans = x;
    }
};

snode segt[4*NN];

snode merg(snode& a , snode& b)
{
    snode c;
    c.sum = a.sum + b.sum;
    c.pref = max ({a.pref , a.sum , a.sum + b.pref , a.sum + b.sum});
    c.ans = max({c.sum , c.pref });
    return c;
}

void build(int node=1 , int l =1 , int r = n)
{
    if (l > r) return;
    if (l == r)
    {
        segt[node].sett(arr[r]);
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merg(segt[lc] , segt[rc]);
}

void update(int node , int l , int r , int idx , int val)
{
    if (idx<l or idx>r) return;
    if (l==r)
    {
        segt[node].sett(val);
        return;
    }
    if (idx<=mid) update(lc , l , mid , idx , val);
    else update(rc , mid+1 , r , idx , val);
    segt[node] =  merg(segt[lc] , segt[rc]);
}

snode zero;

snode get (int node , int l , int r , int st , int en)
{
    if (en<l or st>r or st>en) return zero;
    if (st<=l and r<=en)
    {
        return segt[node];
    }
    snode p1 = get(lc , l , mid, st , en);
    snode p2 = get(rc , mid+1 , r, st , en);
    return merg(p1,p2);
}

void solve()
{
    build();
    while (q--)
    {
        int op , a , b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            update(1 ,1 , n , a , b);
        }
        else
        {
            int ans = get(1 , 1, n , a , b).ans;

            cout << (ans < 0 ? 0 : ans) << endl;
        }
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
        ///freopen("test_output.txt" , "w" , stdout);
        cin >> n >> q;
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
