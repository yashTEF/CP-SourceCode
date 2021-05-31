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
	cerr << "here\n";
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
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;

}				