#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 4e5+3;
const int mod = 1e9+7;
int tc=1;
int n , q;
int brr[NN];
vector<int> arr;
int segt[4*NN];


void update(int node , int l , int r , int idx , int val)
{
    if (idx<l or idx>r) return;
    if (l==r)
    {
        segt[node] += val;
        return;
    }
    if (idx<=mid) update(lc , l , mid , idx , val);
    else update(rc , mid+1 , r , idx , val);
    segt[node] =  (segt[lc] + segt[rc]);
}

int get (int node , int l , int r , int st , int en)
{
    if (en<l or st>r or st>en) return 0;
    if (st<=l and r<=en)
    {
        return segt[node];
    }
    int p1 = get(lc , l , mid, st , en);
    int p2 = get(rc , mid+1 , r, st , en);
    return p1+p2;
}

vector<array<int,3>> qers;


void solve()
{
    sort(all(arr));
    arr.erase(unique(all(arr)) , arr.end());
    int m = arr.size();

    for (int i=1 ; i<=n ; i++)
    {
        int id = lower_bound(all(arr) , brr[i]) - arr.begin() + 1;
        update(1 , 1 , m , id , 1);
    }

    for (auto u : qers)
    {
        if (u[0] == 1)
        {
            int st = lower_bound(all(arr) , u[1]) - arr.begin() + 1;

            int en = upper_bound(all(arr) , u[2]) - arr.begin() ;

            cout << get(1 , 1, m , st , en) << endl;
        }
        else
        {
            int st = lower_bound(all(arr) , brr[u[1]]) - arr.begin() + 1;
            int en = lower_bound(all(arr) , u[2]) - arr.begin() + 1;
            update(1 , 1, m , st , -1);
            brr[u[1]] = u[2];
            update(1 , 1 , m , en , 1);
        }
    }

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input.txt" , "r" , stdin);
        ///freopen("test_output.txt" , "w" , stdout);
        cin >> n >> q;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> brr[i];
            arr.push_back(brr[i]);
        }

        for (int i=1 ; i<=q ; i++)
        {
            char op;
            int x , y;
            cin >> op >> x >> y;
            if (op == '?')
            {
                qers.push_back({1 , x , y});
            }
            else
            {
                qers.push_back({2 , x , y});
                arr.push_back(y);
            }
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
