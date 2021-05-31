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

int main() {
	int tt = 10;
	cout << tt << '\n';
	for (int t = 0; t < tt; ++t) {	
	int n = rand(8) + 1;
		cout << n << ' ' << 5 << '\n';
		string s;
		for (int i = 0; i < n; ++i) {
			int cur = rand(5);
			s += (cur + 'a');
		}
		cout << s << '\n';
	}
	return 0;
}