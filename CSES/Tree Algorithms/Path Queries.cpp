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
int arr[NN];
int brr[NN];
int sub[NN];
int low[NN] , high[NN];
vector<int> dfs_order;
struct snode
{
    int sum = 0;
    int add = 0;
};

snode zero = {0 , 0};
snode segt[NN*4];
void propagate(int node , int l , int r)
{
    if (segt[node].add)
    {
        if (l<r)
        {
            segt[lc].add += (segt[node].add);
            segt[rc].add += (segt[node].add);
        }
        segt[node].sum += segt[node].add;
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
void update(int node , int l , int r , int st , int en , int val)
{
    propagate(node,l,r);
    if (en<l or st>r or st>en) return;
    if (st<=l and r<=en)
    {
        segt[node].add += val;
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val);
    update(rc , mid+1 , r , st , en , val);
    segt[node].sum = segt[lc].sum + segt[rc].sum;
    return;
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
        update(1 , 1 , n , low[node] , high[node] , brr[node]);
        cnt++;
    }
    int op , a , b;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            update(1 , 1, n , low[a] , high[a] , -arr[low[a]]);
            arr[low[a]] = b;
            update(1 ,1,n , low[a] , high[a] , b);
        }
        else
        {
            cin >> a;
            cout << get(1 , 1 , n , low[a] , low[a]) << endl;
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
