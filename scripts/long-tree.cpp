#include "bits/stdc++.h"
using namespace std;

signed main(int argc, char* argv[]) {
    ios::sync_with_stdio(0), cin.tie(0);

    if (argc < 2) {
        cerr << "Usage: ./a.out <n>\n";
        return 1;
    }

    int n = atoi(argv[1]);
    assert(n >= 2);

    cout << "1 2\n";
    for (long i = 3; i <= n; ++i)
        cout << (rand() & 1 ? (i - 1) : (i - 2)) << " " << i << "\n";

    return 0;
}