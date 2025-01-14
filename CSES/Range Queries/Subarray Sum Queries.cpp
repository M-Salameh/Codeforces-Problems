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
const int NN = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , q;
int arr[NN];

struct snode
{
  int seg , pref , suf , sum;
};

snode segt[4*NN];


snode merge(snode& a , snode& b)
{
    snode ans;
    ans.seg = max (a.seg , max(b.seg , a.suf+b.pref));
    ans.pref = max (a.pref , a.sum+b.pref);
    ans.suf = max (b.suf , b.sum+a.suf);
    ans.sum = a.sum + b.sum;
    return ans;
}

void build(int node = 1 , int l = 1 , int r = n)
{
    if (l == r)
    {
        segt[node] = {arr[r] , arr[r] , arr[r] , arr[r]};
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merge(segt[lc] , segt[rc]);
}

void update(int node , int l , int r , int idx)
{
    if (idx < l or idx > r) return;
    if (l == r)
    {
        segt[node] = {arr[idx] , arr[idx] , arr[idx] , arr[idx]};
        return;
    }
    if (idx <= mid) update(lc , l , mid , idx);
    else update(rc , mid+1 , r, idx);
    segt[node] = merge(segt[lc] , segt[rc]);
}

snode zero={-inf , -inf , -inf , -inf};

snode get(int node , int l , int r , int st , int en)
{
    if (en<l or st>r or st>en) return zero;
    if (st<=l and r<=en) return segt[node];

    snode p1 = get(lc , l , mid , st , en);
    snode p2 = get(rc , mid+1 , r , st , en);
    return merge(p1 , p2);
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
        build();
        int idx , val;
        while(q--)
        {
            cin >> idx >> val;
            arr[idx] = val;
            update(1 , 1, n , idx);
            snode f = get(1 ,1 , n , 1 , n);

            int k = max (max(f.seg , f.pref) , max(f.suf , f.sum));
            k = k>=0?k : 0;

            cout << k << endl;
        }
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
