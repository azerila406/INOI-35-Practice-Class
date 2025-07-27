#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = randint((int) 1000, (int) 3e5);
    int m;
    do {
        m = randint((int) 1e5, (int) 5e5);
    } while (m < n);

    cout << n << " " << m << "\n";

    vector<pair<int, int>> edges;
    set<pair<int, int>> used;

    for (int i = 2; i <= n; ++i) {
        int u = i;
        int v = randint(1, i - 1);
        int w = randint(1, 500000);
        cout << u << " " << v << " " << w << "\n";
        edges.emplace_back(u, v);
        used.insert({min(u, v), max(u, v)});
    }

    for (int i = n; i < m; ++i) {
        int u = randint(1, n);
        int v = randint(1, n);
        while (u == v) v = randint(1, n);
        int w = randint(1, 500000);
        cout << u << " " << v << " " << w << "\n";
        edges.emplace_back(u, v);
    }

    int q = 100000;
    cout << q << "\n";

    int max_total_k = 500000;
    int total_k = 0;
    for (int i = 0; i < q; ++i) {
        int remaining_queries = q - i;
        int remaining_k = max_total_k - total_k;

        if (remaining_k <= 0) assert(false);

        int max_ki = min(m, remaining_k - (remaining_queries - 1));
        int ki = randint(1, max_ki);

         total_k += ki;
         cout << ki << " ";

          set<int> indices;
          while ((int)indices.size() < ki) {
             indices.insert(randint(1, m));
        }
     for (int idx : indices) cout << idx << " ";
    cout << "\n";
}

    return 0;
}
