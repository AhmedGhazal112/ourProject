#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define double long double
#define int long long
#define ordered_set tree<pair<int,int>, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>
#define all(c) (c).begin(), (c).end()
#define Sort(c) sort(all(c))
#define cin(c) for(auto&xyz:c)cin>>xyz
#define cinpair(c) for(auto&xyz:c)cin>>xyz.first>>xyz.second
#define cout(c) for(auto&xyz:c)cout<<xyz<<' '
#define rfor(c) for(auto&i:c)
#define coutpair(c) for(auto&xyz:c)cout<<xyz.first<<' '<<xyz.second<<'\n'
#define mems(mem, c) memset(mem,c,sizeof mem)
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define td vector<vector<int>>
#define cintd(v) for (size_t i = 0; i < v.size(); i++)for (size_t j = 0; j < v[i].size(); j++)cin>>v[i][j]
#define mpii map<int,int>

struct bit {
private:
    int n;
    vi b;

    int query(int i) {
        int res = 0;
        while (i)res += b[i], i -= i & -i;
        return res;
    }

public:
    bit(int n) {
        this->n = n + 1;
        b = vi(this->n);
    }

    void update(int i, int v) {
        i++;
        while (i <= n)b[i] += v, i += i & -i;
    }

    int query(int l, int r) {
        l++, r++;
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n, q, o, e;
    cin >> n >> q;
    vi v(n);
    cin(v);
    set<int> st;
    bit b(n);
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1)
            st.insert(i);
        b.update(i, v[i]);
    }
    int sm = b.query(0, n - 1), l = sm, r = sm;
    if (!st.empty())l = b.query(0, *st.begin()), r = b.query(*st.rbegin(), n - 1);
    if (st.size() % 2 == 0) {
        e = sm;
        o = max(sm - l, sm - r);
    } else {
        o = sm;
        e = max(sm - l, sm - r);
    }
    int t, s, i, val;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> s;
            if (s % 2)cout << (o >= s ? "YES" : "NO") << '\n';
            else cout << (e >= s ? "YES" : "NO") << '\n';
            continue;
        }
        cin >> i >> val;
        i--;
        b.update(i, val - v[i]);
        v[i] = val;
        if (val == 1)st.insert(i);
        if (val == 2)st.erase(i);
        sm = b.query(0, n - 1), l = sm , r = sm;
        if (!st.empty())l = b.query(0, *st.begin()), r = b.query(*st.rbegin(), n - 1);
        if (st.size() % 2 == 0) {
            e = sm;
            o = max(sm - l, sm - r);
        } else {
            o = sm;
            e = max(sm - l, sm - r);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
//        cout << '\n';
    }
}








