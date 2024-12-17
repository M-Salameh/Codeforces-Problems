#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
vector<string> ans;
string s;

void solve(int pos = 1)
{
    if (pos == n)
    {
        string f = ""; f+=s[pos-1];
        ans.push_back(f);
        return;
    }
    string cur =""; cur+=s[pos-1];
    solve(pos+1);
    vector<string> ans2;
    for (int i=0 ; i<ans.size() ; i++)
    {
        string& temp = ans[i];
        ans2.push_back(cur+temp);
        for (int i=1 ; i<=temp.size() ; i++)
        {
            string x = temp.substr(0,i) + cur;
            if (i+1 <= temp.size())
            {
                x += temp.substr(i);
            }
            ans2.push_back(x);
        }
    }
    ans.clear();
    ans = ans2;
}


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> s;
        n = s.size();
        solve();
        set<string> res;
        for (auto& stri : ans)
        {
            res.insert(stri);
        }
        cout << res.size()<<endl;
        for (auto& k : res)
        {
            cout << k << endl;
        }
    }

    return 0;
}
