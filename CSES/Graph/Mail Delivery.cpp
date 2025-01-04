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
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n , m;
vector<pair<int,int>> adj[NN];
int degree[NN];
bool vis[NN];

bool chck()
{
    for (int i=1 ; i<=n ; i++)
    {
        if (degree[i]&1) return true;
    }
    return false;
}

void find_euler_path()
{
    if (chck())
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }

    stack<int> st;
    st.push(1);

    vector<int> path;

    while (st.size())
    {
        int node = st.top();
        if (degree[node] == 0)
        {
            path.push_back(node);
            st.pop();
            continue;
        }
        while (adj[node].size())
        {
            auto [child , id] = adj[node].back();
            adj[node].pop_back();

            if (vis[id]) continue;
            vis[id] = true;
            degree[node]--;
            degree[child]--;
            st.push(child);
            break;
        }
    }
    if (path.size() != m+1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int node : path) cout << node << " ";

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 , u ,v; i<=m ; i++)
        {
            cin >> u >> v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
            degree[u]++;
            degree[v]++;
        }
        find_euler_path();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

