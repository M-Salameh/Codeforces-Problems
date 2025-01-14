#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , m , q;
struct Node
{
    int sum = 0;
    int l , r;
    Node* left;
    Node* right;

    Node(int ll , int rr , int summ)
    {
        l = ll;
        r = rr;
        sum = summ;
        left = nullptr;
        right = nullptr;
    }
    Node(Node* ll , Node* rr)
    {
        left = ll;
        right = rr;
        sum = 0;
        if (ll != nullptr)
        {
            sum += ll->sum;
            l = ll->l;
        }
        if (rr != nullptr)
        {
            sum += rr->sum;
            r = rr->r;
        }
    }
    Node (Node* cpy) : Node(cpy->left , cpy->right) {}

};

int arr[NN];
Node* segt[NN];

Node* build(int l=1 , int r=n)
{
    if (l == r) return new Node(l , r , arr[r]);

    Node* x = build(l , mid);

    Node* y = build(mid+1 , r);

    Node* ans = new Node(x , y);
    return ans;
}

Node* update(Node* node, int idx, int val)
{
    if(node->l == node->r)
    {
        return new Node(idx, idx, val);
    }
    int l = node->l;
    int r = node->r;

    if(idx <= mid)
    {
        Node* x = update(node->left , idx , val);
        Node* ans = new Node(x , node->right);
        return ans;
    }
    else
    {
        Node* x = update(node->right , idx , val);
        Node* ans = new Node(node->left , x );
        return ans;
    }
}

int query(Node* node , int st , int en)
{
    if (st > node->r or en < node->l) return 0;
    if (st <= node->l and node->r <= en) return node->sum;

    int p1 = query(node->left , st , en);
    int p2 = query(node->right , st , en);

    return p1+p2;
}

void solve()
{
    int copies = 1;
    segt[copies++] = build();

    int op , k , a ,b , x;
    while (q--)
    {
        cin >> op >> k;
        if (op == 1)
        {
            cin >> a >> x;
            segt[k] = update(segt[k] , a , x);
        }
        else if (op == 2)
        {
             cin >> a >> b;
             cout << query(segt[k] , a , b) << endl;
        }
        else
        {
            segt[copies++] = new Node(segt[k]);
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
        //freopen("test_input.txt" , "r" , stdin);
        //freopen("test_output.txt" , "w" , stdout);
        cin >> n >> q;

        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }

        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
