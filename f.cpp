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
using pii = pair<int, int>;

void solve() {
	int N;
	cin >> N;
	vector<int> x(N), p(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
		--x[i];
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int i, int j) {
		return x[i] < x[j];
	});
	vector<int> ans(N * N, -1);
	int taken = 0;
	for (int i : p) {
		if (x[i] - taken < i) {
			cout << "No\n";
			return;
		}
		ans[x[i]] = i + 1;
		int remaining = i;
		for (int j = 0; j < x[i]; ++j) {
			if (ans[j] == -1 && remaining) {
				ans[j] = i + 1;
				--remaining;
			}
		}
		taken += i + 1;
	}	
	debug(ans);
	for (int i : p) {
		int remaining = N - (i + 1);
		for (int j = x[i] + 1; j < N * N; ++j) {
			if (remaining == 0) {
				break;
			}
			if (ans[j] == -1) {
				ans[j] = i + 1;
				--remaining;
			}
		}
		if (remaining != 0) {
			cout << "No\n";
			return;
		}
	}
	// assert(taken == N * N);
	// for (int i = 1; i <= N; ++i) {
	// 	int times = 0;
	// 	for (int j = 0; j < N * N; ++j) {
	// 		if (ans[j] == i) {
	// 			++times;
	// 			if (times == i) {
	// 				assert(j == x[i - 1]);
	// 			}
	// 		}
	// 	}
	// 	assert(times == N);
	// }
	cout << "Yes\n";
	for (auto c : ans) {
		cout << c << ' ';
	}
	cout << '\n';
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
