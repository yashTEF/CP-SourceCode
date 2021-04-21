#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;

clock_t start;

double runtime() {
	return (double) (clock() - start) / CLOCKS_PER_SEC;
}



typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 10;

ll pow(ll a, ll p) {
	ll prod = 1;
	while (p > 0) {
		if (p & 1) {
			prod = prod * a % MOD;
		}
		a = a * a % MOD;
		p >>= 1;
	}
	return prod;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> deg(n, 0);
	vector<int> fri[m];
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int id;
			cin >> id;
			id--;
			fri[i].push_back(id);
		}
	}
	vector<int> c(m);
	int bound = (m + 1) / 2;
	for (int i = 0; i < m; ++i) {
		if (fri[i].size() == 1) {
			deg[fri[i][0]]++;
			c[i] = fri[i][0];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (deg[i] > bound) {
			cout << "NO" << '\n';
			return;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (fri[i].size() != 1) {
			int min_deg = m + 1;
			int id = -1;
			for (int x : fri[i]) {
				if (deg[x] < min_deg) {
					id = x;
					min_deg = deg[x];
				}
			}
			c[i] = id;
			++deg[id];
		}
	}
	cout << "YES" << '\n';
	for (int i = 0; i < m; ++i) {
		cout << c[i] + 1 << ' ';
	}
	cout << '\n';

}

int main() {
	start = clock();
							#ifdef LOCAL
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
							#endif
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;

}				
