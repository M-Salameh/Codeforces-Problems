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

const long long inf = 2e12+1;
const int NN = 5e2+5;
const int mod = 1e9+7;
const int MM = 1e3+1;
int tc=1;
int n , m, q;
int dist[NN][NN];

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            for (int k=1 ; k<=n ; k++)
            {
                if (dist[i][j] == inf or dist[i][k] == inf) continue;
                dist[j][k] = min (dist[j][k] , dist[j][i] + dist[i][k]);
            }
        }
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int ans = dist[a][b]==inf ? -1 : dist[a][b];
        cout << ans << endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> q;
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ;j<=n ; j++)
            {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = inf;
            }
        }
        for (int i=1 ; i<=m ; i++)
        {
            int u, v , w;
            cin >> u >> v >> w;
            dist[u][v] = min (dist[u][v] , w);
            dist[v][u] = min (dist[v][u] , w);
        }
        solve();
    }

    return 0;
}


