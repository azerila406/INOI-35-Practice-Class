#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
using namespace std;
const long long INF = 1ll << 60;
const int MXN = 5e5 + 5;
int N, M, a[MXN];

bool check(int m) {
	for (int i = 2 * m + 1, j = 2 * N; i <= 2 * N; i++, j--) if (a[i] + a[j] < M) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;	
	FOR(i, 1, 2 * N + 1) cin >> a[i];
	sort(a + 1, a + 2 * N + 1);
	
	int l = -1, r = N;
	while (r - l > 1) {
		int m = l + r >> 1;
		if (check(m)) r = m;
		else l = m;
	}
	int mx1 = 0, mx2 = 0;
	for (int i = 2 * r + 1, j = 2 * N; i <= 2 * N; i++, j--) mx1 = max(mx1, a[i] + a[j]);
	for (int i = 1, j = 2 * r; j >= 1; i++, j--) mx2 = max(mx2, a[i] + a[j]);
	assert((r == N || mx1 >= M) && mx2 < M);
	cout << max(mx1 - M, mx2) << '\n';
	return 0;
}
//https://atcoder.jp/contests/agc032/submissions/41651277