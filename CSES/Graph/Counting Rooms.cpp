#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 1e3+1;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , m;
bool wall[NN][MM];
int hor[] = {1 , -1 , 0 , 0};
int ver[] = {0 , 0 , 1 , -1};

void dfs(int x , int y)
{
    if (x<1 or y<1) return;
    if (x>n or y>m) return;

    if (wall[x][y]) return ;

    wall[x][y] = true;

    for (int i=0 ; i<4 ; i++)
    {
        int dx = x + hor[i];
        int dy = y + ver[i];
        dfs(dx , dy);
    }

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n  ;i++)
        {
            for (int j=1 ; j<=m  ; j++)
            {
                char c;
                cin >> c;
                wall[i][j] = (c == '#');
            }
        }
        int ans = 0;
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=m ; j++)
            {
                if (not wall[i][j])
                {
                    ans ++ ;
                    dfs(i , j);
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}


