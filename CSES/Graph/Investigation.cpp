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
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m , k;

vector<pair<int,int>> adj[NN];
int num[NN];
int minf[NN];
int maxf[NN];
int dist[NN];
bool vis[NN];

void add (int& a , int& b)
{
    a %= mod; if (a<0) a+=mod;
    b %= mod; if (b<0) b+=mod;
    a = a+b;
    a %= mod; if (a<0) a+=mod;
}

void solve()
{
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> bfs;
    num[1] = 1;
    dist[1] = 0;

    bfs.push({0 , 1});

    while (bfs.size())
    {
        auto [cos   t,node] = bfs.top();
        bfs.pop();

        if (vis[node]) continue;

        vis[node] = true;

        for (auto [child,w] : adj[node])
        {
            int temp = dist[node] + w;

            if (temp < dist[child])
            {
                dist[child] = temp;
                num[child] = num[node];
                minf[child] = minf[node] + 1;
                maxf[child] = maxf[node] + 1;
                bfs.push({temp , child});

            }
            else if (temp == dist[child])
            {
                add(num[child] , num[node]);
                minf[child] = min (minf[child] , minf[node] + 1);
                maxf[child] = max (maxf[child] , maxf[node] + 1);
            }
        }
    }
    cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << endl;

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
        for (int i=1 ; i<=m ; i++)
        {
            int u, v , w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
        }
        for (int i=1 ; i<=n ; i++)
        {
            dist[i] = inf;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

