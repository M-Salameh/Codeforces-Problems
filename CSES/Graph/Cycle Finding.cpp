#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
///#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const long long inf = 2e12+1;
const int NN = 3e3;
const int mod = 1e9+7;
const int MM = 1e4+1;
int tc=1;
int n , m;
struct edge
{
    int src , dest , w;
};

vector<int> dp;
set<int> sus;
int parent[NN];
edge edges[MM];


void bellman_ford()
{
    dp = vector<int> (n+1 , inf);
    dp[1] = 0;

    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            edge& e = edges[j];
            if (dp[e.src]+e.w < dp[e.dest])
            {
                dp[e.dest] = e.w + dp[e.src];
                parent[e.dest] = e.src;
            }
        }
    }

    for (int j=1 ; j<=m ; j++)
    {
        edge& e = edges[j];
        int temp = dp[e.dest];
        dp[e.dest] = min(dp[e.dest] , dp[e.src] + e.w);

        if (temp != dp[e.dest])
        {
            sus.insert(e.dest);
        }
    }

}




void solve()
{
    bellman_ford();
    if (sus.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }

    ///for (int node : sus) cout << node << endl;

    vector<bool> taken(n+1 , false);

    int st = *sus.begin();
    ///for (int i=1; i<=n ; i++)

    stack<int> path;
    while (not taken[st])
    {
        taken[st] = true;
        path.push(st);
        st = parent[st];
    }
    cout << "YES" << endl;
    cout << st << " ";
    while (path.top() != st)
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << st << endl;

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
            int u, v , w;
            cin >> u >> v >> w;
            edges[i] = {u , v , w};

        }
        solve();
    }

    return 0;
}

