#include<bits/stdc++.h>
using namespace std;

vi quiet;
unordered_map<int, vi> mp;    
int cache[520];

int dfs(int x) {
  // If we can not make sure which person has more money.
  if (!mp.count(x)) return x; 
  if (cache[x]) return cache[x];

  vi g = mp[x];
  int least = quiet[x];
  int least_idx = x;

  fori(i, 0, sz(g)) {
  int t = dfs(g[i]);
  cache[g[i]] = t;
  if (quiet[t] < least) {
    least = quiet[t];
    least_idx = t;
  }
  }
  return least_idx;
}

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>>& richer, 
              vector<int>& q) {
  quiet = q;
  int n = sz(q);
  mp.clear();
  mst(cache, 0);

  fora(v, richer) {
    int lo = v[1];
    int hi = v[0];
    mp[lo].pb(hi);
  }

  fora(it, mp) {
    vi g = it.se;
    cout << it.fi << ": ";
    pvi(g);
  }

  vi res;   
  fori(i, 0, sz(q)) {
    int r;
    if (cache[i] > 0) r = cache[i];
    else r = dfs(i);
    res.pb(r);
  }
  return res;
  }
};

int main() {
   Solution go;
  vvi aa = {{0,2},{0,3},{0,5},{0,9},{0,10},{0,11},{0,13},{0,20},{0,22},{0,24},{0,25},{0,26},{0,32},{0,34},{0,35},{0,41},{0,43},{0,46},{0,48},{1,3},{1,5},{1,10},{1,11},{1,15},{1,21},{1,22},{1,25},{1,27},{1,30},{1,31},{1,33},{1,34},{1,36},{1,39},{1,40},{1,47},{1,48},{1,49},{2,3},{2,5},{2,6},{2,12},{2,15},{2,16},{2,18},{2,19},{2,20},{2,24},{2,25},{2,26},{2,29},{2,33},{2,37},{2,38},{2,39},{2,44},{2,47},{2,48},{2,49},{3,8},{3,9},{3,11},{3,12},{3,13},{3,16},{3,18},{3,20},{3,28},{3,30},{3,31},{3,32},{3,33},{3,34},{3,45},{3,46},{3,48},{4,6},{4,7},{4,9},{4,12},{4,13},{4,14},{4,15},{4,20},{4,21},{4,22},{4,26},{4,27},{4,29},{4,35},{4,36},{4,37},{4,38},{4,44},{4,45},{4,46},{5,6},{5,9},{5,11},{5,16},{5,17},{5,19},{5,23},{5,24},{5,25},{5,26},{5,27},{5,28},{5,29},{5,30},{5,35},{5,37},{5,40},{5,42},{5,43},{5,44},{5,45},{5,46},{5,47},{5,48},{6,7},{6,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,15},{6,16},{6,18},{6,21},{6,24},{6,25},{6,29},{6,30},{6,31},{6,37},{6,38},{6,40},{6,41},{6,42},{6,45},{6,46},{6,48},{6,49},{7,10},{7,11},{7,12},{7,13},{7,15},{7,17},{7,18},{7,19},{7,20},{7,21},{7,26},{7,31},{7,33},{7,36},{7,39},{8,10},{8,16},{8,19},{8,20},{8,22},{8,23},{8,24},{8,25},{8,26},{8,27},{8,29},{8,31},{8,33},{8,36},{8,41},{8,44},{8,45},{8,46},{8,48},{9,11},{9,13},{9,14},{9,15},{9,16},{9,17},{9,18},{9,19},{9,22},{9,28},{9,31},{9,34},{9,35},{9,39},{9,40},{9,42},{9,44},{9,49},{10,11},{10,14},{10,15},{10,16},{10,18},{10,19},{10,21},{10,26},{10,29},{10,33},{10,39},{10,44},{10,47},{10,48},{10,49},{11,13},{11,16},{11,18},{11,19},{11,20},{11,23},{11,25},{11,27},{11,29},{11,31},{11,32},{11,33},{11,35},{11,38},{11,39},{11,40},{11,43},{11,45},{11,47},{12,13},{12,17},{12,18},{12,19},{12,20},{12,21},{12,22},{12,23},{12,24},{12,29},{12,35},{12,36},{12,39},{12,40},{12,43},{12,46},{12,47},{12,49},{13,14},{13,15},{13,16},{13,18},{13,21},{13,22},{13,23},{13,28},{13,30},{13,32},{13,34},{13,36},{13,39},{13,43},{13,45},{13,46},{13,47},{13,48},{14,15},{14,16},{14,17},{14,18},{14,19},{14,20},{14,22},{14,25},{14,27},{14,28},{14,30},{14,32},{14,33},{14,34},{14,39},{14,40},{14,41},{14,42},{14,46},{14,47},{14,49},{15,17},{15,21},{15,22},{15,27},{15,28},{15,29},{15,30},{15,37},{15,38},{15,39},{15,40},{15,41},{15,42},{15,44},{15,45},{15,47},{16,17},{16,18},{16,20},{16,27},{16,29},{16,31},{16,36},{16,37},{16,38},{16,39},{16,40},{16,41},{16,42},{16,45},{16,46},{17,19},{17,23},{17,24},{17,25},{17,26},{17,28},{17,29},{17,31},{17,33},{17,34},{17,35},{17,38},{17,39},{17,41},{17,46},{17,47},{17,48},{17,49},{18,22},{18,23},{18,25},{18,27},{18,28},{18,29},{18,31},{18,36},{18,37},{18,39},{18,40},{18,41},{18,42},{18,43},{18,48},{19,20},{19,21},{19,22},{19,23},{19,24},{19,27},{19,28},{19,30},{19,31},{19,33},{19,35},{19,39},{19,40},{19,44},{19,47},{19,48},{20,25},{20,27},{20,28},{20,29},{20,32},{20,34},{20,37},{20,38},{20,41},{20,43},{20,44},{20,45},{20,46},{20,47},{20,49},{21,22},{21,24},{21,26},{21,27},{21,28},{21,29},{21,32},{21,36},{21,37},{21,43},{21,45},{21,47},{21,48},{22,23},{22,25},{22,28},{22,30},{22,32},{22,37},{22,41},{22,42},{22,44},{22,45},{22,47},{22,48},{22,49},{23,25},{23,26},{23,28},{23,29},{23,30},{23,31},{23,32},{23,33},{23,34},{23,35},{23,38},{23,39},{23,40},{23,42},{23,43},{23,46},{23,48},{23,49},{24,26},{24,27},{24,28},{24,30},{24,31},{24,33},{24,35},{24,37},{24,39},{24,40},{24,42},{24,43},{24,47},{24,48},{24,49},{25,28},{25,30},{25,31},{25,32},{25,35},{25,36},{25,39},{25,40},{25,43},{25,44},{25,45},{25,46},{26,28},{26,30},{26,31},{26,33},{26,36},{26,38},{26,40},{26,41},{26,42},{26,44},{26,45},{26,47},{26,48},{26,49},{27,28},{27,30},{27,34},{27,35},{27,36},{27,39},{27,40},{27,44},{27,45},{27,48},{28,30},{28,31},{28,32},{28,33},{28,34},{28,35},{28,36},{28,37},{28,41},{28,45},{28,46},{28,47},{29,30},{29,31},{29,33},{29,35},{29,36},{29,39},{29,40},{29,45},{29,46},{29,47},{30,31},{30,33},{30,37},{30,38},{30,39},{30,41},{30,43},{30,45},{30,46},{30,49},{31,34},{31,35},{31,36},{31,38},{31,40},{31,41},{31,43},{31,45},{31,49},{32,43},{32,44},{32,46},{32,47},{32,48},{33,35},{33,41},{33,43},{33,45},{33,46},{33,47},{34,36},{34,38},{34,39},{34,40},{34,41},{34,42},{34,44},{34,46},{34,48},{35,37},{35,43},{35,45},{36,37},{36,40},{36,43},{36,45},{36,46},{36,48},{37,38},{37,40},{37,42},{37,46},{37,47},{38,39},{38,40},{38,42},{38,46},{38,47},{38,49},{39,43},{39,45},{39,46},{39,47},{39,48},{39,49},{40,41},{40,42},{40,43},{40,45},{40,46},{40,47},{40,48},{41,45},{41,47},{41,48},{41,49},{42,44},{42,46},{42,47},{42,49},{43,44},{43,47},{43,48},{44,45},{44,46},{44,48},{44,49},{45,46},{45,47},{45,49},{46,47},{46,48},{46,49},{47,48},{48,49}};
  vi bb = {17,33,29,39,41,10,1,19,5,8,18,15,7,25,45,48,35,28,34,22,31,36,27,47,42,43,14,49,20,9,16,40,44,32,13,24,4,21,30,11,0,46,38,2,12,6,37,23,3,26};

  vi res = go.loudAndRich(aa, bb);
  pvi(res);
  return 0;
}
