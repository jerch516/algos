// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 209;
const int maxm = 209 * 209;
const int inf = 0x3f3f3f3f;

typedef struct Edge {
    int u, v, w, next;
} Edge;

// Link list to represent a graph.
Edge edges[maxm];
int head[maxn];

int dist[maxn];
int busy[maxn];
int counters[maxn];
bool visit[maxn];
bool cycle[maxn];
int n, m;

void dfs(int src, bool *array) {
    array[src] = 1;
    for (int i = head[src]; i != -1; i = edges[i].next) {
        if (!array[edges[i].v]) {
            dfs(edges[i].v, array);
        }
    }
}

void spfa() {
    mst(visit, 0);
    // mst(cycle, 0);
    mst(dist, 0x3f);
    mst(counters, 0);

    queue<int> dq;
    dq.push(1);
    visit[1] = 1;
    dist[1] = 0;

    while (!dq.empty()) {
        int u = dq.front(); dq.pop();
        visit[u] = 0;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v, w = edges[i].w;
            if (dist[v] > -inf && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = 1;
                    dq.push(v);
                    if (++counters[v] >= n) {
                    // Here we can either assign -inf to its vaule which makes this
                    // node dead and it will never be updated later or use a sperate
                    // dfs call to find all nodes in this cycle and mark them.
                        // dfs(v, cycle);
                        dist[v] = -inf;
                    }
                }
            }
        }
    }
}

void bellman_ford() {
    mst(dist, 0x3f);
    mst(cycle, 0);
    dist[1] = 0;

    bool negative_cycle = 0;
    fori (step, 1, n + 1) {
        bool update = 0;
        fori (i, 1, n + 1) {
            int u = i;
            for (int j = head[u]; j != -1; j = edges[j].next) {
                int v = edges[j].v, w = edges[j].w;
                if (dist[v] > dist[u] + w) {
                    update = 1;
                    dist[v] = dist[u] + w;
                    if (step == n) {
                        negative_cycle = 1;
                        dfs(v, cycle);
                    }
                }
            }
        }
    }
}

int cube(int u, int v) {
    int x = busy[u], y = busy[v];
    return (y - x) * (y - x) * (y - x);
}

void solve_spfa(int tt) {
    cin >> n;
    fori (i, 1, n + 1) {
        cin >> busy[i];
    }

    cin >> m;
    mst(head, -1);
    fori (i, 0, m) {
        int u, v; cin >> u >> v;
        Edge e = {u, v, cube(u, v), head[u]};
        edges[i] = e;
        head[u] = i;
    }

    spfa();

    cout << "Case " << tt << ":\n";
    int q; cin >> q;
    fori (i, 0, q) {
        int to; cin >> to;
        if (!cycle[to] && 3 <= dist[to] && dist[to] < inf) {
            output(dist[to]);
        } else {
            output("?");
        }
    }
}

void solve_bellman_ford(int tt) {
    cin >> n;
    fori (i, 1, n + 1) {
        cin >> busy[i];
    }

    cin >> m;
    mst(head, -1);
    fori (i, 0, m) {
        int u, v; cin >> u >> v;
        Edge e = {u, v, cube(u, v), head[u]};
        edges[i] = e;
        head[u] = i;
    }

// The dijkstra algorithm can't handle the negative weight, spfa also can
// handle the negative weight and also can check the graph connectivity.

// The bellman ford algorithm can handle the negative weight and also can
// detect negative-weighted cycle, but it cann't check the graph
// connectivity, thus we need a sperate dfs call to check.
    mst(visit, 0);
    dfs(1, visit);
    bellman_ford();

    cout << "Case " << tt << ":\n";
    int q; cin >> q;
    fori (i, 0, q) {
        int to; cin >> to;
        if (visit[to] && 3 <= dist[to] && dist[to] < inf && !cycle[to]) {
            output(dist[to]);
        } else {
            output("?");
        }
    }
}

int main() {
    // Is this the problem that keep showing runtime error??
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        // solve_spfa(i);
        solve_bellman_ford(i);
    }
    return 0;
}

