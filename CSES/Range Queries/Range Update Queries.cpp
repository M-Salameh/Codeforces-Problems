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
int n;
int q;

int segt[4*NN];
int arr[NN];

void add (int& a , int& b)
{
    //a %= mod; if (a<0) a+= mod;
    //b %= mod; if (b<0) b+= mod;
    a = a+b;
    ///a %= mod; if (a<0) a+= mod;
}


void propagate(int node , int l , int r)
{
    if (segt[node] == 0) return;
    if (l == r) return;
    if (l<r)
    {
        add (segt[lc] , segt[node]);
        add (segt[rc] , segt[node]);
    }
    segt[node] = 0;

}


void get(int node , int l , int r , int idx)
{
    propagate(node , l , r);
    if (r<l or idx<l or idx>r) return;
    if (l == r)
    {
        arr[idx] += segt[node];
        segt[node] = 0;
        return;
    }
    get(lc , l , mid, idx);
    get(rc , mid+1 , r, idx);
}

void update(int node , int l , int r , int st , int en , int val)
{
    propagate(node,l,r);
    if (en<l or st>r or st>en) return;
    if (st<=l and r<=en)
    {
        segt[node] += val;
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val);
    update(rc , mid+1 , r , st , en , val);
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> q ;
        for (int i=1 ; i<=n ;i++) cin >> arr[i] ;
        ///build();
        while(q--)
        {
            int op;
            cin >> op;
            if (op == 2)
            {
                int k;
                cin >> k ;
                get(1,1,n,k);
                cout << arr[k] << endl;
            }
            else
            {
                int a, b, u;
                cin >> a >> b >> u;
                update(1,1,n,a,b,u);

            }
        }

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
