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
const int NN = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , q;
int arr[NN];
const int block_size = 450;
 
struct query
{
    int l, r , block_idx , query_idx;
    query(int _l , int _r, int _id)
    {
        query_idx = _id;
        l = _l;
        r = _r;
        block_idx = l/block_size;
 
    }
    bool operator<(query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
 
 
int res = 0;
vector<query> qu;
int ans[NN];
 
int freq[NN];
 
void add(int idx)
{
    if (freq[arr[idx]] == 0) res++;
    freq[arr[idx]]++;
}
 
void removee (int idx)
{
    freq[arr[idx]]--;
    if(freq[arr[idx]] == 0) res--;
}
 
void MO ()
{
    sort(all(qu));
    int l=0 , r=-1;
    for (query qq : qu)
    {
        while (l > qq.l ) add(--l);
        while (r < qq.r ) add(++r);
        while (l < qq.l ) removee(l++);
        while (r > qq.r ) removee(r--);
        ans[qq.query_idx] = res;
    }
}
 
void solve()
{
    MO ();
 
    for (int i=1 ; i<=q ; i++)
        cout << ans[i] << endl;
 
}
 
void compress()
{
    vector<pair<int,int>> brr;
    for (int i=1 ; i<=n ; i++) brr.push_back({arr[i-1],i-1});
    sort(all(brr));
    int cnt = 1;
    arr[brr[0].second] = 1;
    for (int i=1 ; i<brr.size() ; i++)
    {
        while(brr[i].first == brr[i-1].first and i<brr.size())
        {
            arr[brr[i].second] = cnt;
            i++;
        }
        if (i >= brr.size()) break;
        cnt++;
        arr[brr[i].second] = cnt;
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
            cin >> arr[i-1];
        }
        compress();
 
        for (int i=1 ; i<=q ; i++)
        {
            int l , r;
            cin >> l >> r;
            query qq = query(--l , --r , i);
            qu.push_back(qq);
        }
        solve();
 
    }
 
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;
 
    return 0;
}
 