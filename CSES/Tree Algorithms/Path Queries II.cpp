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

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+4;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , q;
vector<int> adj[NN];
int sub[NN] , depth[NN] , parent[NN];
int head[NN] , heavy[NN] , id[NN];

int segt[NN*4];
int arr[NN];

int skipp;

int get(int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l) return 0;
    if (st<=l and r<=en)
    {
        return segt[node];
    }
    int p1 = get(lc , l , mid , st , en) ;
    int p2 = get(rc , mid+1 , r , st , en);
    segt[node] = max(segt[lc] , segt[rc]);
    return max(p1 , p2);

}

void update(int idx , int val)
{
    idx--;
    idx += skipp;
    segt[idx] = val;
    int node = idx >>=1;
    while (node > 0)
    {
        segt[node] = max (segt[lc] , segt[rc]);
        node >>= 1;
    }
}

int get(int st , int en)
{
    st--;
    en--;
    st += skipp;
    en += skipp;
    int ans = 0;
    while (st <= en)
    {
        if (st & 1) ans = max(ans , segt[st++]);
        if (~en & 1) ans = max (ans , segt[en--]);
        st >>= 1;
        en >>= 1;
    }
    return ans;
}

void update(int node , int l , int r , int idx ,int val)
{
    if (l==r)
    {
        segt[node] = val;
        return;
    }
    if (idx <= mid) update(lc , l , mid , idx, val);
    else update(rc , mid+1 , r , idx , val);
    segt[node] = max (segt[lc] , segt[rc]);
}



void dfs(int node=1 , int father=0)
{
    sub[node] = 1;
    parent[node] = father;
    depth[node] = 1 + depth[father];
    int hv = 0;
    for (int child : adj[node])
    {
        if (child == father) continue;
        dfs(child , node);
        sub[node] += sub[child];
        if (sub[child] > hv)
        {
            hv = sub[child];
            heavy[node] = child;
        }
    }
}

int cnt;
void HLD(int node=1 , int hh=1)
{
    head[node] = hh;
    id[node] = ++cnt;
    update(id[node] , arr[node]);

    if (heavy[node])
    {
        HLD(heavy[node] , hh);
    }

    for (int child : adj[node])
    {
		if (child == parent[node] or child == heavy[node]) continue;
		HLD(child , child);
	}
}


int path(int x , int y)
{
    int ret = 0;
	while (head[x] != head[y])
    {
		if (depth[head[x]] > depth[head[y]]) swap(x, y);
        ret = max (ret, get(id[head[y]], id[y]));
		y = parent[head[y]];
	}
	if (depth[x] > depth[y]) swap(x, y);
	ret = max(ret, get(id[x], id[y]));
	return ret;
}

void solve()
{
    dfs();

    HLD();

    int op , a , b;
    while(q--)
    {
        cin >> op >> a >> b;
        if (op == 1)
        {
            update(id[a] , b);
        }
        else
        {

            cout << path(a , b) << " ";
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
        ///freopen("test_output.txt" , "w" , stdout);
        cin >> n >> q;
        skipp = 1 << ( (int) ceil(log2(n)));
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
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
