#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)x.size()
#define endl '\n'
const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const ll linf = 9e18 + 5;


int n;
const int N = 2e5 + 5;
vector<int> adj[N];
struct block;
multiset<block> have[N];
int v[N];


ll ans = 0;

struct block {
	int zero;
	int one;

	bool operator < (const block &b) const {
		ll o1 = 1ll * one * b.zero;
		ll o2 = 1ll * zero * b.one;

		return o1 < o2;
	}
};

void init() {
}

void input() {
	cin >> n;

	for (int u = 2; u <= n; u++) {
		int p;
		cin >> p;

		adj[p].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
}

void mrg(multiset<block> &s1, multiset<block> &s2) {
	if (sz(s1) < sz(s2)) {
		swap(s2, s1);
	}

	for (auto x : s2) {
		s1.insert(x);
	}
	s2.clear();
}

void dfs(int u) {
	for (auto v : adj[u]) {
		dfs(v);
	
		mrg(have[u], have[v]);
	}

	block now;
	if (v[u]) {
		now.zero = 0;
		now.one = 1;
	}
	else {
		now.zero = 1;
		now.one = 0;
	}

	while (!have[u].empty()) {
		if (now < *have[u].begin()) {
			break;
		}

		ans += (1ll * now.one * have[u].begin()->zero);

		now.zero += have[u].begin()->zero;
		now.one += have[u].begin()->one;

		have[u].erase(have[u].begin());
	}

	have[u].insert(now);
}

void solve() {
	dfs(1);

	block all;
	all.zero = 0;
	all.one = 0;
	for (auto x : have[1]) {
		ans += 1ll * all.one * x.zero;

		all.zero += x.zero;
		all.one += x.one;
	}

	cout << ans;
}

void output() {
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int number_of_testcases = 1;
	//cin >> number_of_testcases;
	while (number_of_testcases--) {
		init();

		input();

		solve();

		output();
	}

	return 0;
}
//https://atcoder.jp/contests/agc023/submissions/36725226