//============================================================================
// Name        : 1017b
// Date        : Sun Apr 14 17:02:21 CST 2019
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
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n)
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
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  map<pair<char, char>, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[{a[i], b[i]}]++;
  }
  vi t(4, 0);
  t[0] = mp[{'0', '0'}];
  t[1] = mp[{'0', '1'}];
  t[2] = mp[{'1', '0'}];
  t[3] = mp[{'1', '1'}];
  trace(mp);
  ll ret = (ll) t[0] * t[2] + (ll) t[0] * t[3] + (ll) t[1] * t[2];
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
