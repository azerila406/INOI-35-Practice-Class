#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
const int N = 2e5 + 111;
int n, col[N];
vector <int> gr[N];
 
pair <int, int> dfs(int v, int p) {
    pair <int, int> ans = {0, v};
    for (int u: gr[v]) {
        if (u != p) {
            auto x = dfs(u, v);
            ans = max(ans, {x.first + (col[u] != col[v]), x.second});
        }
    }
    return ans;
}
 
void solve() {
    cout << (dfs(dfs(0, -1).second, -1).first + 1) / 2;
}
 
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    for (int i = 0, v, u; i < n - 1; i++) {
        cin >> v >> u;
        gr[--v].pb(--u);
        gr[u].pb(v);
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    read();
    solve();
}