#include "bits/stdc++.h"
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    assert(n >= 2);
    cout << "1 2\n";
    
	for(long i = 3; i <= n; ++i) cout << (rand() & 1 ? (i - 1) : (i - 2)) << " " << i << "\n";
    
	return 0;
}