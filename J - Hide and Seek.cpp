#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

int modo=1e9+7;
int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res ;
}

int h[100100];
int tc=1;
int n,x;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin>>tc;
    while(tc--)
    {
        cin>>n>>x;
       for(int i=1;i<=n;i++)cin>>h[i];
       for(int i=1;i<=n;i++)
       {
           if(h[i]<x)cout<<1<<" ";
           else cout<<0<<" ";
       }
       cout<<endl;
    }
    return 0;
}
