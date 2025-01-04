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

int ans[NN];
bool vis[NN];
int son[NN];


void dfs(int src)
{
    vector<int> path;
    path.push_back(src);
    vis[src] = true;
    int nxt = son[src];

    while (not vis[nxt])
    {
        vis[nxt] = true;
        path.push_back(nxt);
        nxt = son[nxt];
    }

    int temp = 0;

    if (ans[nxt]) temp = ans[nxt];

    else
    {
        vector<int> v;
        int c = 0;
        while (true)
        {
            int a = path.back() ; path.pop_back();
            v.push_back(a);
            c++;
            if (a == nxt)
            {
                for (int node : v)
                {
                    ans[node] = c;
                }
                break;
            }
        }
        temp = c;
    }

    while(path.size())
    {
        ans[path.back()] = ++temp;
        path.pop_back();
    }

}


void solve()
{
    for (int i=1 ; i<=n ;i++) if (not vis[i]) dfs(i);

    for (int i=1 ; i<=n ; i++)
    {
        cout << ans[i] << " ";
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
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            int u;
            cin >> u;
            son[i]= u;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}

