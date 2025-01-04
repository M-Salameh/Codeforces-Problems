#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
///#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int mod = 1e9+7;
const int MM = 1e3+1;
int tc=1;
int n , m;
/// 0=U, 1=R , 2=D, 3=L
int delta_x[] = {-1 , 0 , 1 , 0};
int delta_y[] = {0 , 1 , 0 , -1};
string dirs = "URDL";

int weight[MM][MM];
queue<pair<int,int>> bf;
pair<int , int> A;
int path[MM][MM];

void chck(pair<int,int> cur , pair<int,int> nxt , int i)
{
    int curw = weight[cur.first][cur.second];
    int& nxtw = weight[nxt.first][nxt.second];

    if (curw+1 < nxtw)
    {
        nxtw = curw+1;
        bf.push(nxt);
        path[nxt.first][nxt.second] = i;
    }
}

bool bfs(bool out = false)
{
    while(bf.size())
    {
        pair<int,int> cur = bf.front() ; bf.pop();
        int x = cur.first;
        int y = cur.second;
        if (out)
        {
            if (x==1 or x==n or y==1 or y==m)
            {
                vector<char> trace;
                while(x!=A.first or y!=A.second)
                {
                    trace.push_back(dirs[path[x][y]]);
                    int t = x;
                    ///cout << "in x = " << x << " and y = " << y << endl;
                    x -= delta_x[path[t][y]];
                    y -= delta_y[path[t][y]];
                }
                reverse(all(trace));

                cout << "YES" << endl;
                cout << trace.size() << endl;
                for (char c : trace) cout << c;
                return true;
            }
        }

        pair<int,int> nxt;

        for (int i=0 ; i<4 ; i++)
        {
            nxt.first = x + delta_x[i];
            nxt.second = y + delta_y[i];
            if (nxt.first < 1 or nxt.first > n or nxt.second < 1 or nxt.second > m) continue;
            chck(cur , nxt , i);
        }

    }
    return false;
}


void solve()
{
    bfs();
    ///cout << "done bfs 1" << endl;
    weight[A.first][A.second] = 0;
    path[A.first][A.second] = 0;
    bf.push(A);
    if (not bfs(true))
    {
        cout << "NO" << endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            string s;
            cin >> s;
            s = "@"+s;
            for (int j = 1 ; j<=m ; j++)
            {
                weight[i][j] = mod;
                if (s[j] == 'M')
                {
                    weight[i][j] = 0;
                    bf.push({i,j});
                }
                else if (s[j] == '#')
                {
                    weight[i][j] = 0;
                }
                else if (s[j] == 'A')
                {
                    A.first = i;
                    A.second = j;
                }
            }
        }
        solve();
    }

    return 0;
}


