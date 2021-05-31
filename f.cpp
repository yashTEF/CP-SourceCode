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
const ll INF = 1e9 + 7;

ll pow(ll a, ll p) {
	ll prod = 1;
	while (p > 0) {
		if (p & 1) {
			prod = prod * a % INF;
		}
		a = a * a % INF;
		p >>= 1;
	}
	return prod;
}

ll inv(ll a) {
	return pow(a, INF - 2);
}

void solve() {
	ll n;
	cin >> n;
	ll ans = 0;
	ans = (ans + pow(2LL, pow(n, 2LL))) % INF;
	ans %= INF;
	if (n & 1) {
		ans = (ans + (pow(2LL, (pow(n, 2LL) + 3LL) / 4LL)) * 2LL % INF) % INF;
		ans = (ans + (pow(2LL , (pow(n, 2LL) + 1LL) / 2LL)) % INF) % INF ;
		ans %= INF;
	} else {
		ans = (ans + (pow(2LL, pow(n, 2LL) / 4LL) * 2LL % INF)) % INF;
		ans = (ans + (pow(2LL , pow(n, 2LL) / 2LL) % INF)) % INF;
		ans %= INF;
	}
	ans = ans * inv(4LL) % INF;
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