#include "bits/stdc++.h"
#define int long long
using namespace std;
const long long INF = 1ll << 60;
const int N = 1e5 + 5;
int n, s, x[N], p[N];

int solve(int l, int r, int i) {
	if (x[r] <= s || x[l] >= s) 
		return abs(x[i] - s);
	if (p[l] < p[r]) {
		p[r] += p[l];	
		return solve(l + 1, r, r) + (i == l ? x[r] - x[l] : 0ll);
	}
	else {
		p[l] += p[r];
		return solve(l, r - 1, l) + (i == r ? x[r] - x[l] : 0ll);
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> p[i];
	}
	cout << max(solve(0, n - 1, 0), solve(0, n - 1, n - 1)) << '\n';
	return 0;
}
//https://atcoder.jp/contests/agc023/submissions/38691948