#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n ;
vector<pair<int,char>> adj[NN];
map<string , int> mp;
string sts[NN];

void build(string s , int& k)
{
    if (s.size() == n-1)
    {
        mp[s] = ++k;
        sts[k] = s;
        return;
    }
    build(s+"0" , k);
    build(s+"1" , k);
}

vector<char> path;

void find_euler_path()
{

    stack<pair<int,char>> st;
    st.push({1,'s'});

    while (st.size())
    {
        auto [node , c] = st.top();
        if (adj[node].size() == 0)
        {
            path.push_back(c);
            st.pop();
            continue;
        }

        auto [child , x] = adj[node].back();
        adj[node].pop_back();
        st.push({child,x});
    }

}

void solve()
{
    int cnt = 0;
    string s = "";
    build(s , cnt);

    int tot = (1 << (n-1));
    for (int i=1; i<=tot ; i++)
    {
        s = sts[i].substr(1 , n-2);

        adj[i].push_back({mp[s+"0"] , '0'});
        adj[i].push_back({mp[s+"1"] , '1'});

    }

    find_euler_path();

    path.pop_back();

    for (char c : path) cout << c;
    cout << sts[1] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n ;
        if (n == 1)
        {
            cout << "01" << endl;
        }
        else solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
