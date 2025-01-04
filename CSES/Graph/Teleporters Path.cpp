#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n ,m;
vector<pair<int,int>> adj[NN];
bool vis[NN];
int in[NN] , out[NN];

vector<int> path;

void find_euler_path()
{

    stack<int> st;
    st.push(1);

    while (st.size())
    {
        int node = st.top();
        if (out[node] == 0)
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
            out[node]--;
            in[child]--;
            st.push(child);
            break;
        }
    }

}

bool check()
{
    for (int node = 2 ; node < n ; node++)
    {
        if (in[node] != out[node]) return true;
    }
    if (in[1] != out[1]-1) return true;
    if (in[n] != out[n]+1) return true;

    return false;
}

void solve()
{
    if (check())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    find_euler_path();
    reverse(all(path));

    if (path.size() != m+1 or path.back() != n )
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
        for (int i=1 , u , v ; i<=m ; i++)
        {
            cin >> u >> v;
            adj[u].push_back({v,i});
            out[u]++;
            in[v]++;
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
