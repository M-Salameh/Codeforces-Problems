#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> adj[NN];
bool vis[NN];


void dfs(int src , int parent = 0)
{
    if (vis[src]) return;
    vis[src] = true;
    for (int& child : adj[src])
    {
        if (child == parent) continue;
        dfs(child , src);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int,int>> reps;
        int last = 0;
        for (int i=1 ; i<=n ; i++)
        {
            if (not vis[i])
            {
                if (last)
                {
                    reps.push_back({last , i});
                }
                last = i;
                dfs(i);
            }
        }
        cout << reps.size() << endl;
        for(auto& [from , to] : reps)
        {
            cout << from << " " << to << endl;
        }
    }

    return 0;
}


