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

ll gcd(ll a, ll b) {
	if (b == 0) 
		return a;
	return gcd(b, a % b);
}

struct TestCase {
	bool ok = true;
	vector<vector<int>> adj;
	vector<ll> p, h, sz;

	TestCase() {
		int n;
		ll m;
		cin >> n >> m;
		adj = vector<vector<int>> (n, vector<int>());
		h.resize(n), p.resize(n), sz.resize(n);
		for (int i = 0; i < n; ++i) 
			cin >> p[i];
		for (int i = 0; i < n; ++i) 
			cin >> h[i];
		for (int i = 0; i + 1 < n; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(0, -1);
		cout << ((ok) ? "YES" : "NO") << '\n';
	}

	void dfs1(int s, int anc) {
		sz[s] = p[s];
		ll min_happy = 0;
		for (int x : adj[s]) {
			if (x != anc) {
				dfs1(x, s);
				sz[s] += sz[x];
				min_happy += (h[x] + sz[x]) / 2;
			}
		}
		ll tmp = h[s] + sz[s];
		if (tmp % 2) ok = false;
		ll happy = tmp / 2;
		if (happy < min_happy || happy < 0 || happy > sz[s]) ok = false;
	}
};


int main() {
	start = clock();
	#ifdef LOCAL

	freopen("in1.txt", "r", stdin);
	freopen("op1.txt", "w", stdout);

	#endif
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		TestCase tc;
	}
	return 0;

}				