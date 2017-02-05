#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define y1 stupid_cmathlksjdfdlkfjsldjflksjdfkljslkdflskdfiowewru
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()

const int inf = (int)1e9;
const int mod = inf + 7;

int n, m;
vector<pii> e;
vector<int> g[100100], gr[100100];
// e = {(1, 2); (2, 1); (2, 3); (3, 2); (1, 3); (3, 1); (2, 5); (5, 2)}
int tin[100100], fup[100100], used[100100], timer = 0;
int is_bridge[200200];
int col[200200], sz;

void dfs(int v, int par) {
    used[v] = 1;
    tin[v] = timer++;
    fup[v] = tin[v];
    // g[v]
    forit (it, g[v]) {
        int ind = *it;
        int to = e[ind].s;
        if (to == par) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                is_bridge[ind] = 1;
                is_bridge[ind^1] = 1;
            }
        }
    }
}

void dfs1(int v, int c) {
    col[v] = c;
    forit (it, g[v]) {
        int ind = *it;
        int to = e[ind].s;
        if (is_bridge[ind]) continue;
        if (col[to] == c) continue;
        dfs1(to, c);
    }
}

int main(){

    scanf("%d%d", &n, &m);
    for (int i = 0, x = 2, y = 1291231; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--; y--;
        e.pb(mp(x, y));
        g[x].pb(sz(e) - 1);
        e.pb(mp(y, x));
        g[y].pb(sz(e) - 1);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) col[i] = -1;

    sz = 0;
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            dfs1(i, sz);
            sz++;
        }
    }

    for (int i = 0; i < sz(e); i++) {
        int x = e[i].f, y = e[i].s;
        if (is_bridge[i]) {
            gr[col[x]].pb(col[y]);
        }
    }

    return 0;
}