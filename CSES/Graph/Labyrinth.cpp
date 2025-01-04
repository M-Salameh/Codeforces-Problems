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
int arr[NN][MM];

/// 0=U, 1=R , 2=D, 3=L
int delta_x[] = {-1 , 0 , 1 , 0};
int delta_y[] = {0 , 1 , 0 , -1};
string dirs = "URDL";

int xs,ys;
int xe,ye;

int path[NN][MM];

#define wall 1
#define flor 2
#define from 3
#define to 4

void solve()
{
    queue<pair<int,int>> bfs;
    bfs.push({xs,ys});
    arr[xs][ys] = wall;

    while(bfs.size())
    {
        auto[x,y] = bfs.front();
        bfs.pop();
        for (int i=0 ; i<4 ;i++)
        {
            int dx = x+delta_x[i];
            int dy = y+delta_y[i];

            if (dx<1 or dx>n or dy<1 or dy>m) continue;
            if (arr[dx][dy] == wall) continue;
            path[dx][dy] = i;
            arr[dx][dy] = wall;
            bfs.push({dx,dy});
        }
    }

    if (arr[xe][ye] != wall)
    {
        cout << "NO";
        return;
    }
    vector<char> trace;
    while(xs != xe or ys != ye)
    {
        trace.push_back(dirs[path[xe][ye]]);
        int t = xe;
        xe -= delta_x[path[t][ye]];
        ye -= delta_y[path[t][ye]];
    }
    cout << "YES" << endl;
    reverse(all(trace));
    cout << trace.size() << endl;
    for (char c : trace) cout << c;
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
                if (c == '#')
                {
                    arr[i][j] = wall;
                }
                else if (c == '.')
                {
                    arr[i][j] = flor;
                }
                else if (c == 'A')
                {
                    arr[i][j] = from;
                    xs = i;
                    ys = j;
                }
                else
                {
                    arr[i][j] = to;
                    xe = i;
                    ye = j;
                }
            }
        }
        solve();
    }

    return 0;
}


