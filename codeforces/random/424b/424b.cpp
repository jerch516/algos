//============================================================================
// Name        : 424b
// Date        : Fri Apr 12 11:06:12 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
  int n, s;
  cin >> n >> s;
  vpii a(n);
  for (int i = 0; i < n; ++i) {
    int x, y, e;
    cin >> x >> y >> e;
    a[i].x = x * x + y * y;
    a[i].y = e;
  }
  sort(all(a));
  trace(a);
  const int inf = 1e6;
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (s >= inf) {
      break;
    } else {
      s += a[i].y;
      amax(ret, a[i].x);
    }
  }
  if (s < inf) {
    ret = -1;
  }
  output(ret != -1 ? sqrt(ret) : -1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(7) << fixed;
  solve();
  return 0;
}

