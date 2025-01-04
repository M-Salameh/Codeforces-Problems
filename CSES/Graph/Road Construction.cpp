#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 1e5+1;
const int MM = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , m;

struct edge
{
    int from=0 , to=0 , w=0;

    bool operator < (edge const& other)
    {
        return w < other.w;
    }
};

edge edges[MM];
int degree[NN] , parent[NN];

int find_set(int a)
{
    while(a != parent[a]) a = parent[a];
    return a;
}

void union_sets(int a, int b , int& largest)
{
    int large = find_set(a);
    int small = find_set(b);
    if (large == small) return;

    if (degree[large] < degree[small]) swap(large,small);

    parent[small] = large;

    degree[large] += degree[small];

    largest = max (degree[large] , largest);

}


void solve()
{
    int from , to;
    int largest = 1;
    int comps = n;
    while(m--)
    {
        cin >> from >> to;
        if (find_set(from) == find_set(to))
        {
            cout << comps << " " << largest << endl;
        }
        else
        {
            comps--;
            union_sets(from , to , largest);
            cout << comps << " " << largest << endl;
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
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            parent[i] = i;
            degree[i] = 1;
        }
        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
