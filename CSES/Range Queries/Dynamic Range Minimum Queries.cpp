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
int segt[4*NN];
 
void build(int node=1 , int l=1 , int r=n)
{
    if (l == r)
    {
        segt[node] = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = min(segt[lc] , segt[rc]);
}
 
int get(int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l ) return inf;
    if (st<=l and en>=r)
    {
        return segt[node];
    }
    int x = get(lc , l , mid , st , en);
    int y = get(rc , mid+1 , r , st , en);
    return  min(x , y);
}
 
 
void update(int node , int l , int r , int idx , int val)
{
    if (idx<l or idx>r) return;
    if (l==r)
    {
        segt[node] = val;
        arr[idx] = val;
        return;
    }
    update(lc , l , mid , idx , val);
    update(rc , mid+1 , r , idx , val);
    segt[node] = min (segt[lc] , segt[rc]);
}
 
void solve()
{
    build();
    while (k--)
    {
        int l , r;
        int op;
        cin >> op;
        cin >> l >> r;
        if (op == 1)
        {
            update(1 , 1, n , l , r);
        }
        else cout << get(1 ,1 , n , l , r) << endl;
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