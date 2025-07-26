#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_W = 1e6;
const int MAX_N = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int n = 100000; // can be changed to any value ≤ 1e5
    int m = n + rand() % (MAX_N - n + 1); // ensure m ≥ n-1 and ≤ 1e5

    cout << n << " " << m << "\n";

    set<pair<int, int>> edges;

    // First generate a spanning tree to make it connected
    for (int i = 2; i <= n; ++i) {
        int u = i;
        int v = rand() % (i - 1) + 1; // connect to some node before i
        int w = rand() % MAX_W + 1;

        edges.insert({min(u, v), max(u, v)});
        cout << u << " " << v << " " << w << "\n";
    }

    // Now add extra random edges to reach m edges
    while ((int)edges.size() < m) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        if (u == v) continue;

        pair<int, int> e = {min(u, v), max(u, v)};
        if (edges.count(e)) continue;

        int w = rand() % MAX_W + 1;
        edges.insert(e);
        cout << u << " " << v << " " << w << "\n";
    }

    return 0;
}

//CHATGPT