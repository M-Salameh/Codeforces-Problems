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

const long long inf = 1e18+1;
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m , k;

vector<vector<pair<int, int>>> adj;

priority_queue<int> ans[NN];

void solve()
{
    ans[1].push(0);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > dijkstra;
    dijkstra.push({0,1});

    while (dijkstra.size())
    {
        auto [cost , node] = dijkstra.top();
        dijkstra.pop();

        if (ans[node].top() < cost) continue;

        for (auto& [child , w] : adj[node])
        {
            int temp = cost + w;
            if (ans[child].size() < k)
            {
                ans[child].push(temp);
                dijkstra.push({temp , child});
            }
            else
            {
                if (ans[child].top() > temp)
                {
                    ans[child].pop();
                    ans[child].push(temp);
                    dijkstra.push({temp , child});
                }
            }
        }
    }

    vector<int> res;

    for (int i=1 ; i<=k; i++)
    {
        res.push_back(ans[n].top());
        ans[n].pop();
    }
    sort(all(res));
    for (int cost : res) cout << cost << " ";
    cout << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///auto time_Start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m >> k;
        adj = vector<vector<pair<int, int>>> (n+1);
        for (int i=1 ; i<=m ; i++)
        {
            int u, v , w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});

        }
        solve();
    }

    ///auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_Start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
