#include<bits/stdc++.h>

using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
using ull = unsigned long long;



typedef pair<int, int> pii;
const ll INF = 998244353LL;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	vector<ll> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i % INF;
	}
	sort(p.begin(), p.end(), [&](int x, int y) {
		return a[x] < a[y];
	});
	ll ans = fact[n];
	debug(ans);
	ll tmp = 1;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && a[p[i]] == a[p[j]]) {
			++j;
		}
		tmp = tmp * fact[j - i] % INF;
		i = j;
	}
	ans -= tmp;
	if (ans < 0) ans += INF;
	sort(p.begin(), p.end(), [&](int x, int y) {
		return b[x] < b[y];
	});
	debug(ans, tmp);
	tmp = 1;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && b[p[i]] == b[p[j]]) {
			++j;
		}
		debug(i, j);
		tmp = tmp * fact[j - i] % INF;
		i = j;
	}
	ans -= tmp;
 	if (ans < 0) ans += INF;
 	sort(p.begin(), p.end(), [&](int x, int y) {
 		if (a[x] == a[y])
 			return b[x] < b[y];
 		return a[x] < a[y];
 	});
 	debug(ans, tmp);
 	for (int i = 0; i + 1 < n; ++i) {
 		if (b[p[i]] > b[p[i + 1]]) {
 			cout << ans << '\n';
 			return;
 		}
 	}
 	tmp = 1;
 	for (int i = 0; i < n;) {
 		int j = i;
 		while (j < n && (a[p[i]] == a[p[j]] && b[p[i]] == b[p[j]])) {
 			++j;
 		}
 		tmp = tmp * fact[j - i] % INF;
 		i = j;
 	}
 	ans = (ans + tmp) % INF;
 	debug(ans);
 	cout << ans << '\n';
}

int main() {
	#ifdef LOCAL	

	freopen("in1.txt", "r", stdin);
	freopen("op1.txt", "w", stdout);

	#endif
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;

}				