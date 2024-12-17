#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()
 
using namespace std;
 
const long long inf = 8e18;
const int NN = 2e5+3;
int tc=1;
int n;
 
int power (int a , int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}
 
int calc(int x)
{
    int i = 1 , j = 9;
    while (n - i*j > 0)
    {
        n -= i*j;
        i++;
        j *= 10;
    }
    int idx = n % i;
    int ans = (n-1)/i + power(10 , i-1);
 
    if (idx)
    {
        ans /= power(10 , i-idx);
    }
    ans %= 10;
    return ans;
 
}
 
signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        cout << calc(n) << endl;
    }
 
    return 0;
}