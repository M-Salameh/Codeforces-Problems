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

const long long inf = 1e18+1;
const int NN = 1e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m , k;

vector<vector<int>> adj;
int parent[NN];
int ans[NN];
int degree[NN];

void add (int& a , int& b)
{
    a %= mod; if (a<0) a+=mod;
    b %= mod; if (b<0) b+=mod;
    a = a+b;
    a %= mod; if (a<0) a+=mod;
}

void solve()
{
    queue<int> bfs;
    for (int i=1 ; i<=n ; i++)
    {
        ans[i] = 0;
        if (degree[i] == 0)
        {
            bfs.push(i);
        }
    }
    ans[1] = 1;

    while (bfs.size())
    {
        int node = bfs.front();
        bfs.pop();
        for (int& child : adj[node])
        {
            degree[child]--;

            if (degree[child] == 0)
            {
                bfs.push(child);
            }

            if (ans[node]>0)
            {
                add(ans[child],ans[node]);
            }
        }
    }
    cout << ans[n] << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_Start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        adj = vector<vector<int>> (n+1);
        for (int i=1 ; i<=m ; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            degree[v]++;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_Start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

