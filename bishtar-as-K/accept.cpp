#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

using namespace std;
using ar = array<int, 2>;

const int N = 2e5 + 5;
const int MOD = 998244353;
const long long INF = 1ll << 60;
int n, k, a[N], f[N], inv[N];

int pw(int a, int b) {
        int re = 1;
        for (; b; b >>= 1, a = a * a % MOD) if (b & 1)
                re = re * a % MOD;
        return re;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr); 
        f[0] = inv[0] = 1;
        FOR(i, 1, N) {
                f[i] = f[i - 1] * i % MOD;
                inv[i] = pw(f[i], MOD - 2);
        }

        cin >> n >> k;
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n)
                a[i] = 2ll * a[i] - k;
        sort(a, a + n);
        int L = 0, R = n - 1, S = 1, ans = 1;
        while (L <= R) {
                if (a[L] + a[R] >= 0) {
                       ans *= S++;
                       ans %= MOD;
                       --R;
                }
                else {
                        ans *= S--;
                        ans %= MOD;
                        ++L;
                }
        }
        int cnt = 0;
        FOR(i, 0, n) {
                if (!i || a[i] == a[i - 1]) ++cnt;
                if (i == n - 1 || a[i] != a[i - 1]) {
                        ans *= inv[cnt];
                        ans %= MOD;
                        cnt = 1;
                }
        }
        cout << ans << '\n';

        return 0;
}
//https://atcoder.jp/contests/arc148/submissions/49142433