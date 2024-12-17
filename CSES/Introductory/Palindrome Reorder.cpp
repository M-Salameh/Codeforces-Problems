#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;


signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        string s;
        int freq[30] = {0};
        cin >> s;
        string alls;
        for (char c : s)
        {
            freq[(c-'A') + 1]++;
            if (freq[(c-'A') + 1] == 1)
            {
                alls += c;
            }
        }
        char ch = '@';
        for (int i=1 ; i<=26 ; i++)
        {
            if (freq[i]&1)
            {
                if (ch == '@')
                {
                    ch = i+'A'-1;
                }
                else
                {
                    cout << "NO SOLUTION" << endl;
                    return 0 ;
                }
            }
        }
        string ans;
        for (char c : alls)
        {
            for(int i=1 ; i<=freq[c-'A' + 1]/2 ; i++)
            {
                ans += c;
            }
        }
        if (ch!='@') ans += ch;
        reverse(all(alls));
        for (char c : alls)
        {
            for(int i=1 ; i<=freq[c-'A' + 1]/2 ; i++)
            {
                ans += c;
            }
        }
        cout << ans << endl;


    }

    return 0;
}
