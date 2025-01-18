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
int n , q;
vector<int> adj[NN];
int parent[NN][25];

void dfs(int node=1 , int father=0)
{
    parent[node][0] = father;
    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs(child ,node);
    }
}

void sparse()
{
    for (int mask = 1 ; mask<25 ; mask++)
    {
        for (int node = 1 ; node<=n; node++)
        {
            parent[node][mask] = parent[parent[node][mask-1]][mask-1];
        }
    }
}

void solve()
{
    dfs();
    int k,x;
    sparse();
    while(q--)
    {
        cin >> x >> k;
        for (int mask = 24 ; mask>=0 ; mask--)
        {
            if (k & (1 << mask))
            {
                x = parent[x][mask];
                k -= (1<<mask);
            }
        }
        x = x > 0 ? x : -1 ;
        cout << x << endl;
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
        for (int i=2 , u , v ; i<=n ; i++)
        {
            cin >> u;
            v = i;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
