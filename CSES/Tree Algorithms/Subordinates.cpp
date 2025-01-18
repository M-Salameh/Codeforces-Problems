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
int parent[NN];
int sub_tree_size[NN];

void dfs(int node=1 , int father=0)
{
    parent[node] = father;
    sub_tree_size[node] = 1;
    for (int& child : adj[node])
    {
        if (parent[child]) continue;
        dfs(child ,node);
        sub_tree_size[node] += sub_tree_size[child];
    }

}

void solve()
{
    dfs();
    for (int i=1 ; i<=n ; i++) sub_tree_size[i]--;

    for (int i=1 ; i<=n ;i++)
    {
        cout << sub_tree_size[i] << " ";
    }
    cout << endl;
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
            cin >> u;
            adj[u].push_back(i);
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
