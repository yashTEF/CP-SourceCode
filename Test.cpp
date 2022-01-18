#include <bits/stdc++.h>

using namespace std;

clock_t start;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

double exec_time() {
	return (double) (clock() - start) / CLOCKS_PER_SEC;
}

mt19937_64 rng(chrono :: steady_clock :: now().time_since_epoch().count());

ll rand(ll B) {
	return (ull) rng() % B;
}

void test() {
	// int t = 10;
	// cout << t << '\n';
	// for (int i = 1; i <= t; ++i) {
	// 	int n = rand(10) + 1, m = rand(10) + 1;
	// 	int a, b;
	// 	a = rand(1000) + 1, b = rand(1000) + 1;
	// 	cout << n << ' ' << m << ' ' << a << ' ' << b << '\n';
	// }
	set<int> s;
	s.insert(1);
	auto it = s.begin();
	cout << *it << '\n';
	s.insert(0);
	cout << *it << '\n';
}

int main() {
	test();
	return 0;
}