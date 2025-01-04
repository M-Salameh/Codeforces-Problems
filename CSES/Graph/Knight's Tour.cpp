#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 9;
const int mod = 1e9+7;
int tc=1;
int n ,m;
int ans[NN][NN] , degree[NN][NN];

bool vis[NN][NN];

int hor[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ver[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool in(int x, int y)
{
    return 1<=x and x<=8 and 1<=y and y<=8;
}

void take(int x , int y , int id)
{
    ans[x][y] = id;
    vis[x][y] = true;
    for (int i=0 ; i<8 ; i++)
    {
        int dx = x + hor[i];
        int dy = y + ver[i];
        if (vis[dx][dy]) continue;
        if (in(dx , dy))
        {
            degree[dx][dy] -- ;
        }
    }

}

void untake(int x , int y)
{
    ans[x][y] = 0;
    vis[x][y] = false;
    for (int i=0 ; i<8 ; i++)
    {
        int dx = x + hor[i];
        int dy = y + ver[i];
        if (vis[dx][dy]) continue;
        if (in(dx , dy))
        {
            degree[dx][dy] ++ ;
        }
    }
}

bool rec (int x , int y , int id)
{
    take(x , y , id);
    if (id >= 64)
    {
       return true;
    }
    set<pair<int,pair<int,int>>> nxt;
    for (int i=0 ; i<8 ; i++)
    {
        int dx = x + hor[i];
        int dy = y + ver[i];
        if (vis[dx][dy]) continue;
        if (in(dx , dy))
        {
            nxt.insert({degree[dx][dy], {dx , dy}});
        }
    }
    for (pair<int,pair<int,int>> op : nxt)
    {
        bool k = rec (op.second.first , op.second.second , id+1);
        if (k) return true;
    }
    untake(x , y);
    return false;
}

void solve()
{
    for(int x=1; x <= 8; x++)
    {
        for(int y=1 ; y <=8 ; y++)
        {
            for(int i=0; i<8; i++)
            {
                int dx = x + ver[i];
                int dy = y + hor[i];
                if(in(dx, dy)) degree[x][y]++;
            }
        }
    }


    rec(m , n , 1);

    for (int i=1 ; i<=8 ; i++)
    {
        for (int j=1 ; j<=8 ; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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

        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
