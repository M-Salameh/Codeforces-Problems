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
const int NN = 2e5+1;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n;
vector<int> adj[NN];
int from_root_1[NN];
int ans , idx;
int from_root_2[NN];
int val[NN];
int root1 , root2;

void dfs(int node=1 , int father=0)
{
    from_root_1[node] = 1 + from_root_1[father];
    if (from_root_1[node] > ans)
    {
        ans = from_root_1[node];
        idx = node;
    }
    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs(child ,node);
    }

}
void dfs2(int node , int father = 0)
{
    from_root_2[node] = 1 + from_root_2[father];
    if (from_root_2[node] > from_root_1[node])
    {
        val[node] = from_root_2[node];
    }
    else val[node] = from_root_1[node];

    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs2(child ,node);
    }
}

void solve()
{
    dfs();
    ans = 0;
    root1 = idx;
    for (int i=0 ; i<=n ; i++) from_root_1[i] = 0;
    dfs(root1 , 0);
    root2 = idx;

    dfs2(root2 , 0);

    for (int i=1 ; i<=n ; i++) cout << val[i]-1 << " ";cout << endl;
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
        cin >> n;
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
