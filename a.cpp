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


mt19937_64 rng(chrono :: steady_clock :: now().time_since_epoch().count());

using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e9 + 7;
const int B = 31;

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

void solve(int test) {
	int N;
	cin >> N;
	vector<int> h(N), k(N);
	for (int i = 0; i < N; ++i) {
		cin >> k[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> h[i];
	}
	vector<int> suff(N);
	for (int i = N - 1; i >= 0; --i) {
		suff[i] = k[i] - h[i] + 1;
		debug(suff[i]);
		if (i + 1 < N) {
			suff[i] = min(suff[i + 1], suff[i]);
		}
	}
	debug(suff);	
	int st = suff[0];
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		if (i == N - 1 || suff[i + 1] > k[i]) {
			ll len = k[i] - st + 1;
			debug(k[i], st);
			ans += len * (len + 1) / 2;
			if (i + 1 < N)
				st = suff[i + 1];
		}
	}
	cout << ans << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) solve(i);

		return 0;
}	