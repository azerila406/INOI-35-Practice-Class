#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 998244353;
template<class T>
inline T power(T a, i64 b) {
	T res = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) res *= a;
	return res;
}
int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}
struct Z {
	int x;
	Z(int _x = 0) : x(norm(_x)) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x >= P) x -= P;
		return *this;
	}
	inline Z &operator-=(const Z &rhs) {
		x -= rhs.x;
		if (x < 0) x += P;
		return *this;
	}
	inline Z &operator*=(const Z &rhs) {
		x = 1ull * x * rhs.x % P;
		return *this;
	}
	inline Z inv() const {
		return power(*this, P - 2);
	}
	inline Z &operator/=(const Z &rhs) {
		*this *= rhs.inv();
		return *this;
	}
	inline Z operator+(const Z &rhs) const {
		Z res = *this;
		return res += rhs;
	}
	inline Z operator-(const Z &rhs) const {
		Z res = *this;
		return res -= rhs;
	}
	inline Z operator*(const Z &rhs) const {
		Z res = *this;
		return res *= rhs;
	}
	inline Z operator/(const Z &rhs) const {
		Z res = *this;
		return res /= rhs;
	}
};
Z fac[3000005], ifac[3000005], inv[3000005], pw[3000005];
void init(int n) {
	fac[0] = inv[0] = pw[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i, pw[i] = pw[i - 1] + pw[i - 1];
	ifac[n] = power(fac[n], P - 2);
	for (int i = n - 1; ~i; --i)
		ifac[i] = ifac[i + 1] * (i + 1), inv[i + 1] = fac[i] * ifac[i + 1];
}
Z C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fac[n] * ifac[m] * ifac[n - m];
}
Z calc(int n, int m) {
    return C(n + m - 1, m - 1);
}
Z get(int a, int b, int c) {
    return fac[a + b + c] * ifac[a] * ifac[b] * ifac[c];
}
int main() {
    init(3000000);
    int A, B, C;
    cin >> A >> B >> C;
    Z ans = get(A, B, C);
    int lim = min({A, B, C});
    for (int i = 1; i <= lim; ++i) {
        Z res = calc(A + B + C - 3 * i, i) * pw[i - 1] * 3;
        res += (calc(A + B + C - 3 * i - 1, i + 1)) * pw[i];
        if (i & 1) res = -res;
        ans += res * get(A - i, B - i, C - i);
    }
    cout << ans.x << "\n";
    return 0;
}
//https://atcoder.jp/contests/agc058/submissions/34049430