#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast32_t

const long long inf = 1e18+1;
const int NN = 2e5+3;
int tc=1;
int n,k;
int arr[NN];
multiset<int> low,high;
int sum1 , sum2;


void add(int x)
{
    if (x <= *low.rbegin())
    {
        low.insert(x);
        sum1 += x;
        if (low.size() <= (k+1)/2) return;
        int temp = *low.rbegin();
        high.insert(temp);
        sum1 -= temp;
        sum2 += temp;
        low.erase(--low.end());
        return;
    }

    high.insert(x);
    sum2 += x;
    if (high.size() <= (k/2)) return;
    int temp = *high.begin();
    low.insert(temp);
    sum1 += temp;
    sum2 -= temp;
    high.erase(high.begin());
    return;
}

void remov(int x)
{
    auto it = low.find(x);
    if (it == low.end())
    {
        high.erase(high.find(x));
        sum2 -= x;
    }
    else
    {
        low.erase(it);
        sum1 -= x;
    }

}

void solve()
{
    for (int i=k+1 ; i<=n  ; i++)
    {
        remov(arr[i-k]); add(arr[i]);
        int cost = sum2 - sum1 + ((k&1)* (*low.rbegin()));
        cout << cost << " ";
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        for (int i = 1 , st; i <= n; i++)
        {
           cin >> arr[i];
        }
        if (k == 1)
        {
            for (int i=1; i<=n-k+1 ; i++) cout << 0 << " ";
            return 0;
        }
        if (k == 2)
        {
            for (int i=1 ; i<n ; i++)
            {
                cout << abs (arr[i+1] - arr[i]) << " ";
            }
            return 0;
        }
        low.insert(arr[1]); sum1 = arr[1];
        for (int i=2 ; i<=k ; i++) add(arr[i]);
        int cost = sum2 - sum1 + ((k&1)* (*low.rbegin()));
        cout << cost << " ";
        solve();
    }

    return 0;
}

/**
7 3
3 1 7 2 5 6 6

8 2
2 4 3 5 8 1 2 1

4 3
2 5 6 6

*/
