#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 9900, m = 9900;
    vector<pair<int, int>> lit;

    for (int c = 1; c <= m; c++) {
        lit.emplace_back(1, c);
    }

    cout << n << " " << m << " " << lit.size() << "\n";
    for (auto [r, c] : lit) cout << r << " " << c << "\n";

    return 0;
}