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
const int NN = 2e5+4;
const int MM = 1e3+1;
const int mod = 1e9+7;
const int Level = 22;
int tc=1;
int n , q;
vector<int> adj[NN];
int segt[4*NN];
int arr[NN];
int brr[NN];
int sub[NN];
int low[NN] , high[NN];
vector<int> dfs_order;

void build(int node=1 , int l=1 , int r=n)
{
    if (l == r)
    {
        segt[node] = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = segt[lc] + segt[rc];
}


int get(int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l ) return 0;
    if (st<=l and en>=r)
    {
        return segt[node];
    }
    int x = get(lc , l , mid , st , en);
    int y = get(rc , mid+1 , r , st , en);
    return  (x + y);
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
    segt[node] =  (segt[lc] + segt[rc]);
}

void dfs(int node=1 , int father=0)
{
    sub[node] = 0;

    for (int child : adj[node])
    {
        if (child == father) continue;
        dfs(child , node);
        sub[node] += 1 + sub[child];
    }
    dfs_order.push_back(node);
}



void solve()
{
    dfs();
    reverse(all(dfs_order));
    int cnt = 1;
    for(int node : dfs_order)
    {
        low[node] = cnt;
        high[node] = cnt + sub[node];
        arr[cnt] = brr[node];
        cnt++;
    }
    build();
    int op , a , b;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            update(1 , 1 ,n , low[a] , b);
        }
        else
        {
            cin >> a;
            cout << get(1 , 1 , n , low[a] , high[a]) << endl;
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
            cin >> brr[i];
        }
        for (int i=2 , u , v ; i<=n ; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
