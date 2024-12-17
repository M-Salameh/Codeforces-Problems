#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+2;
const int mod = 1e9+7;
int tc=1;
int n;

int starting[NN];
int ending[NN];
int price[NN];
int segt[NN*8+5];

int dp[NN];

void update(int node , int l , int r , int& idx , int& val)
{
    if (l>idx or r<idx) return;
    if (l == r)
    {
        segt[node] = val;
        return;
    }
    update(2*node  , l , mid , idx , val);
    update(2*node+1  , mid+1 , r , idx , val);
    segt[node] = max(segt[node*2] , segt[node*2 + 1]);
}

int query(int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l) return 0;
    if (st<=l and r<=en) return segt[node];
    int p1 = query(2*node , l , mid , st , en);
    int p2 = query(2*node+1 , mid+1 , r , st , en);
    return max (p2 , p1);
}


void compress()
{
    map<int,int> tims;
    int cnt = 1;

    for (int i=1 ; i<=n ; i++)
    {
        tims[starting[i]];
        tims[ending[i]];
    }
    for (auto& [compr , id] : tims)
    {
        tims[compr] = cnt++;
    }
    for (int i=1 ; i<=n ; i++)
    {
        starting[i] = tims[starting[i]];
        ending[i] = tims[ending[i]];
    }
}


void solve()
{
    vector<pair<int , pair<int,int>>> v (n+1);
    for (int i=1 ; i<=n ; i++)
    {
        v[i].first = ending[i];
        v[i].second.first = -price[i];
        v[i].second.second = starting[i];
    }

    sort(v.begin() , v.end());

    int m  = n ; n *=2 ; n++;
    int ans = 0;

    for (int i=1 ; i<=m ; i++)
    {
        int from = v[i].second.second;
        int to = v[i].first;
        int pr = -v[i].second.first;

        int max_before = query(1,1,n , 1 , from-1);
        dp[i] = max_before + pr;
        int temp_to = query(1,1,n , to , to);
        if (temp_to<= dp[i]) update(1,1,n,to , dp[i]);
        ans = max (ans , dp[i]);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i=1; i<=n ; i++)
        {
            cin >> starting[i];
            cin >> ending[i];
            cin >> price[i];
        }

        compress();

        solve();

    }
    return 0;
}


