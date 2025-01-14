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

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , m , q;
struct snode
{
    int sum = 0;
    int reset = 0;
    int add = 0;
};

snode zero = {0 , 0 , 0};
snode segt[4*NN];
int arr[NN];

snode merg(snode& a , snode& b)
{
    snode ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

void build (int node = 1 , int l = 1 , int r = n)
{
    if (l>r) return;
    if (l == r)
    {
        segt[node] = {arr[r] , 0 , 0};
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);
    segt[node] = merg(segt[lc] , segt[rc]);
    return;
}

void propagate(int node , int l , int r)
{
    if (segt[node].reset)
    {
        if (l < r)
        {
            segt[lc].reset = (segt[node].reset);
            segt[lc].add = 0;
            segt[rc].reset = (segt[node].reset);
            segt[rc].add = 0;
        }
        segt[node].sum = (segt[node].reset * (r-l+1));
        segt[node].reset = 0;
    }
    if (segt[node].add)
    {
        if (l<r)
        {
            segt[lc].add += (segt[node].add);
            segt[rc].add += (segt[node].add);
        }
        segt[node].sum += segt[node].add * (r-l+1);
        segt[node].add = 0;
    }
    return;
}

int get(int node , int l , int r , int st , int en)
{
    propagate(node , l , r);
    if (st>en or st>r or en<l) return 0;
    if (st<=l and r<=en)
    {
        return (segt[node].sum);
    }
    int p1 = get(lc , l , mid , st , en) ;
    int p2 = get(rc , mid+1 , r , st , en);
    segt[node].sum = segt[lc].sum + segt[rc].sum;
    return (p1 + p2);

}

void update(int node , int l , int r , int st , int en , int val , bool incr)
{
    propagate(node,l,r);
    if (en<l or st>r or st>en) return;
    if (st<=l and r<=en)
    {
        if (incr)
        {
            segt[node].add += val;
        }
        else
        {
            segt[node].add = 0;
            segt[node].reset = val;
        }
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val , incr);
    update(rc , mid+1 , r , st , en , val , incr);
    segt[node].sum = segt[lc].sum + segt[rc].sum;
    return;
}

void solve()
{
    build();
    int op , a ,b , x;
    while (q--)
    {
        cin >> op >> a >> b;
        if (op == 3)
        {
            cout << get(1,1,n,a,b) << endl;
        }
        else
        {
            cin >> x;
            bool f = (op==1);
            update(1 , 1, n , a , b , x , f);
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
        //freopen("test_input.txt" , "r" , stdin);
        //freopen("test_output.txt" , "w" , stdout);
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
