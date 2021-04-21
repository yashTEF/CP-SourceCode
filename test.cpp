	#include <iostream>
	#include <cstdio>
	#include <cstdlib>
	#include <algorithm>
	#include <cmath>
	#include <vector>
	#include <set>
	#include <map>
	#include <unordered_set>
	#include <unordered_map>
	#include <queue>
	#include <ctime>
	#include <cassert>
	#include <complex>
	#include <string>
	#include <cstring>
	#include <chrono>
	#include <random>
	#include <bitset>
	#include <fstream>
using namespace std;

using ll = long long;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;


	#ifdef LOCAL
		#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
	#else
		#define	eprintf(...) 42
	#endif

clock_t start;

double runtime() {
	return (double) (clock() - start) / CLOCKS_PER_SEC;
}


const int maxn = 1e5 + 5;
const ll INF = (ll) 1e15;

vector<pair<int, int>> adj1[maxn], adj2[maxn];
bool vis1[maxn], vis2[maxn];
ll dist1[maxn], dist2[maxn];

vector<int> decrementBinaryNumber(string number, vector<string> requests) {
	
}
int main() {
	start = clock();
		#ifdef NDEBUG
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
		#endif
	int t = 1;
	// scanf("%d", &t);
	while (t--) solve();


	return 0;
}

