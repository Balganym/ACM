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

int t[400400], a[100100];

void build(int v, int tl, int tr){
    if(tl == tr) t[v] = a[tl];
    else{
        int mid = (tl + tr) >> 1;
        build(v+v, tl, mid);
        build(v+v+1, mid+1, tr);
        t[v] = t[v+v] + t[v+v+1];
    }
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr) t[v] = val;
    else{
        int mid = (tl + tr) >> 1;
        if(pos <= mid) update(v+v, tl, mid, pos, val);
        else update(v+v+1, mid+1, tr, pos, val);
        t[v] = t[v+v] + t[v+v+1];
    }
}

int get(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return t[v];
    
    int mid = (tl + tr) >> 1;
    int ans1 = get(v+v, tl, mid, l, r);
    int ans2 = get(v+v+1, mid+1, tr, l, r);
    return ans1 + ans2;
}

int n, q;
int main(){
    
    scanf("%d%d", &n, &q);
    
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    
    build(1, 0, n - 1);
    
    int l, r;
    while(q--){
        scanf("%d%d", &l,&r);
        l--, r--;
        cout << get(1, 0, n-1, l, r) << endl;
    }
    
    return 0;
}












