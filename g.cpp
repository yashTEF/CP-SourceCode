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
using ui = unsigned int;
using ull = unsigned long long;

clock_t start;

double runtime() {
	return (double) (clock() - start) / CLOCKS_PER_SEC;
}

typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

ll inv(ll a) {
	return pow(a, MOD - 2);
}

ll pow(ll a, ll p) {
	ll prod = 1;
	while (p > 0) {
		if (p & 1) prod = prod * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return prod;
}



void solve() {

}
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
	int N = 1e7;
	vector<int> div(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; j += i) {
			div[j] += i;
		}
	}
	vector<int> done(N + 1, INF);
	for (int i = 1; i <= N; ++i)
		if (div[i] <= N) {
			done[div[i]] = min(done[div[i]], i);
		}
	while (tt--) {
		int n;
		cin >> n;
		if (done[n] == INF) {
			cout << -1 << '\n';
		} else {
			cout << done[n] << '\n';
		}
	}
	// cout << runtime() << '\n';
	return 0;

}				