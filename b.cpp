
#define _GLIBCXX_DEBUG 1;
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
typedef pair<int, int> pii;

void solve() {
	
}

int main() {

	// freopen("in1.txt", "r", stdin);
	// freopen("op1.txt", "w", stdout);

	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;

}				
