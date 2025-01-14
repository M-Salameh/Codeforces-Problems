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
int pref[NN];
 
struct snode
{
   int first,second;
};
 
snode segt[4*NN];
 
snode merg(snode& a, snode& b)
{
    if(a.first > b.first)return a;
    if(b.first > a.first)return b;
    if(a.second > b.second)return a;
    return b;
}
 
void build(int node=1 , int l=1 , int r=n)
{
    if (l == r)
    {
        segt[node] = {arr[r],r};
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merg(segt[lc] , segt[rc]);
}
 
snode get(int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l ) return {-inf,-inf};
    if (st<=l and en>=r)
    {
        return segt[node];
    }
    snode x = get(lc , l , mid , st , en);
    snode y = get(rc , mid+1 , r , st , en);
    return merg(x , y);
}
int sum(int i,int j)
{
    if(i>j)return 0;
    return pref[j]-pref[i-1];
}
 
int dp[NN];
 
void solve()
{
    build();
    stack<pair<int,int>> st;
    st.push({inf , n+1});
 
    for (int i=n ; i>=1 ; i--)
    {
        while (st.size())
        {
            auto [val , idx] = st.top();
            if(val > arr[i])
            {
                st.push({arr[i],i});
 
                dp[i] = dp[idx]+arr[i]*(idx-i)-sum(i,idx-1);
 
                break;
            }
            st.pop();
 
        }
    }
    int l , r;
    snode x;
    int maxx , idx;
    int ans;
    while (q--)
    {
        cin >> l >> r;
        x = get(1,1,n,l,r);
        maxx=x.first,idx=x.second;
        ans = dp[l] - dp[idx] + maxx*(r-idx) - sum(idx+1,r);
        cout << ans << endl;
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
            pref[i] = pref[i-1] + arr[i];
        }
        solve();
 
    }
 
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;
 
    return 0;
}
 