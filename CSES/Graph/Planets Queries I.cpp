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
const int NN = 2e5+2;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> adj[NN];
int vis[NN];
int son[NN][30];


void solve()
{
    for (int level=1 ; level<30 ; level++)
    {
        for (int node=1; node<=n ; node++)
        {
            son[node][level] = son[son[node][level-1]][level-1];
        }
    }

    while(m--)
    {
        int x,k;
        cin >> x >> k;
        for (int level = 0 ;  level < 30 ; level++)
        {
            if (k & (1<<level))
            {
                x = son[x][level];
            }
        }
        cout << x << endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            int u;
            cin >> u;
            son[i][0] = u;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

