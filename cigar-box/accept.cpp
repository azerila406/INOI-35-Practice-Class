#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

using namespace std;
using ar = array<int, 2>;

const int N = 3005;
const long long INF = 1ll << 60;
const int MOD = 998244353;
int n, m, p[N], a[N], dp[N][N], f[N], inv[N];
bool sorted[N][N];

int C(int n, int r) {
        return r >= 0 && n >= r ? f[n] * inv[n - r] % MOD * inv[r] % MOD : 0;
}

int pw(int a, int b) {
        int re = 1;
        for (; b; a = a * a % MOD, b >>= 1) if (b & 1)
                re = re * a % MOD;
        return re;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr); 
        f[0] = inv[0] = 1;
        FOR(i, 1, N) {
                f[i] = i * f[i - 1] % MOD;
                inv[i] = pw(f[i], MOD - 2);
        }

        cin >> n >> m;
        FOR(i, 0, n) cin >> a[i];

        FOR(i, 0, n) {
                sorted[i][i] = true;
                for (int j = i + 1; j < n && a[j] > a[j - 1]; j++) {
                        sorted[i][j] = true;
                }
        }

        /*
           FOR(mm, 1, m + 1) {
        FOR(i, 0, n) FOR(j, 0, n) dp[0][i][j] = sorted[i][j];
                FOR(sz, 2, n + 1) {
                for (int l = n - 1; l >= 0; --l) {
                        dp[mm][l][l] = pw(2 * n, mm);
                        for (int r = l + 1; r < n; ++r) {
                                dp[mm][l][r] = dp[mm - 1][l + 1][r] + dp[mm - 1][l][r - 1] + dp[mm - 1][l][r] * 2ll * (n - (r - l + 1));
                                dp[mm][l][r] %= MOD;
                                cout << mm << ' ' << l << ' ' << r << ' ' << dp[mm][l][r] << endl;
                        }
                }
        }
        */
        dp[0][n] = 1;
        FOR(mm, 1, m + 1) {
                FOR(sz, 1, n + 1) {
                        dp[mm][sz] = dp[mm - 1][sz + 1] + dp[mm - 1][sz] * 2ll * (n - sz + (sz == 1));
                        dp[mm][sz] %= MOD;
                }
        }
        int ans = 0; 
        FOR(i, 0, n) FOR(j, i, n) if (sorted[i][j]) {
                ans += dp[m][j - i + 1] * C(n - (j - i + 1), i);
                ans %= MOD;
        }
        cout << ans << '\n';
        return 0;
}
//https://github.com/conlacda/atcoder-testcases/tree/arc112/arc112/E