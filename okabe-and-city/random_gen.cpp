#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n = rng() % 9900 + 5, m = rng() % 9900 + 5;

    set<pair<int, int>> lit;
    lit.insert({1, 1});

    int trials = 3; 
    int k = min(n * m / 5, 9950);
    int res = k;
    for (int i = 0; i < trials; i++) {
        int val = rng() % k;
        if (val < res) res = val;
    }
    k = res;

    while ((int)lit.size() < k) {
        int r = 1 + rng() % n;
        int c = 1 + rng() % m;
        lit.insert({r, c});
    }

    cout << n << " " << m << " " << lit.size() << "\n";
    for (auto [r, c] : lit) cout << r << " " << c << "\n";
    cout << "\n";

    return 0;
}