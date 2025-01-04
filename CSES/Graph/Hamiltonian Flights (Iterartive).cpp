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

const int_fast64_t inf = 1e15+1;
const int NN = 22;
const int lim = (1 << NN);
const int mod = 1e9+7;
int tc=1;
int n ,m;
vector<int> adj[NN];
int dp[lim][NN];

void add (int& a , int& b)
{
    a %= mod; if (a<0) a+=mod;
    b %= mod; if (b<0) b+=mod;
    a = a + b;
    a %= mod;
    if (a < 0) a += mod;

}

void solve()
{
    dp[1][0] = 1;

    int tot = (1<<n);
    int first = (1 << 0);
    int last = (1 << (n-1));

    for (int subset=2 ; subset<tot ; subset++)
    {
        if (subset & first == 0) continue;
        if (subset & last )
        {
            if (subset != tot-1) continue;
        }

        for (int to = 0; to < n; to++)
        {
            int temp = (1 << to);

			if ((subset & temp) == 0) continue;

			int other = subset ^ temp;

			for (int from : adj[to])
            {
				if ((subset & (1 << from)))
                {
                    add(dp[subset][to] , dp[other][from]);
				}
			}
		}
    }
    cout << dp[tot-1][n-1] << endl;
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
            adj[--v].push_back(--u);
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
