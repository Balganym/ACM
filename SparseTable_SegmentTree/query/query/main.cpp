#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
using namespace std;

ll arr[100100];
int q, a, b;
vector <int> ans;
struct Node{
    ll mx, mn;
    
    Node(){
        mn = 1e9;
        mx = -1e9;
    }
    
    Node( int _mx, int _mn){
        mn = _mn;
        mx = _mx;
    }
    
} t[4*100100];

void build(int v, int tl, int tr){
    
    if(tl==tr){
        t[v].mn = arr[tl];
        t[v].mx = arr[tl];
    }
    else{
        
        int mid = (tl+tr)/2;
        build(2*v, tl, mid);
        build((v*2)+1, mid+1, tr);
        t[v].mx = max(t[v*2].mx, t[(v*2)+1].mx);
        t[v].mn = min(t[v*2].mn, t[(v*2)+1].mn);
    }
}

void upd(int v, int tl, int tr, int pos, int val){
    
    if(tl==tr){
        t[v].mx = val;
        t[v].mn = val;
    }
    else{
        int mid = (tl+tr)/2;
        if(pos<= mid){
            upd(2*v, tl, mid, pos, val);
        }
        else{
            upd(2*v+1, mid+1, tr, pos, val);
        }
        t[v].mx = max(t[2*v].mx, t[2*v+1].mx);
        t[v].mn = min(t[2*v].mn, t[2*v+1].mn);
    }
}


ll getmax(int v, int tl, int tr, int l, int r){
    
    if(tl>r || l>tr) return -1e9;
    if(tl>=l && r>=tr) return t[v].mx;
    
    int mid = (tl+tr)/2;
    ll ans1 = getmax(2*v, tl, mid, l, r);
    ll ans2 = getmax(2*v+1, mid+1, tr, l, r);
    return max(ans1, ans2);
    
}

ll getmin(int v, int tl, int tr, int l, int r){
    
    if(tl>r || l>tr) return 1e9;
    if(tl>=l && r>=tr) return t[v].mn;
    
    int mid = (tl+tr)>>1;
    ll ans1 = getmin(v*2, tl, mid, l, r);
    ll ans2 = getmin(v*2+1, mid+1, tr, l, r);
    return min(ans1, ans2);
    
}


int main(){
    
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
    
  scanf("%d", &q);
    
    for(int i=0; i<100000; i++){
        ll k = (((i+1) % 12345) * ((i+1) % 12345)) % 12345;
        ll k1 = (((((i+1) % 23456) * ((i+1) % 23456)) % 23456) * ((i+1) % 23456)) % 23456;
        arr[i] = k+k1;
    }
    
    build(1, 0, 99999);

    for(int i=0; i<q; i++){
        scanf("%d%d", &a, &b);
        
        if(a>0){
            a--; b--;
            ll mx = getmax(1, 0, 99999, a ,b);
            ll mn = getmin(1, 0, 99999, a ,b);
            
            cout<<mx-mn<<endl;
            
        }
        else{
            a*=(-1);
            a--;
            upd(1,0, 99999, a, b);
        }
    }
    return 0;
}
