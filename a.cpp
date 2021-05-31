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
	while(p > 0) {
		if (p & 1) {
			prod = prod * a % INF;
		}
		a = a * a % INF;
		p >>= 1;
	}
	return prod;
}

ll brute() {
	ll N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	vector<int> p(N);
	iota(p.begin(), p.end(), 0);
	ll ans = 0;
	do {

	} while (next_permutation(p.begin(), p.end()));	
	return ans;
}


ll solve() {
	ll N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	ll ans = 0LL;
	debug(s);
	ll t = N / 2 + (N % 2 != 0);
	for (ll i = 0; i < t; ++i) {
		ll cur = s[i] - 'a';
		ll rem = (t - i - 1);
		debug(cur, rem, t);	
		ans = (ans + (cur * 1LL * pow(K, rem) % INF)) % INF;
	}	
	debug(ans);
	bool ok = false;
	for (ll i = t - 1; i >= 0; --i) {
		if (s[i] != s[N - 1 - i]) {
			if (s[i] < s[N - 1 - i]) {
				ok = true;
			}
			break;
		}
	}
	if (ok) {
		ans++;
		ans %= INF;	
	}
	return ans;
}

int main() {
	#ifdef LOCAL	

	freopen("in1.txt", "r", stdin);
	freopen("op1.txt", "w", stdout);

	#endif
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;	
	for (int i = 1; i <= tt; ++i) {
		auto ans = solve	();
		cout << "Case #" << i << ": " << ans << '\n'; 
	}
	return 0;

}				