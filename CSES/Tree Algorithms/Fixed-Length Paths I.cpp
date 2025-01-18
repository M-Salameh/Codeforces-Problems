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
int n , k;
vector<int> adj[NN];
int arr[NN] , sub[NN];
bool processed[NN];

void dfs(int node=1 , int father = 0)
{
    sub[node] = 1;
    for (int child : adj[node])
    {
        if (child == father or processed[child]) continue;
        dfs(child , node);
        sub[node] += sub[child];
    }
}

int centroid (int node , int new_max , int par=0)
{
    for (int child : adj[node])
    {
        if (not processed[child] and child!=par and sub[child]>=new_max)
        {
            return centroid(child , new_max , node);
        }
    }
    return node;
}

int mx_depth;
long long cnt[NN]{1};
long long ans;

void get_cnt(int node , int par , bool filling , int depth = 1)
{
    if (depth > k) return;
    mx_depth = max (mx_depth , depth);
    if (filling) cnt[depth]++;
    else ans += cnt[k-depth];
    for (int child : adj[node])
    {
        if (child != par and not processed[child])
        {
            get_cnt(child ,node , filling , depth+1);
        }
    }

}

void centroid_decomp(int node = 1)
{
    dfs(node , 0);
    int centr = centroid(node , sub[node]/2);

    processed[centr] = true;
    mx_depth = 0;
    for (int child : adj[centr])
    {
        if (processed[child]) continue;
        get_cnt(child, centr , false);
        get_cnt(child , centr , true);
    }
    fill (cnt+1 , cnt+mx_depth+1 , 0);
    for (int child : adj[centr])
    {
        if (not processed[child]) centroid_decomp(child);
    }

}

void solve()
{
    ans = 0;
    centroid_decomp();
    cout << ans << endl;
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
        cin >> n >> k;
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
