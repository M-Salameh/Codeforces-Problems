#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 2e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> adj[NN];
bool vis[NN];
int son[NN][23];
int depth[NN];

void dfs(int src)
{
    if (vis[src]) return;

    vis[src] = true;

    dfs(son[src][0]);

    depth[src] = 1 + depth[son[src][0]];
}

int down(int node , int dist)
{
    if (dist <= 0) return node;

    for (int i=0 ; i<23 ; i++)
    {
        if (dist & (1<<i))
        {
            node = son[node][i];
        }
    }
    return node;
}

void solve()
{
    for (int i=1 ; i<=n ;i++) if (not vis[i]) dfs(i);

    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int src = down(a , depth[a]);

        if (down(a , depth[a] - depth[b]) == b)
        {
            cout << depth[a] - depth[b] << endl;
        }

        else if (down(src , depth[src] - depth[b]) == b)
        {
            cout << depth[a] + depth[src] - depth[b] << endl;
        }
        else
        {
            cout << -1 << endl;
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
        ///freopen("test_input.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            int u;
            cin >> u;
            son[i][0] = u;
        }
        for (int level=1 ; level<23 ; level++)
        {
            for (int node=1; node<=n ; node++)
            {
                son[node][level] = son[son[node][level-1]][level-1];
            }
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

