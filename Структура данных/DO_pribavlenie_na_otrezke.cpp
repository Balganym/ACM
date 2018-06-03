#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

#define fname ""
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define sz(a) (int)a.size()
#define all(v) v.begin(), v.end()
#define forit(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int N = 100100;

ll T, n, a[100100], q;

struct node{
    ll sum, val;
} t[400400];


void build(ll v, ll tl, ll tr){
    
    if(tl == tr){
        t[v].sum = 0;
        t[v].val = 0;
        return;
    }
    
    ll md = (tl + tr) >> 1;
    build(v+v, tl, md);
    build(v+v+1, md + 1, tr);
    t[v].sum = 0;
    t[v].val = 0;
}

void push(ll v, ll tl, ll tr){
    if(!t[v].val) return;
    
    ll md = (tl + tr) >> 1;
    t[v+v].val += t[v].val;
    t[v+v+1].val += t[v].val;
    t[v+v].sum += t[v].val * (md - tl + 1);
    t[v+v+1].sum += t[v].val * (tr - md);
    t[v].val = 0;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(r < tl || tr < l) return;
    if(l <= tl && tr <= r){
        t[v].sum += val * (tr - tl + 1);
        t[v].val += val;
        return;
    }
    push(v, tl, tr);
    ll md = (tl + tr) >> 1;
    upd(v+v, tl, md, l, min(r, md), val);
    upd(v+v+1, md+1, tr, max(l, md+1), r, val);
    t[v].sum = t[v+v].sum + t[v+v+1].sum;
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    
    if(tl > r || l > tr) return 0;
    if(tl >= l && tr <= r) return t[v].sum;
    
    ll md = (tl + tr) >> 1;
    push(v, tl, tr);
    return get(v+v, tl, md, l, r) + get(v+v+1, md+1, tr, l, r);
}

void solve(){
    
    build(1, 0, 100000-1);
    scanf("%lld%lld", &n, &q);
    
    ll k,l,r,v;
    
    while(q--){
        scanf("%lld", &k);
        if(k){
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", get(1, 0, n-1, l, r));
        }else{
            scanf("%lld%lld%lld", &l,&r,&v);
            upd(1, 0, n-1, l, r, v);
        }
    }
}

int main(){
    
    cin >> T;
    
    for(int cs = 1; cs <= T; ++cs){
        printf("Case %d:\n", cs);
        solve();
    }
    
    return 0;
}

