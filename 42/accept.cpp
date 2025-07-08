#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#pragma GCC optimize("O2")

using namespace std;
using ar = array<int, 2>;

const int64_t INF = 1e9 + 5;
const int N = 1500 + 50;

struct seg {
        int t[2 * N];
        void build() {  // build the tree
                fill(t, t + 2 * N, -INF);
        }

        void modify(int p, int value) {  // set value at position p
                p += N;
                if (t[p] > value) return;
                for (t[p] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
        }

        int query(int l, int r) { 
                int res = -INF;
                for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
                        if (l&1) res = max(res, t[l++]);
                        if (r&1) res = max(res, t[--r]);
                }
                return res;
        }
} T[2][N];
int n, a[N], b[N], dp[N][N];

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr); 
        FOR(i, 0, N) FOR(j, 0, 2) T[j][i].build();
        FOR(i, 0, N) FOR(j, 0, N) dp[i][j] = -INF;

        cin >> n;
        FOR(i, 0, n) {
                cin >> a[i];
                a[i] -= 42;
        }
        copy(a, a + n, b);
        sort(b, b + n);
        FOR(i, 0, n) 
                a[i] = lower_bound(b, b + n, a[i]) - b;

        FOR(i, 0, n) {
                int x = b[a[i]], xx = a[i];
                if (x < 0) continue;
                dp[i][1] = x;
                FOR(t, 2, n + 1)
                        dp[i][t] = T[0][t - 1].query(0, xx + 1);
                FOR(t, 2, n + 1)
                        dp[i][t] = max(dp[i][t], T[1][t - 1].query(xx, n + 1) + x);
                FOR(t, 1, n + 1) {
                        if (dp[i][t] < 0) continue;
                        T[0][t].modify(xx, dp[i][t]);
                        T[1][t].modify(xx, dp[i][t] - x);
                }
        }
        int mx = 0;
        FOR(i, 0, n) FOR(t, mx + 1, n + 1) if (dp[i][t] >= 0) mx = max(mx, t);
        cout << mx << '\n';
        return 0;
}
//https://quera.org/problemset/158163?tab=submissions