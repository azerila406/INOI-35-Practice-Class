#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_total_n = 2e5;
    int t = randint(1, 10000); // number of test cases
    vector<int> ns;

    int total_n = 0;

    // Smart distribution: pick sizes that sum up to max_total_n
    while (t > 0 && total_n < max_total_n) {
        int remaining = max_total_n - total_n;
        int n = randint(1, remaining);
        ns.push_back(n);
        total_n += n;
        --t;
    }

    cout << ns.size() << '\n'; // actual number of test cases
    for (int n : ns) {
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << randint(1, 1'000'000'000) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
