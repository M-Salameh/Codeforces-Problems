#include <bits/stdc++.h>
#define int long long
///#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
string s;
int dir[50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

bool taken[50][50];

int solve(int pos , int row , int col)
{
    ///cout << "IN pos = " << pos << "***" <<endl;
    if (row == 7 and col == 1)
    {
        return pos == 49;
    }
    if (pos == 49) return 0;

    if  ( (taken[row][col - 1] and taken[row][col + 1])
            and (not taken[row - 1][col] and not taken[row + 1][col]) )
        {
            return 0;
        }

	if  ( (taken[row - 1][col] and taken[row + 1][col])
            and ( not taken[row][col - 1] and not taken[row][col + 1]) )
		{
		    return 0;
        }

    int ans = 0;

    taken[row][col] = true;

    if (dir[pos] == 4)
    {
        for (int i=0 ; i < 4; i++)
        {
            int row2 = row + dr[i];
            int col2 = col + dc[i];
            if (taken[row2][col2]) continue;
            ans += solve(pos+1 , row2 , col2);
        }
        taken[row][col] = false;
        return ans;
    }

    int row2 = row + dr[dir[pos]];
    int col2 = col + dc[dir[pos]];
    if (not taken[row2][col2]) ans += solve(pos + 1, row2, col2);
    taken[row][col] = false;
    return ans;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> s;
        n = s.size();
        s = "s"+s;
        for (int i=1 ; i<=n ; i++)
        {
            char mov = s[i];
            if (mov == 'L')
            {
                dir[i] = 1;
            }
            else if (mov == 'R')
            {
                dir[i] = 3;
            }
            else if (mov == 'U')
            {
                dir[i] = 0;
            }
            else if (mov == 'D')
            {
                dir[i] = 2;
            }
            else dir[i] = 4;
        }
        memset(taken , false , sizeof taken);
        for (int i = 0 ; i <= 8; i++)
        {
            taken[0][i] = true;
            taken[8][i] = true;
            taken[i][0] = true;
            taken[i][8] = true;
        }
        int ans = solve(1,1,1);

        cout << ans << endl;
    }

    return 0;
}
