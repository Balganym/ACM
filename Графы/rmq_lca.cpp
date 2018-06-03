#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
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
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define fo(i,k,n) for(size_t i=k; (int)i<n; ++i)
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, m, T, l;
int tin[500100], tout[500100];
vector<int> g[500100], up[500100];
vector <pii> q;

void dfs(int v, int p = 0){
    
    tin[v] = ++T;
    up[v][0] = p;
    
    for(int i=1; i<=l; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    fo(i,0,sz(g[v])){
        int to = g[v][i];
        if(to != p)
            dfs(to, v);
    }
    
    tout[v] = ++T;
    
}

bool check(int a, int b){
    
    return tin[a] <= tin[b] && tout[a] >= tout[b];
    
}


int lca(int a, int b){
    if(check(a, b)) return a;
    if(check(b, a)) return b;
    for(int i = l; i>=0; i--){
        if(!check(up[a][i], b))
            a = up[a][i];
    }
    
    return up[a][0];
    
}


int main(){
    
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    
    int test;
    l = 1;
    
    scanf("%d", &test);
    
    while(test--){
        string s;
        int a, b;
        char ch[4];
        scanf("%s%d%d", ch, &a,&b);
        n = max(n,max(a,b));
        a--; b--;
        s = ch;
        if(s == "GET"){
            q.pb(mp(a,b));
        }
        else{
            g[a].pb(b);
            g[b].pb(a);
        }
    }
    
    while((1<<l)<=n) l++;
    fo(i,0,n){
        up[i].resize(l+1);
    }
    
    dfs(0);
    
    fo(i,0,sz(q)){
        int a = q[i].first, b = q[i].second;
        printf("%d\n", lca(a, b)+1);
    }
    
    return 0;
}