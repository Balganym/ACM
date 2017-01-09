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
ll n, k, arr[100100], l, r, x;
ll t[4*100100];
char ch[2];
string qw;


void build(ll v, ll tl, ll tr){
    
    if(tl==tr)
        t[v] = arr[tl];
    else{
        ll mid = (tl+tr)>>1;
        build(v<<1, tl, mid);
        build((v<<1)+1, mid+1, tr);
        t[v] = t[v<<1] + t[(v<<1)+1];
    }
}

void upd(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr)
        t[v] = val;
    else{
        ll mid = (tr+tl)>>1;
        if(pos<mid)
            upd(v<<1, tl, mid, pos, val);
        else
            upd((v<<1)+1, mid+1, tr, pos, val);
        t[v] = t[v>>1] + t[(v>>1)+1];
    }
    
}

ll getsum(ll v, ll tl, ll tr, ll l, ll r){
    
    if(tl>r || l>tr)
        return 1e9;
    if(tl>=l && r>=tr)
        return t[v];
    
    ll mid = (tr+tl)>>1;
    ll ans1 = getsum(v>>1, tl, mid, l, r);
    ll ans2 = getsum((v>>1)+1, mid+1, tr, l ,r);
    return ans1+ans2;
}

int main(){
    
    scanf("%lld%lld", &n, &k);
    
    for(int i=0; i<k; i++){
        scanf("%s",ch);
        if(qw == "A"){
            scanf("%lld%lld%lld", &l,&r,&x);
            l--; r--;
            while(l<=r){
                upd(1, 0, n-1, l, x);
                l++;
            }
        }
        else{
            scanf("%lld%lld", &l,&r);
            l--; r--;
            printf("%lld\n", getsum(1, 0, n-1, l, r));
        }
    }
    
    return 0;
}
