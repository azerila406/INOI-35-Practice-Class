/* In the name of Allah */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define Size(x) ((int)(x).size())
#define Precision(i) cout << fixed << setprecision(i)

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int MAX_N = 1e5 + 10;
vector <pii> adj[MAX_N];
int seen[MAX_N];
int par[MAX_N];
int ok[MAX_N];

int get_par(int u) {
	return ~par[u] ? (par[u] = get_par(par[u])) : u;
}

void merge(int u, int v) {
	u = get_par(u), v = get_par(v);
	if(u == v)
		return;
	par[v] = u;
}

int dfs(int u, int h = 1, int p = -1) {
	seen[u] = h;
	int mn_e = h;

	for(auto i : adj[u]) {
		int v = i.X, x = i.Y;
		if(!seen[v]) {
			int t = dfs(v, h + 1, x);
			t <= h ? ok[x] = 1 : ok[x] = 2;
			mn_e = min(mn_e, t);
		}
		else if(x != p) {
			ok[x] = 1;
			mn_e = min(mn_e, seen[v]);
		}
	}

	return mn_e;
}

int main() {
	ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector <pair <pii, pii>> E;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		u--, v--;
		E.pb(mp(mp(w, i), mp(u, v)));
	}

	sort(E.begin(), E.end());
	memset(par, -1, sizeof par);
	for(int i = 0, s = 0; s < m; i++) {
		if(i == m || E[i].X.X != E[s].X.X) {
			vector <int> vec;
			for(int j = s; j < i; j++) {
				int x = E[j].X.Y;
				int u = E[j].Y.X, v = E[j].Y.Y;

				u = get_par(u), v = get_par(v);
				if(u != v) {
					adj[u].pb(mp(v, x));
					adj[v].pb(mp(u, x));
					vec.pb(u), vec.pb(v);
				}
			}

			sort(vec.begin(), vec.end());
			vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
			for(auto u : vec)
				if(!seen[u])
					dfs(u);

			for(auto u : vec)
				seen[u] = 0, adj[u].clear();
			while(s < i) {
				int u = E[s].Y.X, v = E[s].Y.Y;
				merge(u, v), s++;
			}
		}
	}

	for(int i = 0; i < m; i++)
		cout << (ok[i] ? (ok[i] > 1 ? "any" : "at least one") : "none") << endl;
}
