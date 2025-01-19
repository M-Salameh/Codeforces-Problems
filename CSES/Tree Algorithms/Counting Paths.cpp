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
vector<int> adj[NN];
int parent[24][NN];
int depth[NN];
int paths[NN];
int over[NN];
int n,q;


void dfs(int node , int father)
{
    depth[node] = depth[father]+1;
    parent[0][node] = father;
    for (auto child : adj[node])
    {
        if(child == father) continue;
        dfs(child , node);
    }
}

int go_up(int node , int diff)
{
    for(int i=0; i<=22 ; i++)
    {
        int temp = (1LL<<i);
        if (diff & temp)
        {
            node = parent[i][node];
        }
    }
    return node;
}

void sparse_matrix()
{
    for (int i=1 ; i <= 22 ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int LCA(int u,int v)
{
    if (u==v) return v;

    if(depth[u] < depth[v]) swap(u,v);

    u = go_up(u , depth[u]-depth[v]);

    if(u == v) return u;

    for(int i = 22 ; i>=0 ; i--)
    {
        if (parent[i][u] == parent[i][v]) continue;
        u = parent[i][u];
        v = parent[i][v];
    }

    return parent[0][u];
}

int dfs2(int node , int father)
{
    for (int child : adj[node])
    {
        if (child == father) continue;
        paths[node] += dfs2(child , node);
    }
    paths[node] -= over[node];

    return paths[node] - over[node];
}

void solve()
{
    dfs(1 , 1);
    sparse_matrix();
    int a , b;
    while(q--)
    {
        cin >> a >> b;
        int lca = LCA(a , b);
        paths[a]++ ; paths[b]++;
        over[lca]++;
    }
    dfs2(1 , 1);
    for (int node = 1 ; node<=n ; node++) cout << paths[node] << " "; cout << endl;
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
