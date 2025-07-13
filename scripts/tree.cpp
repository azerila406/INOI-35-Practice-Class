#include "bits/stdc++.h"
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
	for(long i = 2; i <= n; ++i) cout << (rand() % (i - 1) + 1) << " " << i << "\n";
	return 0;
}